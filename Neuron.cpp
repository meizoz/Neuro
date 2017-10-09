#include "Neuron.hpp"
#include "Constants.hpp"
#include <cmath>

const double A = exp(-(DT/TAU)); // V(t+h)= A*V(t) + extCur*B
const double B = (R/TAU)*(1-A);

Neuron::Neuron(std::vector<int> targs) : pot(0), refractTimer(-1)
{
		targets = targs;
}

Neuron::Neuron() : pot(0), refractTimer(-1)
{};

double Neuron::getPot() const
{
	return pot;
}

void Neuron::recieve(int t)
{
	recievedJs.push_back(t);
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

std::vector<int> Neuron::update(int t, double extCur)
{
	std::vector<int> targs;
	
	if(!isRefractory())
	{	
		pot = A*pot + extCur*B; //update of potential (pot)
		
		if(!recievedJs.empty())
		{
			for(int& i : recievedJs)
			{
				if(i==t)
				{
					pot += J;
				}
			}
		}
	}
	
	if(pot > NEUR_THRESHOLD) //condition for spike
	{
		spikes.push_back(t);
		pot = 0;
		refractTimer = 2;
		
		if(!targets.empty())
		{
			targs = targets;
		}
	}
	 
	if(isRefractory())
	{
		 refractTimer -= DT;
	}
	
	return targs;
}
