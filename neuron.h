#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


#ifndef NEURON_H
#define NEURON_H


class Neuron {
	
	private:
		
	const int TAU_ = 20;  ///Tau.
	const double C_ = 1;   ///Capacity of the neuron.
	const double R_ = TAU_/C_;  ///Resistance of the neuron.
	
	
	const double V_THR_ = 20.0;  ///Value of the threshold.	
	const double V_RESET_ = 0.0;  ///Reset potential of the membrane (during the refractory period).
	const double V_REF_ = 0.0;   ///Initial potential of the membrane.
	
	
	const double REF_TIME_ = 20 ;   ///Refractory time.
	const double H_ = 1;   ///Time path.
	
	
	double I_EXT_;  ///External current (we can choose to input, useful for the tests).   Interval (a,b) ???????????
	const double C1_ = exp(-(H_*0.1)/TAU_); ///Fisrt constant of the update formula.
	const double C2_ = R_*(1-exp(-(H_*0.1)/TAU_)); ///Second constant of the update formula.
	const double J_ = 0.1;  ///Weight of the connection, constant.
	
	
	const int D_ = 15;   ///Delay of the connection
	
	
	int id_neuron_;   ///Number of the neuron in the vector of neurons.
	int poisson_;   ///Integer which is equal at 1 if we want to apply the poisson distribution, equals to 0 if not.
	double j_;   ///Weight of the connection, depending on the status of the neuron (excitatory or inhibitory).
	bool spike_;   ///Indicate if the neuronhas spiked or not at a time t.
	double v_;    ///Membrane potential
	int local_time_;   ///Personal clock of the neuron
	int clock_ref_;   ///Clock used for the refractory period of the neuron
	int nb_spikes_;   ///Number of spikes the neuron did.
	int time_spike_;   /// Time when a spike happened.
	vector<double> ring_buffer_;   ///Ring buffer
	vector<int> target_;   ///Vector which contains all the target of a neuron.
	

	public:
	
	
	///Constructor
	///@param i_ext : external input
	///@param nb : id of the neuron
	///@param poisson : equal to 1 or 0, to determine the poissons_ attribute
	///@param j : equal to 1 if the neuron is excitatory, or to g if the neuron is inhibitory
	Neuron (double i_ext, int nb, int poisson, double j);
	
	
	///@brief Setter for the vector of targets.
	///@param nb_connection_ex : number of connection with excitatory neurons 
	///@param nb_connection_in : number of connection with the inhbitory neurons
	void set_target (unsigned int nb_connection_ex, unsigned int nb_connection_in);
	
	
	///@brief Getter for the position of the neuron in the vector representing the network.
	int get_id () const;
	
	
	///@brief Getter for the poisson attribute.
	int get_poisson () const;
	
	
	///@brief Getter for the weight of the connection, depending on the status of the neuron.
	double get_j () const;
	
	
	///@brief Getter for the membrane potential of the neuron.
	double get_mb_potential () const;
	
	
	///@brief Getter for the time at which a spike occcured.
	double get_time_spike () const;
	
	
	///@brief Getter for the total number of spikes the neuron have done after the updating period.  
	int get_nb_spikes () const;
	
	
	///@brief Method which gives the personnal time of the neuron.
	int get_local_time ()const;
	
	
	///@brief Getter for the value of J, the weight of the connection.
	double get_J ()const;
	
	
	///@brief Getter for the status of the neuron (if it has spiked or not).
	bool get_spike_status () const;
	
	
	///@brief Getter for the content of the case i of the target.
	///@param i : index of the vector
	int get_target (int i);
	
	
	///@brief Getter for the size of the target.
	int get_size_target();
	
	
	///@brief Method which modifies the ring buffer at the right place, depending of the time.
	///@param t : time
	void add_term_buffer (int t);
	
	
	///@brief Method which deletes a term of the ring buffer, at the corresponding place.
	///@param t : time
	void delete_term_buffer (int t);
	
	
	
	///@brief Method which updates the membrane potential of the neuron.
	///@param poisson : integer equals to 1 or 0 to decide if the poisson dsitribution exists
	///@param eta : parameter of the poisson distribution, depending on the experiment we are performing
	void update (int poissson, int eta);
	
	
	///@brief Method which updates the membrane potential n times (it is used only in the tests).
	///@param nb_update : number of updates we want to perform
	///@param poisson : integer equals to 1 or 0 to decide if the poisson dsitribution exists
	///@param eta : parameter of the poisson distribution, depending on the experiment we are performing
	void n_update (int nb_update, int poisson, int eta);
	
};


#endif
