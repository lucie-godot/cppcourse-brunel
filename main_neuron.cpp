#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

#include "neuron.h"


int main () {
	
	
	//Creation of the network of neurons
	
	
	
	vector<Neuron> neuron (12500);  //This is the vector which contains all the neurons
	//The first 10000 neurons are the excitatory one.
	int connections [12500][12500];  //This is the matrix of the connections between the neurons
	// the neurons are represented on the columns, the lines represent the connections with one neuron.
	
	for (int i = 0; i < 12500; i += 1) {
		srand(time(NULL));  //Initilization of rand, to obtain random numbers
		for(int con_ex = 0; con_ex < 1000; con_ex += 1) {  //con_ext is the number of connection with an excitatory neuron for each neuron
			connections [rand()%10000][i] += 1; //We are choosing the connections with excitatory neurons, for each neuron.
		};
		for(int con_in = 0; con_in < 250; con_in += 1) {  //con_in is the number of connection with an inhibitory neuron for each neuron
			connections [rand()%10000 + 250][i] += 1;  //Connections with inhibitory neurons
		};
		
	};
	
	
	
	
	//Creation of the time variables
	
	double t_ = 0;
	double t_stop_ = 10000;
	double h_ = 1;
	
	
	//Creation of variables
	int nu_ext = 0;   //Modifier valeur !!!!!!!!!!!
	int nb_connections_ex = 1000;

	//Creation of the file which contains the time of the spikes
	
	ofstream f_spikes_time ("spikes_time");
	
	//Specification of I_ext and the time interval
	
	double I_ext_;
	double value_;
	
	cout<<"Can you specify the value of the external current ?"<<endl;
	cin>>value_;
	I_ext_ = value_;
	
	int a_;
	int b_;
	do {
		cout<<"In which time interval does the external current is define ?"<<endl;
		cin >> a_;
		cin >> b_; }
	while (a_>=b_);
	
	
	//Important loop 
	
	while (t_ <= t_stop_) {
		
		//Update of the membrane potential of n1
		
		
		for (int i = 0; i < 12500; i += 1) {  //Est-ce au'il ne vaudrait pas mieux utiliser la taille, le type size_t ????????
			if (t_ >= a_ and t_ <= b_) {
				if (neuron[i].update (I_ext_, nu_ext, nb_connections_ex)){  //If the neuron number i spikes
					neuron[i].spike(t_);
					f_spikes_time << neuron[i].get_spike_time(t_) << endl;
					for (int j = 0; j < 12500; j += 1) {  //For every connection, we have to add 1 to the ring buffer.
						if (connections[j][i] != 0){  //We are searching for the connections for a fixed column
							neuron[j].add_term_buffer(neuron[i].get_local_time(), neuron[i].get_J());
						};
					};
				};
			}
			
			else {
				if (neuron[i].update(0, nu_ext, nb_connections_ex)){
					neuron[i].spike(t_);
					f_spikes_time << neuron[i].get_spike_time(t_) << endl;
				};
			};
		};
		
		
		for (int i = 0; i < 12500; i += 1){
			do {
				t_ += h_;
				for (int j = 0; j < 12500; j += 1){
					neuron[j].delete_term_buffer(t_);
				}
			}
			while (t_ < neuron[i].get_local_time ());
		};

	
};
	return 0;
}
