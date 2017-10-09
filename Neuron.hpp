#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

class Neuron
{
	public :
	
	Neuron(std::vector<int> targ);
	Neuron();
	
	double getPot() const;
	bool isRefractory() const;
	void recieve(int time);
	
	std::vector<int> update(int t, double extCur);
	
	private :
	
	double pot; //membrane potential
	std::vector<int> spikes; //vector to access the number of spikes easily, a double to record the time of the spike
	double refractTimer;
	std::vector<int> recievedJs;
	std::vector<int> targets;
};

#endif
