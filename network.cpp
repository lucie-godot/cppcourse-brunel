#include <random>
#include "network.h"


Network::Network (): f_spikes_time ("spikes_time"){
};




void Network::set_neuron () {
	for (unsigned int i = 0; i < nb_neu_ex; i += 1) {  //Inisialisation of the vector of neuron
		neurons.push_back(Neuron(0.1, 0, i, 1));
	}
	for (unsigned int i = 0; i < nb_neu_in; i += 1) {  //Inisialisation of the vector of neuron
		neurons.push_back(Neuron(-0.5, 0, nb_neu_ex + i, 1));
	}	
};





void Network::inform_target (int t_, int i_) {
	for (int j = 0; j < neurons[i_].get_size_target(); j += 1) {
		int value;
		value = neurons[i_].get_target(j);
		neurons[value].add_term_buffer(t_);
		//cout << t_ << endl;
	}
};



void Network::write_spikes (int t_, int i_) {
	f_spikes_time << t_ << "\t" <<  i_ << "\n";
};




void Network::set_all_target () {
	for (int i = 0; i < nb_neuron; i += 1) {
		neurons[i].set_target(nb_connection_ex, nb_connection_in);
	}
};


void Network::general_update (int t_, int t_stop_) {  ///Method used to update the network of neuron
	while (t_ < t_stop_) {
		for (int i = 0; i < nb_neuron; i += 1) {
			neurons[i].update(neurons[i].get_poisson(), t_);
			if (neurons[i].get_spike_status()) {
				f_spikes_time << neurons[i].get_time_spike() << "\t" << neurons[i].get_id() << "\n";
				inform_target (t_, i);
			};
			neurons[i].delete_term_buffer(t_);
			//cout << neurons[i].get_mb_potential() << "  " << neurons[i].get_id()<< endl;
		}
		t_ += h_;
	};
	f_spikes_time.close();
};
