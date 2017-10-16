#include <iostream>
using namespace std;

#include "network.h"
#ifndef NETWORK_H
#define NETWORK_H


bool Network::connection (double I_ext_) {
	
	if (n1.update(I_ext_)) {   //Attention, ce test modifie v de n1
		n2.update(I_ext_);
		return true;
	}
	else {
		n2.update(0);
		return false;
	};
	
	
};



#endif 
