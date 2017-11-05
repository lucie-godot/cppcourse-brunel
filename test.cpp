#include <iostream>
#include <gtest/gtest.h>
#include <math.h>
#include "neuron.h"
#include "network.h"

using namespace std;


TEST (NeuronTest, OneExcitatoryMbPotential) {
	
	Neuron n1 (0.1, 1, 0);
	Neuron n2 (0.1, 1, 0);
	Neuron n3 (0.1, 1.01, 0);
	Neuron n4 (0.1, 0, 0);
	
	
	n1.update(0, 0);
	n2.n_update(5, 0, 0);
	n3.n_update(1000, 0, 0);
	n4.n_update(1000, 0, 0);
	
	EXPECT_LT (((20*(1-exp(-(0.1/20)))) - n1.get_mb_potential()), pow(10, -6));  ///Test for one path of time.
	EXPECT_LT ((0.3960265338 - n2.get_mb_potential()), pow(10, -6));  ///Test for 5 paths of time.
	EXPECT_LT ((0-n3.get_mb_potential()), pow(10,-8));
	
	n2.n_update(9995, 0, 0);
	
	EXPECT_LT((20-n2.get_mb_potential()), pow(10, -8));
}


TEST (NeuronTest, OneInhibitory) {
	
	Neuron n1 (-0.5, 1.0, 0);
	Neuron n2 (-0.5, 1.0, 0);
	Neuron n3 (-0.5, 0.0, 0);
	Neuron n4 (-0.5, 1.01, 0);
	
	n1.update(0, 0);
	n2.n_update(5, 0, 0);
	n3.n_update(1000, 0, 0);
	n4.n_update(1000, 0, 0);
	
	EXPECT_LT (((20*(1-exp(-(0.1/20)))) - n1.get_mb_potential()), pow(10, -6));  //Test for one path of time
	EXPECT_LT ((0.3960265338 - n2.get_mb_potential()), pow(10, -6));
	EXPECT_LT ((0-n3.get_mb_potential()), pow(10, -8));
	
	n2.n_update(9995, 0, 0);
	
	EXPECT_LT ((20-n2.get_mb_potential()), pow (10, -8));
}

TEST (NeuronTest, NumberSpikesExcitatory) {
	
	Neuron n1 (0.1, 1.01, 0);
	Neuron n2 (0.1, 0, 0);
	Neuron n3 (0.1, 1.0, 0);
	
	n1.n_update(10000, 0, 0);
	n2.n_update(10000, 0, 0);
	n3.n_update(1000, 0, 0);
	
	
	EXPECT_GT(n1.get_nb_spikes(), 1);
	EXPECT_EQ(n2.get_nb_spikes(), 0);
	EXPECT_EQ(n3.get_nb_spikes(), 0);
}


TEST (NeuronTest, NumberSpikesInhibitory) {
	Neuron n1 (-0.5, 1.01, 0);
	Neuron n2 (-0.5, 0, 0);
	Neuron n3 (-0.5, 1.0, 0);
	
	n1.n_update(10000, 0, 0);
	n2.n_update(10000, 0, 0);
	n3.n_update(1000, 0, 0);
	
	EXPECT_GT(n1.get_nb_spikes(), 1);
	EXPECT_EQ(n2.get_nb_spikes(), 0);
	EXPECT_EQ(n3.get_nb_spikes(), 0);
}

TEST (NeuronTest, ValueSpikes) {
	Neuron n1 (0.1, 1.01, 0);
	Neuron n2 (-0.5, 1.01, 0);
	
	n1.n_update(2000, 0, 0);
	n2.n_update(10000, 0, 0);
	
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
