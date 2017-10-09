#include <iostream>
using namespace std;
#include <math.h>
#include "neuron.h"


#ifndef NEURON_H
#define NEURON_H




double Neuron::mb_potential () {
	return v;
};




void Neuron::mb_potential (double potential){
	v = potential;
};





void Neuron::update (double a, double b, double h, double I_ext) {
	
	
	if (v >= v_thr) {   //The neuron is refractory
		
		cout << "Spike at time: " << t << endl;
		
		for (int x=t; x<= t + refractory_period; x+=h) {	
			v = v_reset;
		}
		t+=refractory_period;
	}
		
	if (t>=a and t<=b) {  //I_ext does exist 
			
		v = exp(-(h/tau))*v + I_ext*R*(1-exp(-(h/tau)));
		t+=h;
	}
	else {
			
		v = exp(-h/tau)*v;
		t+=h;
	};
	
};




double Neuron::update_period (double n, double a, double b, double I_ext){
	
	for (int i = 0; i < n; i += 1){
		update (a, b, h, I_ext);
		};
	
	return v;
	
};





void Neuron::time_spike (vector<double> &spikes){
	if (v >= v_thr) {
		spikes.push_back(t);
	}
};




int Neuron::nb_spikes (vector<double> spike) {   //Return the number of spikes during a period of time given
	
	int result = 0;
	
	for (size_t i = 0; i <= spike.size(); i+=1){
		if (spike[i] != 0){
			result += 1;
		};
	};
	
	return result;
};


#endif
