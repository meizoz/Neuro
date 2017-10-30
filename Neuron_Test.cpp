
#include "Neuron.hpp"
#include "gtest/gtest.h"
#include "Constants.hpp"
#include <cmath>


TEST(NeuronTest,MembraneTest)
{
	const double A = exp(-(DT/TAU));
	const double B = R*(1-A);
	Neuron n;
	n.update(1, 1);
	EXPECT_NEAR(B,n.getPot(),0.001);
	
}
