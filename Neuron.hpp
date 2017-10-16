#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <array>
#include "Constants.hpp"

class Neuron
{
	public :
	
	Neuron(std::vector<int> targ);
	Neuron();
	
	double getPot() const;
	bool isRefractory() const;
	void recieve(int time, int delay);
	
	std::vector<int> update(int t, double extCur);
	
	private :
	
	double pot; //membrane potential
	std::vector<int> spikes; //vector to access the number of spikes easily, an int to record the time step of the spike
	double refractTimer; //refractory state duration
	std::array<double,D+1> recievedBuffer;
	std::vector<int> targets;
};

#endif
