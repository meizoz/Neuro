#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron
{
	public :
	
	Neuron();
	
	double getPot() const;
	
	void update(double t, double extCur);
	
	private :
	
	double pot; //membrane potential
	std::vector<double> spikes; //vector to access the number of spikes easily, a double to record the time of the spike
};

#endif
