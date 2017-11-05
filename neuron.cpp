#include <random>
#include <iomanip>

#include "neuron.h"
using namespace std;




Neuron::Neuron(double i_, double i_ext_, int nb_): I_EXT_(i_ext_), id_neuron(nb_), spike (false), J(i_), v_(V_REF_), local_time_(0), clock_ref_(0), nb_spikes_(0), time_spike_(0), ring_buffer(D+1, 0.0){
};




void Neuron::set_target (int nb_connection_ex, int nb_connection_in){
	
	srand(time(NULL));
	
	for (int i = 0; i < nb_connection_ex; i += 1) {
		target.push_back(rand()%10000);
	}
	for (int i = 0; i < nb_connection_in; i += 1) {
		target.push_back(rand()%(12500-10000)+10000);
	}
};




int Neuron::get_id () {
	return id_neuron;
};

	
double Neuron::get_mb_potential () const {
	return v_;
};




double Neuron::get_time_spike () {
	return time_spike_*0.1;
};




int Neuron::get_nb_spikes () const {
	return nb_spikes_;
};



int Neuron::get_local_time () const {
	return local_time_;
};




double Neuron::get_spike_time (double t_)const {
	return t_*0.1;
};






double Neuron::get_J () const {
	return J;
};




bool Neuron::get_spike_status () const {
	return spike;
};


void Neuron::add_term_buffer (int t_) {  //t_ est le local_time_ du 2eme neuron
	ring_buffer [(t_ + D) % (D + 1)] += J ;    //On prend en compte le délais en mettant J directement dans la bonne case
};



int Neuron::get_target(int i_) {
	return target[i_];
}



int Neuron::get_size_target () {
	return target.size();
};





void Neuron::delete_term_buffer (int t_){
	ring_buffer [(t_ + D) % (D + 1)] = 0;
};





void Neuron::update (int poisson_, int t_) {
	
	if (clock_ref_ > 0) {
		v_ = V_RESET_;
		spike = false;
	}
	else {
		if (v_ >= V_THR_) {  //The neuron is refractory
			nb_spikes_ += 1;
			clock_ref_ = REF_TIME_;
			v_ = V_RESET_;
			spike = true;
			time_spike_ = local_time_;
		}
		else {
			
			v_ = C1*v_ + I_EXT_*C2 + ring_buffer [local_time_%(D+1)] + poisson_*0.1;
			spike = false;
		}
	};
	clock_ref_ -= 1;
	local_time_ += H_;
	//cout << ring_buffer [local_time_%(D+1)] << "  " << id_neuron << endl;
};
	
	
		
		



void Neuron::n_update (int nb_update_, int poisson_, int t_) {
	for (int i (0); i<=nb_update_; i+=1) {
		update (poisson_, t_);
	};
};

//void Neuron::spike (double t_) const {
	
	//cout << "There is a spike at time : " << t_*0.1 << endl;  //Pour tenir compte du décalage avec h=0.1	
//};
