#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "neuron.h"


int main () {
	
	//Variables declaration
	
	Neuron neuron;
	neuron.mb_potential(-70);
	
	double t = 0;
	double t_stop = 10000;
	double h = 1;
	

	//Creation of the file which contains the membrane potential
	
	ofstream f_mb_potential ("mb_potential");
	
	//Specification of I_ext and the time interval
	
	double I_ext;
	double value;
	
	cout<<"Can you specify the value of the external current ?"<<endl;
	cin>>value;
	I_ext = value;
	
	int a;
	int b;
	cout<<"In which time interval does the external current is define ?"<<endl;
	cin >> a;
	cin >> b;
	
	
	
	
	do {
		
		f_mb_potential << neuron.mb_potential() << endl;
		neuron.update (t, a, b, h, I_ext);	
		
	}
	while (t <= t_stop);
	
	return 0;
}
