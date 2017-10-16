#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



class Neuron {
	
	private:
	
	
	// Definition of the attribute of the class
	
		//Attribute used for the update of the neuron
		
	const int tau_ = 20;
	const double C_ = 1;
	const int R_ = tau_/C_;
	const double c1 = exp(-(h_/tau_)); // value of the fisrt constant in the update formula
	const double c2 = R_*(1-exp(-(h_/tau_))); //value of the second constant in the update formula
	
	const double v_thr_ = 20.0;  //Value of the threshold
	const double v_reset_ = 0.0;
	const double v_ref_ = -70.0;
	
	const double refractory_period_ = 2 ;
	const double h_ = 1;   //definition of the time path
	

	double v_ = v_ref_;    //definition of the membrne potential
	int local_time_ = 0;   // definition of the personal clock of the neuron
	int nb_spikes_ = 0;
	
	
		//Attribute used for the connections
	
	const double J = 0.1;  //definition of the weight of the connection
	const int D = 15;   //definition of the delay of the connexion
	double ring_buffer [D+1] = 0.0;   //Pouruoi utiliser un vector et pas un array ??? Pourquoi D + 1 ne fonctionne pas ?
	
	public:
	
	
	double get_mb_potential () const;
	int get_nb_spikes () const;
	int get_local_time ()const;
	void spike (double t_) const;
	
	//Methode
	
	double update (double I_ext_);
	double connection ();
	
	
};

