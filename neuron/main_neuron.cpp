#include <iostream>
#include <vector>
using namespace std;

#include "neuron.h"


int main () {
	
	Neuron neuron;
	neuron.mb_potential(-70);
	
	double t = 0;
	double t_stop = 40;
	double h = 20;
	double I_ext;
	double refractory_period = 2 ;
	
	vector<double> potential (1);
	vector<bool> spike (1);
	
	//Specification of I_ext and the time interval
	
	double value;
	cout<<"Can you specify the value of the external current ?"<<endl;
	cin>>value;
	I_ext = value;
	
	int a;
	int b;
	cout<<"In which time interval does the external current is define ?"<<endl;
	cin >> a;
	cin >> b;
	
	
	
	while (t <= t_stop) {
		
		if ( t<=a and t<=b){  //interval in which I_ext is not equal to 0, if the neuron is not refractory
//			if (
//			potential.push_back(neuron.update(refractory_period, h, I_ext, t));  //Update of the membrane potential if I_ext is not equal to 0.
		};
		
		
//		spike.push_back(neuron.time_spike(t));  //Je regarde au cours du temps quand est-ce que j'ai un spike
		
		
		t += h;
		
	}
	cout << potential[0] << endl;
	return 0;
}
