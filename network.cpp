#include <random>
#include "network.h"


Network::Network (): Neuron(), connection (12500, vector<int> (12500)), f_spikes_time ("spikes_time") {
};



void Network::set_neuron () {
	for (int i = 0; i < nb_neuron; i += 1) {  //Inisialisation of the vector of neuron
		neuron.push_back(Neuron());
	}
};



void Network::set_connection () {
	
	//Implementation of a uniform law, to choose randomly the connections.

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> uni_ex (0, 9999);
	uniform_int_distribution<int> uni_in (10000, 12499);

	
	for (int i = 0; i < nb_neuron; i += 1) {
		for (int j = 0; j < nb_connection_ex; j+= 1) {
			connection[i][uni_ex(gen)] += 1;
		}
		for (int j = 0; j < nb_connection_in; j += 1) {
			connection[i][uni_in(gen)] += -5;
		}
	}
};




void Network::write_spikes (int t_, int i) {
	f_spikes_time << t_ << "  " << i << endl;
};





//PROBLEMES !!!!!!!!!

void Network::general_update (int t_, int t_stop_) {  ///Method used to update the network of neuron
	while (t_ <= t_stop_) {
		for (int i = 0; i < nb_neuron; i += 1) {
			if (neuron[i].update()){
				write_spikes(t_, i);
				for (int j = 0; j < nb_connection_ex; j += 1) {
					if (connection[i][j] > 0) {
						neuron[j].add_term_buffer_ex(t_);
					};
				}
				for (int j = 0; j < nb_connection_in; j += 1) {
					if (connection[i][j + nb_connection_ex] > 0) {
						neuron[j + nb_connection_ex].add_term_buffer_in(t_);
					};
				}
			}
		}
		for (int i = 0; i < nb_neuron; i += 1) {
			neuron[i].delete_term_buffer(t_);
			
		}
		
		t_ += h_;
	};
};
