#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

#include "neuron.h"
#include "network.h"
#include "experiment.h"


int main () {
	
	int t = 0;
	int t_stop = 10000;
	
	Experiment exp;
	
	char answer;
	do { 
		cout << "Do you want to simulate a network of neurons ? Press y for yes and n for no." << endl;
		cin >> answer;
		if (answer == 'y') {
			cout << "Which graph do you want to plot : a, b, c or d ?" << endl;
			char plot;
			cin >> plot;
	
			if (plot == 'a') {
				exp.plota(t, t_stop);
			}
	
			if (plot == 'b') {
				exp.plotb(t, t_stop);
			}
	
			if (plot == 'c') {
				exp.plotc(t, t_stop);
			}
	
			if (plot == 'd') {
				exp.plotd(t, t_stop);
			}
		}
		
		if (answer == 'n') {
			cout << "End of the programm, thank you ! " << endl;
		};	
	}
	while (answer != 'n');

	return 0;
}
