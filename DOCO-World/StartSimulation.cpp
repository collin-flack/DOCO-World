/************************
*File: StartSimulation.cpp
*Author: Collin L. Flack
*Assignment 2: DOCO Simulation
*
*This program is entirely my own work.
Design Summary: This class starts the simulation by creating a Simulation object. 

Methods: 
	StartSimulation() -- Method to seed random generator and output a header message to terminal. A Simulation object is instantiated
	The argument passed to the new Simulation object is the number of frames the user would like to generate of the simulation. 

*************************/

#include "StartSimulation.h"

using namespace std; 

StartSimulation::StartSimulation()
{
	srand(time(NULL));
	cout << "DOCO Simulation (Programming Assignment 2)" << endl; 
	Simulation * play = new Simulation(1);


}

StartSimulation::~StartSimulation()
{
}

