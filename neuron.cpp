#include <random>
#include <iomanip>

#include "neuron.h"
using namespace std;




Neuron::Neuron(double i_, double i_ext_):I_EXT_(i_ext_), J(i_), v_(V_REF_), local_time_(0), clock_ref_(0), nb_spikes_(0), ring_buffer(D+1, 0.0) {
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




double Neuron::get_spike_time (double t_)const {
	return t_*0.1;
};






double Neuron::get_J () const {
	return J;
};





void Neuron::add_term_buffer (int t_) {  //t_ est le local_time_ du 2eme neuron
	ring_buffer [(t_ + D) % (D + 1)] += J ;    //On prend en compte le délais en mettant J directement dans la bonne case
};




//void Neuron::add_term_buffer_in (int t_) {
//	ring_buffer [(t_ + D) % (D + 1)] -= 5;
//};



void Neuron::delete_term_buffer (int t_){
	ring_buffer [(t_ + D) % (D + 1)] = 0;
};





bool Neuron::update (int poisson_) {
	
	if (clock_ref_ > 0) {
		v_ = V_RESET_;
		local_time_ += H_;
		clock_ref_ -= 1;
		return false;
	}
	else {
		if (v_ >= V_THR_) {  //The neuron is refractory
			nb_spikes_ += 1;
			clock_ref_ = REF_TIME_;
			v_ = V_RESET_;
			local_time_ += H_;
			return true;
		}
		else {
			//Implementation of the Poisson distribution
			random_device rd;
			mt19937 gen(rd());
			poisson_distribution<> d(2);  //nu_ext * nb_connections_ex * H_ * J
			
			v_ = C1*v_ + I_EXT_*C2 + ring_buffer [local_time_%(D+1)] + d(gen)*0.1*poisson_;
			
			local_time_ += H_;
			clock_ref_ -= 1;
			return false;
		}
	};
};
	
	
		
		



void Neuron::n_update (int nb_update_, int poisson_) {
	for (int i (0); i<=nb_update_; i+=1) {
		update (poisson_);
	};
};

//void Neuron::spike (double t_) const {
	
	//cout << "There is a spike at time : " << t_*0.1 << endl;  //Pour tenir compte du décalage avec h=0.1	
//};
