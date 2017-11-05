#include <random>
#include "network.h"


Network::Network (): Neuron(0, 0, 0), f_spikes_time ("spikes_time") {
};




void Network::set_neuron () {
	for (int i = 0; i < nb_neu_ex; i += 1) {  //Inisialisation of the vector of neuron
		neurons.push_back(Neuron(0.1, 0, i));
	}
	for (int i = 0; i < nb_neu_in; i += 1) {  //Inisialisation of the vector of neuron
		neurons.push_back(Neuron(-0.5, 0, nb_neu_ex + i));
	}
	
};




int Network::poisson () {
	//Implementation of the Poisson distribution
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution <> d(2);
	return d(gen);
};




void Network::inform_target (int t_) {
	for (int i = 0; i < neurons[i].get_size_target(); i += 1) {
		int value;
		value = neurons[i].get_target(i);
		neurons[value].add_term_buffer(t_);
		//cout << value << endl;
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
			neurons[i].update(poisson(), t_);
			if (neurons[i].get_spike_status()) {
				f_spikes_time << neurons[i].get_time_spike() << "\t" << neurons[i].get_id() << "\n";
				inform_target (t_);
			};
			neurons[i].delete_term_buffer(t_);
			//cout << neurons[i].get_mb_potential() << "  " << neurons[i].get_id()<< endl;
		}
		t_ += h_;
	};
	f_spikes_time.close();
};
