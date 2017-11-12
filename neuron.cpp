#include <random>
#include <iomanip>

#include "neuron.h"
using namespace std;




Neuron::Neuron(double i_ext, int nb, int poisson, double j): I_EXT_(i_ext), id_neuron_(nb),  poisson_(poisson), j_(j*J_), spike_ (false), v_(V_REF_), local_time_(0), clock_ref_(0), nb_spikes_(0), time_spike_(0), ring_buffer_(D_+1, 0.0){
};




void Neuron::set_target (unsigned int nb_connection_ex, unsigned int nb_connection_in){
	
	srand(time(NULL));
	
	for (unsigned int i = 0; i < nb_connection_ex; i += 1) {
		target_.push_back(rand()%10000);
	}
	for (unsigned int i = 0; i < nb_connection_in; i += 1) {
		target_.push_back(rand()%(12500-10000)+10000);
	}
};




int Neuron::get_id () const {
	return id_neuron_;
};



int Neuron::get_poisson () const{
	return poisson_;
};



double Neuron::get_j () const{
	return (j_);
};


	
double Neuron::get_mb_potential () const {
	return v_;
};




double Neuron::get_time_spike () const{
	return time_spike_*0.1;
};




int Neuron::get_nb_spikes () const {
	return nb_spikes_;
};



int Neuron::get_local_time () const {
	return local_time_;
};



double Neuron::get_J () const {
	return J_;
};



bool Neuron::get_spike_status () const {
	return spike_;
};



int Neuron::get_target(int i) {
	return target_[i];
}



int Neuron::get_size_target () {
	return target_.size();
};



void Neuron::add_term_buffer (int t) {  //t_ est le local_time_ du 2eme neuron
	ring_buffer_ [(t + D_) % (D_ + 1)] += j_ ;    //On prend en compte le délais en mettant j directement dans la bonne case
};




void Neuron::delete_term_buffer (int t){
	ring_buffer_ [(t + D_) % (D_ + 1)] = 0;
};



void Neuron::update (int poisson, int eta) {
	
	if (clock_ref_ > 0) {
		v_ = V_RESET_;
		spike_ = false;
		clock_ref_ -= 1;
		local_time_ += H_;
	}
	else {
		if (v_ >= V_THR_) {  //The neuron is refractory
			nb_spikes_ += 1;
			clock_ref_ = REF_TIME_;
			v_ = V_RESET_;
			spike_ = true;
			time_spike_ = local_time_;
			clock_ref_ -= 1;
			local_time_ += H_;
		}
		else {
			//Implementation of the Poisson distribution
			static random_device rd;
			static mt19937 gen(rd());
			static poisson_distribution <> d(eta);
			v_ = C1_*v_ + I_EXT_*C2_ + ring_buffer_[local_time_%(D_+1)] + d(gen)*poisson*J_;
			spike_ = false;
			clock_ref_ -= 1;
			local_time_ += H_;
		}
	};
};
	
	
		


void Neuron::n_update (int nb_update, int poisson, int eta) {
	for (int i (0); i<=nb_update; i+=1) {
		update (poisson, eta);
	};
};
