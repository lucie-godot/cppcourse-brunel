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




double Neuron::update (double refractory_period, double h, double I_ext, double t){
	
	v = exp(-h/tau)*v + I_ext*R*(1-exp(-h/tau));
		
	return v;
};




double Neuron::update_period (double refractory_period, double h, double I_ext, double t, double n){
	
	for (int i = 0; i < n; i += 1){
		update (refractory_period, h, I_ext, t);
		};
	
	return v;
	
};





double Neuron::time_spike (double t){
	if (v >= v_thr) {
				return t;
	}
	return 0;
};





int Neuron::nb_spikes (vector<double> spike) {   //Return the number of spikes during a period of time given
	
	int result = 0;
	
	for (int i = 0; i <= spike.size(); i+=1){
		if (spike[i] != 0){
			result += 1;
		};
	};
	
	return result;
};




#endif
