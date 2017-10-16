#include <iostream>
using namespace std;

#include "neuron.h"
#ifndef NEURON_H
#define NEURON_H


class Network {
	
	// Le n1 transmet au n2
	
	
	private:
	
	Neuron n1;
	Neuron n2;
	
	
	public:
	
	bool connection (double I_ext_);
	
	
};



#endif
