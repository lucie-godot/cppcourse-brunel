#include <iostream>
#include <vector>
using namespace std;



class Neuron {
	
	private:
	
	//constants definition
	
	const int tau_ = 20;
	const double C_ = 1;
	const int R_ = tau_/C_;
	
	const double v_thr_ = 20.0;
	const double v_reset_ = 0.0;
	const double v_ref_ = -70.0;
	
	const double refractory_period_ = 2 ;
	const double h_ = 1;
	
	
	//Variables definition
	
	double v_ = v_ref_;
	double local_time_ = 0;
	int nb_spikes_ = 0;
	
	
	public:
	
	
	double get_mb_potential () const;
	int get_nb_spikes () const;
	int get_local_time ()const;
	
	//Methode
	
	void update (double I_ext_);
	bool spike () const;
	
};

