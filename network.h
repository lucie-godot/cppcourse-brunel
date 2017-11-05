#include <fstream>
#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

using namespace std;

class Network : public Neuron {
	
	private :
	
	const int nb_neuron = 12500;  ///Total number of neurons of the network.
	const int h_ = 1;  ///Path of time, for the general time.
	const int nb_neu_ex = 10000;   ///Number of neuron which are excitatory.
	const int nb_neu_in = 2500;   ///Number of neuron which are inhibitory.
	const int nb_connection_ex = 1000;  ///Number of connections that should be done with excitatory neurons.
	const int nb_connection_in = 250;  ///Number of connections that should be done with inhibitory neurons.
	
	
	vector<Neuron> neurons;   ///Vector which contains /a nb_neuron neurons.
	
	ofstream f_spikes_time;
	
	
	public :
	
	
	///Constructor.
	Network();
	
	
	///Method which creates the elements of the vector of neurons.
	///
	void set_neuron ();
	
	
	///Method which implements a poisson distribution.
	///
	int poisson ();
	
	
	///Method whih takes for parameter /param t_ for the time.
	///It modifies the buffer of the neurons of the target.
	void inform_target (int t_);
	
	
	
	///Method which sets the target of each neuron.
	///
	void set_all_target ();
	
	///Method which takes the parameters /param t_ for the time and /param i_ for the number of the neuron studied.
	///It fills the file with the time a apike occures and the number of the neuron which has produced it.
	void write_spikes (int t_, int i_);
	
	
	///Method which takes the parameters /param t_ for the time and /param t_stop_ for the time wher the simulation stops.
	///It updates each neurons of the network during the duration of the simulation.
	void general_update (int t_, int t_stop_);
	
	
};


#endif
