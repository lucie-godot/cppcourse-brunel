#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "neuron.h"
#include "network.h"


class Experiment {
	
	private :
	
	int g_;   ///Relative inhibitory weight.
	int eta_;
	
	
	public:
	
	
	///Constructor
	Experiment ();
	
	
	///@brief Getter for the value of g.
	int get_g () const;
	
	
	///@brief Getter for the value of eta.
	int get_eta() const;
	
	
	///@brief Setter for the cortex.
	///@param g : relative inhibitory weight
	///@param eta : parameter of poisson distribution
	///@param t : time 
	///@param t_stop : end of the simulation 
	///@param name : name of the file in which the values of spikes and id of neurons are stored
	void set_cortex (int g, int eta, int t, int t_stop, string name);
	
	///@brief Method which create the file needed to plot the first graph of Brunel's simulation.
	///@param t : time (start of the simulation)
	///@param t_stop : time at which the simulations stops
	void plota (int t, int t_stop);
	
	
	///@brief Method which create the file needed to plot the second graph of Brunel's simulation.
	///@param t : time (start of the simulation)
	///@param t_stop : time at which the simulations stops
	void plotb (int t, int t_stop);
	
	
	///@brief Method which create the file needed to plot the third graph of Brunel's simulation.
	///@param t : time (start of the simulation)
	///@param t_stop : time at which the simulations stops
	void plotc (int t, int t_stop);
	
	
	///@brief Method which create the file needed to plot the fourth graph of Brunel's simulation.
	///@param t : time (start of the simulation)
	///@param t_stop : time at which the simulations stops
	void plotd (int t, int t_stop);
	
};

#endif
