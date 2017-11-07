#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


#ifndef NEURON_H
#define NEURON_H


class Neuron {
	
	private:
	
	///Constant attributes
		
	const int TAU_ = 20;  ///Tau.
	const double C_ = 1;   ///Capacity of the neuron.
	const double R_ = TAU_/C_;  ///Resistance of the neuron.
	
	
	const double V_THR_ = 20.0;  ///Value of the threshold.	
	const double V_RESET_ = 0.0;  ///Reset potential of the membrane (during the refractory period).
	const double V_REF_ = 0.0;   ///Initial potential of the membrane.
	
	
	const double REF_TIME_ = 20 ;   ///Refractory time.
	const double H_ = 1;   ///Time path.
	
	
	double I_EXT_;  ///External current (we can choose to input, useful for the tests).   Interval (a,b) ???????????
	const double C1 = exp(-(H_*0.1)/TAU_); ///Fisrt constant of the update formula.
	const double C2 = R_*(1-exp(-(H_*0.1)/TAU_)); ///Second constant of the update formula.
	
	
	const int D = 15;   ///Delay of the connection
	
	
	int id_neuron;
	int poisson_;
	bool spike;   ///Indicate if the neuronhas spiked or not at a time t.
	double J;  ///Weight of the connection
	double v_;    ///Membrne potential
	int local_time_;   ///Personal clock of the neuron
	int clock_ref_;   ///Clock used for the refractory period of the neuron
	int nb_spikes_;   ///Number of spikes the neuron did.
	int time_spike_;   /// Time when a spike happened.
	vector<double> ring_buffer;   ///Ring buffer
	vector<int> target;   ///Vector which contains all the target of a neuron.
	

	public:
	
	
	///Constructor
	
	Neuron (double i_, double i_ext_, int nb_, int poisson);
	
	
	///Method which takes for parameter /param nb_connection_ex for the number of connection with excitatory neurons and /param nb_connection_in for th number of connection with th inhbitory ones.
	///It creates the target.
	void set_target (int nb_connection_ex, int nb_connection_in);
	
	
	///Method which gives the position of the neuron in the vector representing the network.
	///
	int get_id ();
	
	
	
	int get_poisson ();
	
	
	///Method which gives the membrane potential of the neuron.
	///
	double get_mb_potential () const;
	
	
	///Method which gives the time at which a spike occcured.
	///
	double get_time_spike ();
	
	
	///Method which gives the total number of spikes the neuron have done after the updating period.  
	///
	int get_nb_spikes () const;
	
	
	///Method which gives the personnal time of the neuron.
	///
	int get_local_time ()const;
	
	
	///Method which takes the parameter /param t_ for the time.
	/// It returns the time of a secific spike.
	
	double get_spike_time (double t_)const;
	
	
	///Method which gives the value of J, the weight of the connection.
	///
	double get_J ()const;
	
	
	
	///Method which gives the status of the neuron (if it has spiked or not).
	///
	bool get_spike_status () const;
	
	
	///Method which takes the parameter /param t_ for the time.
	///It modifies the ring buffer at the right place, depending of the time.
	
	void add_term_buffer (int t_);
	
	
	///Method which takes for parameter /param i_ for the index of the vector.
	///It gives the case i of the target.
	int get_target (int i_);
	
	
	///Method which gives the size of the target.
	///
	int get_size_target();
	
	
	
	///Method which takes the parameter /param t_ for the time
	///It deletes a term of the ring buffer, at the corresponding place.
	void delete_term_buffer (int t_);
	
	
	
	///Method which takes the parameter /param i_ , which is equal to one if the neuron is excitatory, or to -5 if it is inhibitory.
	///It updates the membrane potential of the neuron. It returns true if the neuron had spiked and false if not.
	void update (int poissson_, int t_);
	
	
	///Method which takes the parameter /param nb_update_ for the number of updates we want and /param i_ for the update method.
	///It updates the membrane potential n times. It is used only in the tests.
	void n_update (int nb_update_, int poisson_, int t_);
	
};


#endif
