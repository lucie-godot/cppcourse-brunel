#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "neuron.h"


int main () {
	
	//Variables declaration
	
	Neuron neuron;
	
	double t_ = 0;
	double t_stop_ = 10000;
	double h_ = 1;
	

	//Creation of the file which contains the membrane potential
	
	ofstream f_mb_potential ("mb_potential");
	f_mb_potential << neuron.get_mb_potential() << endl;
	
	//Specification of I_ext and the time interval
	
	double I_ext_;
	double value_;
	
	cout<<"Can you specify the value of the external current ?"<<endl;
	cin>>value_;
	I_ext_ = value_;
	
	int a_;
	int b_;
	do {
		cout<<"In which time interval does the external current is define ?"<<endl;
		cin >> a_;
		cin >> b_; }
	while (a_>=b_);
	
	
	//Important loop for one neuron 
	
	while (t_ <= t_stop_) {
		
		//Update of the membrane potential
		
		if (t_ >= a_ and t_ <= b_) {
			if (neuron.update (I_ext_)){
				neuron.spike (t_);
				};
			f_mb_potential << neuron.get_mb_potential() << endl;
		}
		else {
			if (neuron.update (0)){
				neuron.spike (t_);
				};
			f_mb_potential << neuron.get_mb_potential() << endl;
		};
		
		
		do {
		t_ += h_; }
		while (t_ < neuron.get_local_time ());
	};
	
	
	return 0;
}
