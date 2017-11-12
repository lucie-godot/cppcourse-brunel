#include <iostream>
#include <gtest/gtest.h>
#include <math.h>
#include "neuron.h"
#include "network.h"
#include "experiment.h"

using namespace std;


TEST (NeuronTest, OneExcitatoryMbPotential) {
	
	Neuron n1 (1.01, 0, 0, 1);
	Neuron n2 (1, 0, 0, 1);
	Neuron n3 (1.01, 0, 0, 1);
	Neuron n4 (0, 0, 0, 1);
	
	
	n1.update(0,2);
	n2.n_update(5, 0,2);
	n3.n_update(1000, 0,2);
	n4.n_update(1000, 0,2);
	
	EXPECT_LT (((20*(1-exp(-(0.1/20)))) - n1.get_mb_potential()), pow(10, -6));  ///Test for one path of time.
	EXPECT_LT ((0.3960265338 - n2.get_mb_potential()), pow(10, -6));  ///Test for 5 paths of time.
	EXPECT_LT ((0-n3.get_mb_potential()), pow(10,-8));
	
	n2.n_update(9995, 0,2);
	
	EXPECT_LT((20-n2.get_mb_potential()), pow(10, -8));
}


TEST (NeuronTest, OneInhibitory) {
	
	Neuron n1 (1.0, 0, 0, -5);
	Neuron n2 (1.0, 0, 0, -5);
	Neuron n3 (0.0, 0, 0, -5);
	Neuron n4 (1.01, 0, 0, -5);
	
	n1.update(0,2);
	n2.n_update(5, 0,2);
	n3.n_update(1000, 0,2);
	n4.n_update(1000, 0,2);
	
	EXPECT_LT (((20*(1-exp(-(0.1/20)))) - n1.get_mb_potential()), pow(10, -6));  //Test for one path of time
	EXPECT_LT ((0.3960265338 - n2.get_mb_potential()), pow(10, -6));
	EXPECT_LT ((0-n3.get_mb_potential()), pow(10, -8));
	
	n2.n_update(9995, 0,2);
	
	EXPECT_LT ((20-n2.get_mb_potential()), pow (10, -8));
}

TEST (NeuronTest, NumberSpikesExcitatory) {
	
	Neuron n1 (1.01, 0, 0, 1);
	Neuron n2 (0, 0, 0, 1);
	Neuron n3 (1.0, 0, 0, 1);
	
	n1.n_update(10000, 0,2);
	n2.n_update(10000, 0,2);
	n3.n_update(1000, 0,2);
	
	
	EXPECT_GT(n1.get_nb_spikes(), 1);
	EXPECT_EQ(n2.get_nb_spikes(), 0);
	EXPECT_EQ(n3.get_nb_spikes(), 0);
}


TEST (NeuronTest, NumberSpikesInhibitory) {
	Neuron n1 (1.01, 0, 0, -5);
	Neuron n2 (0, 0, 0, -5);
	Neuron n3 (1.0, 0, 0, -5);
	
	n1.n_update(10000, 0,2);
	n2.n_update(10000, 0,2);
	n3.n_update(1000, 0,2);
	
	EXPECT_GT(n1.get_nb_spikes(), 1);
	EXPECT_EQ(n2.get_nb_spikes(), 0);
	EXPECT_EQ(n3.get_nb_spikes(), 0);
}

TEST (NeuronTest, RefractoryNeuron) {
	Neuron n1 (1.01, 0, 0, 1);
	Neuron n2 (1.01, 0, 0, -5);
	
	n1.n_update(924, 0,2);
	n2.n_update(924, 0,2);
	
	EXPECT_EQ(n1.get_mb_potential(), 0);
	EXPECT_EQ(n2.get_mb_potential(), 0);

	
	n1.n_update(18,0,2);
	n2.n_update(18,0,2);
	
	EXPECT_EQ(n1.get_mb_potential(), 0);
	EXPECT_EQ(n2.get_mb_potential(), 0);
	
	n1.update(0, 2);
	n2.update(0,2);
	
	EXPECT_GT(n1.get_mb_potential(), 0);
	EXPECT_GT(n2.get_mb_potential(), 0);
}

TEST (NetworkTest, TwoNeurons) {
	Network net1("n1", 2, 1, 0, 2, 0);  //Connection excitatory, excitatory neurons
	Network net2("n2", 2, 0, 1, 0, 2);  //Connection inhybitory, inhibitory neurons
	
	net1.set_neuron(5);
	net1.set_all_target();
	
	net2.set_neuron(5);
	net2.set_all_target();
	
	EXPECT_EQ(net1.get_size_network(), 2);
	EXPECT_EQ(net2.get_size_network(), 2);
	
	net1.general_update(0, 10, 2);
	net2.general_update(0, 10, 2);
	
	EXPECT_GT(net1.get_network_element(0).get_mb_potential(), 0);
	EXPECT_GT(net2.get_network_element(0).get_mb_potential(), 0);
	
}

TEST (NetworkTest, AllNeurons) {
	Network cortex ("net1", 12500, 1000, 250, 10000, 2500);
	
	cortex.set_neuron(5);
	cortex.set_all_target();
	
	EXPECT_EQ(cortex.get_size_network(), 12500);
	EXPECT_EQ(cortex.get_network_element(0).get_j(), 0.1);
	EXPECT_EQ(cortex.get_network_element(12499).get_j(), -0.5);
	
	cortex.general_update(0,100,2);
	
	EXPECT_GT(cortex.get_network_element(0).get_mb_potential(), 0);
};


TEST(ExperimentTest, ExpAWellDefine) {
	
	Experiment exp;
	exp.plota(0,10);
	
	EXPECT_EQ(exp.get_g(), 3);
	EXPECT_EQ(exp.get_eta(), 2);
};


TEST(ExperimentTest, ExpBWellDefine) {
	
	Experiment exp;
	exp.plotb(0,10);
	
	EXPECT_EQ(exp.get_g(), 6);
	EXPECT_EQ(exp.get_eta(), 4);
};


TEST(ExperimentTest, ExpCWellDefine) {
	
	Experiment exp;
	exp.plotc(0,10);
	
	EXPECT_EQ(exp.get_g(), 5);
	EXPECT_EQ(exp.get_eta(), 2);
};



TEST(ExperimentTest, ExpDWellDefine) {
	
	Experiment exp;
	exp.plotd(0,10);
	
	EXPECT_EQ(exp.get_g(), 4);
	EXPECT_EQ(exp.get_eta(), 1);
};

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
