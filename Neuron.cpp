#include "Neuron.hpp"
#include "Constants.hpp"
#include <cmath>

const double A = exp(-(DT/TAU)); // V(t+h)= A*V(t) + extCur*B
const double B = (R/TAU)*(1-A);

Neuron::Neuron() : pot(0), refractTimer(-1)
{};

double Neuron::getPot() const
{
	return pot;
}

bool Neuron::isRefractory()const
{
	if(refractTimer >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Neuron::update(double t, double extCur)
{
	if(!isRefractory())
	{
		pot = A*pot + extCur*B; //update of potential (pot)
	}
	
	if(pot > NEUR_THRESHOLD) //condition for spike
	{
		spikes.push_back(t);
		pot = 0;
		refractTimer = 2;
	}
	 
	if(isRefractory())
	{
		 refractTimer -= DT;
	}
}
