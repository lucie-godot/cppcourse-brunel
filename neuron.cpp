#include <iostream>
#include <math.h>
#include <random>
#include <iomanip>

#include "neuron.h"
using namespace std;




Neuron::Neuron():v_(V_REF_), local_time_(0), nb_spikes_(0), ring_buffer(D+1, 0.0) {
	
};
	
	
	
double Neuron::get_mb_potential () const {
	return v_;
};




int Neuron::get_nb_spikes () const {
	return nb_spikes_;
};



int Neuron::get_local_time () const {
	return local_time_;
};




double Neuron::get_J () const {
	return J;
};





void Neuron::add_term_buffer (int t_, double J_neuron_pre_) {  //t_ est le local_time_ du 2eme neuron
	ring_buffer [(t_ + D) % (D + 1)] += J_neuron_pre_ ;    //On prend en compte le délais en mettant J directement dans la bonne case
};



void Neuron::delete_term_buffer (int t_){
	ring_buffer [(t_ + D) % (D + 1)] = 0;
};



bool Neuron::update (double I_ext_, int nu_ext, int nb_connections_ex) {
	
	//dans le premier if on traite le cas d'un neurone réfractaire, et dans le else les autres cas.
	
	if (v_ >= V_THR_) {  //The neuron is refractory
		
		nb_spikes_ += 1;
		
		for (int x_ = local_time_; x_ <= local_time_ + REF_TIME_; x_ += H_){
			v_ = V_RESET_;
		};
		return true;
	}
	
	else {
		//Implementation of the Poisson distribution
		random_device rd;
		mt19937 gen(rd());
		poisson_distribution<> d(nu_ext * nb_connections_ex * H_ * J);
		
		v_ = C1*v_ + I_ext_*C2 + ring_buffer [local_time_%(D+1)] + d(gen);
		local_time_ += H_;
		
		return false;
		
	};
};



void Neuron::n_update (int nb_update_, double I_ext_, int nu_ext, int nb_connections_ex) {
	for (int i (0); i<=nb_update_; i+=1) {
		update (I_ext_, nu_ext, nb_connections_ex);
	};
};

void Neuron::spike (double t_) const {
	
	cout << "There is a spike at time : " << t_*0.1 << endl;  //Pour tenir compte du décalage avec h=0.1	
};
