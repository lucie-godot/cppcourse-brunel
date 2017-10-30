#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


#ifndef NEURON_H
#define NEURON_H


class Neuron {
	
	private:
	
	
	// Definition of the attribute of the class
	
		//Constants
		
	const int TAU_ = 20;
	const double C_ = 1;
	const int R_ = TAU_/C_;
	
	
	const double V_THR_ = 20.0;  //Value of the threshold
	const double V_RESET_ = 0.0;
	const double V_REF_ = 0;
	
	const double REF_TIME_ = 2 ;
	const double H_ = 1;   //definition of the time path
	
	const double I_EXT_ = 0;  //external current we can choose to input, useful for the tests.   Interval (a,b) ???????????
	const double C1 = exp(-((H_*0.1)/TAU_)); // value of the fisrt constant in the update formula, H_*0.1 to take the lnght of the interval.
	const double C2 = R_*(1-exp(-((H_*0.1)/TAU_))); //value of the second constant in the update formula
	
	const double J = 0.1;  //definition of the weight of the connection
	const int D = 15;   //definition of the delay of the connexion
	
	
	

	double v_;    //definition of the membrne potential
	int local_time_;   // definition of the personal clock of the neuron
	int nb_spikes_;
	vector<double> ring_buffer;



	public:
	
	// Constructor
	
	Neuron ();
	
	
	//Const methods
	
	double get_mb_potential () const;
	int get_nb_spikes () const;
	int get_local_time ()const;
	double get_spike_time (double t_)const;
	double get_J ()const;
	void add_term_buffer (int t_, double J_neuron_pre_);  // fonction permettant de modifier le buffer avec le courant des neurones pre-synaptiques
	void delete_term_buffer (int t_);
	void spike (double t_) const;
	
	//Methods
	
	bool update (int nu_ext, int nb_connections_ex);
	void n_update (int nb_update_, int nu_ext, int nb_connections_ex);
	
	
};


#endif
