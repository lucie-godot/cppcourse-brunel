#include <iostream>
#include <vector>
using namespace std;


class Neuron {
	
	private:
	
	//Définition des constantes nécessaires à la classe
	
	const int tau = 20;
	const int C = 1;
	const int R = tau/C;
	
	const double v_thr = 20.0;
	//const double v_reset = 0.0;
	//const double v_ref = -70.0;
	
	//Définition des variables nécessaires à la classe
	
	double v;
	
	
	public:
	
	//Accesseurs
	
	double mb_potential ();
	
	
	//
	
	void mb_potential (double potential);
	
	//Méthodes
	
	double update (double refractory_period, double h, double I_ext, double t);
	double update_period (double refractory_period, double h, double I_ext, double t, double n);
	
	double time_spike (double t);
	int nb_spikes (vector<double> spike);
	
};


