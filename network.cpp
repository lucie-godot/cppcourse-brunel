#include <random>
#include "network.h"


Network::Network (string name, int nb_neuron, int nb_con_ex, int nb_con_in, int nb_neu_ex, int nb_neu_in):nb_neuron_(nb_neuron), nb_neu_ex_(nb_neu_ex), nb_neu_in_(nb_neu_in), nb_connection_ex_(nb_con_ex), nb_connection_in_(nb_con_in), f_spikes_time (name){
};




void Network::set_neuron (int g) {
	for (unsigned int i = 0; i < nb_neu_ex_; i += 1) {  //Inisialisation of the vector of neuron
		neurons_.push_back(Neuron(0, i, 1,1));
	}
	for (unsigned int i = 0; i < nb_neu_in_; i += 1) {  //Inisialisation of the vector of neuron
		neurons_.push_back(Neuron(0, nb_neu_ex_ + i, 1, -g));
	}
		
};



void Network::set_all_target () {
	for (unsigned int i = 0; i < nb_neuron_; i += 1) {
		neurons_[i].set_target(nb_connection_ex_, nb_connection_in_);
	}
};


int Network::get_size_network () const{
	return neurons_.size();
};



Neuron Network::get_network_element (int i) const{
	return neurons_[i];
};




void Network::inform_one_target (int t, int i, int j){
	int value;
	value = neurons_[i].get_target(j);
	neurons_[value].add_term_buffer(t);
};




void Network::general_inform_target (int t, int i) {
	for (int j = 0; j < neurons_[i].get_size_target(); j += 1) {
		inform_one_target(t, i, j);
	}
};



void Network::write_spikes (int t, int i) {
	f_spikes_time << t << "\t" <<  i << "\n";
};




void Network::general_update (int t, int t_stop, int eta) {  ///Method used to update the network of neuron
	while (t < t_stop) {
		for (unsigned int i = 0; i < nb_neuron_; i += 1) {
			neurons_[i].update(neurons_[i].get_poisson(), eta);
			if (neurons_[i].get_spike_status()) {
				f_spikes_time << neurons_[i].get_time_spike() << "\t" << neurons_[i].get_id() << "\n";
				general_inform_target (t, i);
			};
			neurons_[i].delete_term_buffer(t);
		}
	t += h_;
	};
	f_spikes_time.close();
};
