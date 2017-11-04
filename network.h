#include <fstream>
#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

using namespace std;

class Network : public Neuron {
	
	private :
	
	const int nb_neuron = 12500;  ///Total number of neurons of the network.
	const int h_ = 1;  ///Path of time, for the general time.
	
	
	vector<Neuron> neuron;   ///Vector which contains /a nb_neuron neurons.
	vector<vector<int> > connection;   ///Matrix of the connections between the neurons. It contains the number of connections between the neurons.
	
	
	const int nb_connection_ex = 1000;  ///Number of connections that should be done with excitatory neurons.
	const int nb_connection_in = 250;  ///Number of connections that should be done with inhibitory neurons.
	
	
	ofstream f_spikes_time;
	
	
	public :
	
	
	///Constructor.
	Network();
	
	
	///Method which creates the elements of the vector of neurons.
	void set_neuron ();
	
	
	///Method which fills the matrix /a connection with the number of connections between each neurons.
	void set_connection ();
	
	
	///Method which takes the parameters /param t_ for the time and /param i_ for the number of the neuron studied.
	///It fills the file with the time a apike occures and the number of the neuron which has produced it.
	void write_spikes (int t_, int i_);
	
	
	///Method which takes the parameters /param t_ for the time and /param t_stop_ for the time wher the simulation stops.
	///It updates each neurons of the network during the duration of the simulation.
	void general_update (int t_, int t_stop_);
	
	
};


#endif
