#include <fstream>
#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

using namespace std;

class Network {
	
	private :
	
	const unsigned int nb_neuron_;  ///Total number of neurons of the network.
	const int h_ = 1;  ///Path of time, for the general time.
	const unsigned int nb_neu_ex_;   ///Number of neuron which are excitatory.
	const unsigned int nb_neu_in_;   ///Number of neuron which are inhibitory.
	const unsigned int nb_connection_ex_;  ///Number of connections that should be done with excitatory neurons.
	const unsigned int nb_connection_in_;  ///Number of connections that should be done with inhibitory neurons.
	
	
	vector<Neuron> neurons_;   ///Vector which contains /a nb_neuron neurons.
	
	ofstream f_spikes_time;   ///File which contains every spike's time, and the id of the neuron which has spiked.
	
	
	public :
	
	
	///Constructor.
	///@param name : name of the file.
	///@param nb_neuron : number of neurons for the simulation
	///@param nb_con_ex : number of connection each neuron has to do with excitatory neurons
	///@param nb_con_in : number of connection each neuron has to do with inhibitory neurons
	///@param nb_neu_ex : number of excitatory neurons
	///@param nb_neu_in : number of inhibitory neurons
	Network(string name, int nb_neuron, int nb_con_ex, int nb_con_in, int nb_neu_ex, int nb_neu_in);
	
	
	///@brief Setter for the elements of the vector of neurons.
	///@param g : relative inhibitory weight
	void set_neuron (int g);
	
	
	///@brief Setter for the target of each neuron.
	void set_all_target ();
	
	
	///@brief Getter for the size of the vector of neurons.
	int get_size_network () const;
	
	
	///@brief Getter for an element of the vector of neurons.
	Neuron get_network_element (int i) const;
	
	
	///@brief Method which fills the buffers of one target of one neuron.
	///@param t : time
	///@param i : id of the neuron studied
	///@param j : id of the neuron target
	void inform_one_target (int t, int i, int j);
	
	
	///@brief Method which fills the buffers of all the targets of one neuron.
	///@param t : time
	///@param i : id of the neuron studied
	void general_inform_target (int t, int i);
	
	
	
	///@brief Method which fills the file with the time a spike occured and the id of the neuron which has produced it.
	///@param t : time 
	///@param i : id of the neuron studied.
	void write_spikes (int t, int i);
	
	
	///@brief Method which updates each neurons of the network during the duration of the simulation.
	///@param t : time (start of the simulation
	///@param t_stop : time when the simulation stops
	///@param eta : parameter of the poisson distribution
	void general_update (int t, int t_stop, int eta);
	
	
};


#endif
