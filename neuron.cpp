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





void Neuron::update (double &t, double a, double b, double h, double I_ext) {
	
	
	if (v >= v_thr) {   //The neuron is refractory
		
		double refractory_time = t+refractory_period;
		cout<< refractory_time << endl;
		if (t <= refractory_time) {	
			v = v_reset;
			t+=h;
		}
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




double Neuron::update_period (double t, double n, double a, double b, double I_ext){
	
	for (int i = 0; i < n; i += 1){
		update (t, a, b, h, I_ext);
		};
	
	return v;
	
};





void Neuron::time_spike (vector<double> &spikes, double t){
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
