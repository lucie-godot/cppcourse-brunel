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



double Neuron::update (double I_ext_) {
	
	//dans le premier if on traite le cas d'un neurone réfractaire, et dans le else les autres cas.
	
	if (v_ >= v_thr_) {  //The neuron is refractory
		
		nb_spikes_ += 1;
		
		for (int x_ = local_time_; x_ <= local_time_ + refractory_period_; x_ += h_){
			v_ = v_reset_;
		};
		return true;
		
		ring_buffer [local_time_%(D+1)] += J
		cout << ring_buffer [local_time_%(D+1)] << endl;
	}
	
	else {
		v_ = c1*v_ + I_ext_*c2 + ring_buffer [local_time_%(D+1)];
		local_time_ += h_;
		
		return false;
		
	};
	
};



void Neuron::spike (double t_) const {
	
	cout << "There is a spike at time : " << t_*0.1 << endl;  //Pour tenir compte du décalage avec h=0.1	
};





double Neuron::connection () {
	
	
	
};














#endif
