#include "experiment.h"


Experiment::Experiment () {
};



int Experiment::get_g () const{
	return g_;
};



int Experiment::get_eta () const{
	return eta_;
};



void Experiment::set_cortex (int g, int eta, int t, int t_stop, string name ){
	Network cortex (name, nb_neu_, nb_con_ex_, nb_con_in_, nb_n_ex_, nb_n_in_);
	cortex.set_neuron (g);
	cortex.set_all_target();
	cortex.general_update(t, t_stop, eta);
};



void Experiment::plota (int t, int t_stop) {
	g_ = 3; 
	eta_ = 2;
	set_cortex(g_, eta_, t, t_stop, "spike_plota");
};


void Experiment::plotb (int t, int t_stop) {
	g_ = 6;
	eta_ = 4;
	set_cortex(g_, eta_, t, t_stop, "spike_plotb");
};


void Experiment::plotc (int t, int t_stop) {
	g_ = 5;
	eta_ = 2;
	set_cortex(g_, eta_, t, t_stop, "spike_plotc");
};



void Experiment::plotd (int t, int t_stop) {
	g_ = 4;
	eta_ = 1;
	set_cortex(g_, eta_, t, t_stop, "spike_plotd");
};
