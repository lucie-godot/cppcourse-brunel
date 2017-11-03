#include <iostream>
#include "gtest/gtest.h"
#include <math.h>
#include "neuron.h"
#include "network.h"
#include "experiment.h"

using namespace std;


TEST (NeuronTest, PositiveInput) {
	
	Neuron n;
	
	EXPECT_GT (20*(1-exp(-(0.1/20)) - n.update()), pow(10, -6));  //Test for one path of time
	//Faire la même chose pour un nombre défini de pas de temps, vérifier les tenps de spikes.

}


TEST (NeuronTest, NegativeInput) {
	
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
