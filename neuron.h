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
	const int R_ = TAU_/C_;  ///Resistance of the neuron.
	
	
	const double V_THR_ = 20.0;  ///Value of the threshold.
	const double V_RESET_ = 0.0;  ///Reset potential of the membrane (during the refractory period).
	const double V_REF_ = 0.0;   ///Initial potential of the membrane.
	
	const double REF_TIME_ = 20 ;   ///Refractory time.
	const double H_ = 1;   ///Time path.
	
	const double I_EXT_ = 0;  ///External current (we can choose to input, useful for the tests).   Interval (a,b) ???????????
	const double C1 = exp(-((H_*0.1)/TAU_)); ///Fisrt constant of the update formula.
	const double C2 = R_*(1-exp(-((H_*0.1)/TAU_))); ///Second constant of the update formula.
	
	const int D = 15;   ///Delay of the connection
	const double J = 0.1;  ///Weight of the connection
	
	
	

	double v_;    ///Membrne potential
	int local_time_;   ///Personal clock of the neuron
	int nb_spikes_;   ///Number of spikes the neuron did.
	vector<double> ring_buffer;   ///Ring buffer



	public:
	
	Neuron ();   ///Constructor
	
	
	///Const methods
	
	double get_mb_potential () const;
	int get_nb_spikes () const;
	int get_local_time ()const;
	double get_spike_time (double t_)const;
	double get_J ()const;
	void add_term_buffer_ex (int t_);  // fonction permettant de modifier le buffer avec le courant des neurones pre-synaptiques
	void add_term_buffer_in (int t_);
	void delete_term_buffer (int t_);
	void spike (double t_) const;
	
	//Methods
	
	bool update ();
	void n_update (int nb_update_);
	
	
};


#endif
