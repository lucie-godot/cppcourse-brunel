#include <fstream>
#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

using namespace std;

class Network : public Neuron {
	
	private :
	
	const int nb_neuron = 12500;  //Total number of neurons
	const int h_ = 1; //Path ofgeneral time
	
	vector<Neuron> neuron;
	vector<vector<int> > connection;
	
	const int nb_connection_ex = 1000;  //Number of connections that should be done with excitatory neurons
	const int nb_connection_in = 250;  //Number of connections that should be done with inhibitory neurons
	
	ofstream f_spikes_time;
	
	public :
	
	
	Network();
	void set_neuron ();
	void set_connection ();
	void write_spikes (int t_, int i);
	void general_update (int t_, int t_stop_);
	
	
};


#endif
