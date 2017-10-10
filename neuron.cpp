#include <iostream>
using namespace std;
#include <math.h>
#include "neuron.h"


#ifndef NEURON_H
#define NEURON_H




double Neuron::get_mb_potential () const {
	return v_;
};




int Neuron::get_nb_spikes () const {
	return nb_spikes_;
};



int Neuron::get_local_time () const {
	return local_time_;
};



void Neuron::update (double I_ext_) {
	
	//dans le premier if on traite le cas d'un neurone réfractaire, et dans le else les autres cas.
	
	if (v_ >= v_thr_) {  //The neuron is refractory
		
		nb_spikes_ += 1;
		
		for (int x_ = local_time_; x_ <= local_time_ + refractory_period_; x_ += h_){
			v_ = v_reset_;
		};
	}
	else {
		v_ = exp(-(h_/tau_))*v_ + I_ext_*R_*(1-exp(-(h_/tau_)));
		local_time_ += h_;
		
	};
	
};



bool Neuron::spike () const {
	if (v_ >= v_thr_) {
		return true;
	};
	return false;
	
}

#endif
