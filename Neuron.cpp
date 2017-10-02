#include "Neuron.hpp"
#include "Constants.hpp"
#include <cmath>

const double A = exp(-(DT/TAU)); // V(t+h)= A*V(t) + extCur*B
const double B = (R/TAU)*(1-A);

Neuron::Neuron() : pot(0)
{};

double Neuron::getPot() const
{
	return pot;
}

void Neuron::update(double t, double extCur)
{
	pot = A*pot + extCur*B; //update of potential (pot)
	
	 if(pot > NEUR_THRESHOLD) //condition for spike
	 {
		 spikes.push_back(t);
		 pot = 0;
	 }
}
