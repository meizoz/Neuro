#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <array>
#include "Constants.hpp"

/*!
 * \file Neuron.hpp
 * \brief definiton of Neuron class
 */


/*! \class Neuron
 * 	
 * A class to modelize neurons
 */

class Neuron
{
	public :
	
	Neuron(std::vector<int> targ);
	Neuron();
	
	double getPot() const; //!< returns membrane potential
	bool isInhibitory() const; //!< returns true if neuron is inhibitory
	void setTargets(std::vector<int> tar); //!< sets the tagets of the neuron
	void setNeuronType(bool inhib); //!< sets the neuron type : true for inhibitory neuron, false for exitatory
	bool isRefractory() const; //!< returns true if the neuron is in refractory state
	void recieve(int time, int delay, bool inhib); //!< plan the time at which a spike is recieved @param time time at which the spike is recieved @param delay delay before the spike is recieved @param inhib true if the spike is inhibitory
	void addTarget(int tar); //!< add a target to the list of tagets @param tar index of the target in the brain
	void addPotential(double extPot); //!< add external potential to the membrane potential @param extPot a value to add to the membrane potential
	
	std::vector<int> update(int t, double extCur);
	
	private :
	
	bool isInhib;  //!< a bool, true if the neuron is inhibitory 
	double pot;  //!< membrane potential
	//std::vector<int> spikes;  //!< a vector to access the number of spikes easily, an int to record the time step of the spike
	double refractTimer; //!< refractory state duration
	std::array<double,D+1> recievedBuffer; //!< recieved spikes buffer
	std::vector<int> targets; //!< int corresponding to target neurons
};

#endif
