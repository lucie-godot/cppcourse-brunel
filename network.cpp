#include <random>
#include "network.h"


Network::Network (): Neuron(0, 0), connection (12500, vector<int> (12500)), f_spikes_time ("spikes_time") {
};




void Network::set_neuron () {
	for (int i = 0; i < 10000; i += 1) {  //Inisialisation of the vector of neuron
		neuron.push_back(Neuron(0.1, 0));
	}
	for (int i = 0; i < 2500; i += 1) {  //Inisialisation of the vector of neuron
		neuron.push_back(Neuron(-0.5, 0));
	}
	
};



void Network::set_connection () {
	
	//Implementation of a uniform law, to choose randomly the connections.

	//random_device rd;
	//mt19937 gen(rd());
	//uniform_int_distribution<int> uni_ex (0, 9999);
	//uniform_int_distribution<int> uni_in (10000, 12499);
	srand(time(NULL));

	
	for (int i = 0; i < nb_neuron; i += 1) {
		for (int j = 0; j < nb_connection_ex; j+= 1) {
			connection[i][rand()%10000] += 1;  //uni_ex(gen)
		}
		for (int j = 0; j < nb_connection_in; j += 1) {
			connection[i][rand()%10000 +2500] += 1;  //uni_in(gen)
		}
	}
};




void Network::write_spikes (int t_, int i_) {
	f_spikes_time << t_ << "\t" <<  i_ << "\n";
};







void Network::general_update (int t_, int t_stop_) {  ///Method used to update the network of neuron
	while (t_ <= t_stop_) {
		for (int i = 0; i < 10000; i += 1) {
			//Ajouter un asssert pour être sur que tous les neurones soient au bon temps
			if (neuron[i].update(1)){
				write_spikes(t_, i);
				for (int j = 0; j < nb_connection_ex; j += 1) {
					if (connection[i][j] > 0) {
						neuron[j].add_term_buffer(t_);
					};
				}
				for (int j = 0; j < nb_connection_in; j += 1) {
					if (connection[i][j + nb_connection_ex] > 0) {
						neuron[j + nb_connection_ex].add_term_buffer(t_);
					};
				}
			}
		}
		for (int i = 0; i < 2500; i += 1) {
			//Ajouter un asssert pour être sur que tous les neurones soient au bon temps
			if (neuron[i + 10000].update(1)){
				write_spikes(t_, i + 10000);
				for (int j = 0; j < nb_connection_ex; j += 1) {
					if (connection[i + 10000][j] > 0) {
						neuron[j].add_term_buffer(t_);
					};
				}
				for (int j = 0; j < nb_connection_in; j += 1) {
					if (connection[i + 10000][j + nb_connection_ex] > 0) {
						neuron[j + nb_connection_ex].add_term_buffer(t_);
					};
				}
			}
		}
		for (int i = 0; i < nb_neuron; i += 1) {
			neuron[i].delete_term_buffer(t_);
			cout << neuron[i].get_mb_potential() << "  " << i << "  " << neuron[i].get_J()<< endl;
		}
		
		t_ += h_;
	};
	f_spikes_time.close();
};
