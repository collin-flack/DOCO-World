/************************
*File: StartSimulation.h
*Author: Collin L. Flack
*Assignment 2: DOCO Simulation
*
*This program is entirely my own work.
Design Summary: This class starts the simulation by creating a Simulation object.

Methods:
	StartSimulation() -- Method to seed random generator and output a header message to terminal. A Simulation object is instantiated
	The argument passed to the new Simulation object is the number of frames the user would like to generate of the simulation.

*************************/

#ifndef STARTSIMULATION_H
#define STARTSIMULATION_H

#include <iostream>
#include "Simulation.h"

using namespace std;

class StartSimulation 
{
	public:

		StartSimulation(); 
		~StartSimulation(); 

};

#endif