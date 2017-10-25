#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "neuron.h"


int main () {
	
	//Variables declaration
	
	Neuron n1;
	Neuron n2;
	
	double t_ = 0;
	double t_stop_ = 10000;
	double h_ = 1;
	

	//Creation of the file which contains the membrane potential
	
	ofstream f_mb_potential_1 ("mb_potential_1");
	ofstream f_mb_potential_2 ("mb_potential_2");
	f_mb_potential_1 << n1.get_mb_potential() << endl;
	f_mb_potential_2 << n2.get_mb_potential() << endl;
	
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
	
	
	//Important loop 
	
	while (t_ <= t_stop_) {
		
		//Update of the membrane potential of n1
		
		if (t_ >= a_ and t_ <= b_) {
			if (n1.update (I_ext_, nu_ext, nb_connections_ex)){
				n1.spike (t_);
				n2.add_term_buffer(n1.get_local_time(), n1.get_J());
				};
			f_mb_potential_1 << n1.get_mb_potential() << endl;
			
			n2.update (I_ext_, nu_ext, nb_connections_ex);
			f_mb_potential_2 << n2.get_mb_potential() << endl;
		}
		else {
			if (n1.update (0, nu_ext, nb_connections_ex)){
				n1.spike (t_);
				};
			f_mb_potential_1 << n1.get_mb_potential() << endl;
		};
		
		
		do {
		t_ += h_; }
		while (t_ < n1.get_local_time ());
		
		
		n2.delete_term_buffer(t_);
		
	}
	
	
	return 0;
}
