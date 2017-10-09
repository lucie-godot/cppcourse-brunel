#include <iostream>
#include <vector>
using namespace std;


class Neuron {
	
	private:
	
	//constants definition
	
	const int tau = 20;
	const double C = 1;
	const int R = tau/C;
	
	const double v_thr = 20.0;
	const double v_reset = 0.0;
	const double v_ref = -70.0;
	
	const double refractory_period = 2 ;
	const double h = 1;
	
	
	//Variables definition
	
	double v = v_ref;
	
	public:
	
	
	double mb_potential ();
	void mb_potential (double potential);
	
	//Methodes
	
	void update (double &t, double a, double b, double h, double I_ext);
	double update_period (double t, double n, double a, double b, double I_ext);
	
	void time_spike (vector<double> &spikes, double t);
	int nb_spikes (vector<double> spike);
	
	
};


