#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/*!
 * \file Constants.hpp
 * \brief definition of constants
 */

const double DT = 0.1; //!< time steps duration, in ms
const double TAU = 20; //!< in ms
const double R = 20; //!< membrane resistance
const double NEUR_THRESHOLD = 20; //!< threshold for spike in mV
const double J = 0.1; //!< current recieved by post synaptic neuron in mV in case of a exitatory spike
const double JI = -0.5; //!< current recieved by post synaptic neuron in mV in case of inhibitory spike
const int D = 15; //!< Delay between spike and recieved spike in time steps

#endif
