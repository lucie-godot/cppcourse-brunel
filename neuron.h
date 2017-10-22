#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


#ifndef NEURON_H
#define NEURON_H


class Neuron {
	
	private:
	
	
	// Definition of the attribute of the class
	
		//Constants  maj
		
	const int TAU_ = 20;
	const double C_ = 1;
	const int R_ = TAU_/C_;
	
	
	const double V_THR_ = 20.0;  //Value of the threshold
	const double V_RESET_ = 0.0;
	const double V_REF_ = -70.0;
	
	const double REF_TIME_ = 2 ;
	const double H_ = 1;   //definition of the time path
	
	const double C1 = exp(-(H_/TAU_)); // value of the fisrt constant in the update formula
	const double C2 = R_*(1-exp(-(H_/TAU_))); //value of the second constant in the update formula
	
	const double J = 0.1;  //definition of the weight of the connection
	const int D = 15;   //definition of the delay of the connexion
	
	
	

	double v_;    //definition of the membrne potential
	int local_time_;   // definition of the personal clock of the neuron
	int nb_spikes_;
	vector<double> ring_buffer;   //Pourquoi utiliser un vector et pas un array ??? Pourquoi D + 1 ne fonctionne pas ?
	
	public:
	
	// Constructor
	
	Neuron ();
	
	
	//Const methods
	
	double get_mb_potential () const;
	int get_nb_spikes () const;
	int get_local_time ()const;
	double get_J ()const;
	void add_term_buffer (int t_, double J_neuron_pre_)const;  // fonction permettant de modifier le buffer avec le courant des neurones pre-synaptiques
	void delete_term_buffer (int t_);
	void spike (double t_) const;
	
	//Methods
	
	double update (double I_ext_);
	
	
};


#endif
