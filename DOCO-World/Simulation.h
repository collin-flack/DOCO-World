/************************
*File: Simulation.h
*Author: Collin L. Flack
*Assignment 2: DOCO Simulation
*
*This program is entirely my own work.
Design Summary: This class initializes an array of Tile(s) which are used to compute the interactions of the DOCOs. Furthermore, the
Simulation updates the DOCO simulation and displays the results of the update to terminal.

Methods:
	Simulation() -- This method sets the boolean simBegin as true and creates an array of Tiles- "the world."
	initSim() -- This method takes an argument for the world, the array of Tiles from the Simulation constructor, and fills the world
				 with Tiles up to the width and height read in from the data file. Then, based off positional values, different
				 Tiles have their respective types set.
	display() -- This method iterates through the world and displays characters based off of their type.
	findTile() -- Iterates through the world and finds the Tile in the array of Tiles with the passed width and height coordinate
				  and returns that Tile.
	updateSim() -- Creates a specified number of DOCOs at specified locations and a specified number of foodif the Simulation is beginning.
				   Otherwise, updateSim spawns a random number of food 1-10 and moves all of the DOCOs. Then, updateSim displays the results
				   and calls itself passing the altered world. This recursion continues for the amount of frames specified by Simulation.
	spawnFood() -- Creates a pellet of food on empty Tiles.
	incrementFrameNumber() -- Increases the frame the Simulation is on.
*************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "DataParser.h"
#include "Tile.h"
#include "DOCO.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Tile.h"
#include "windows.h"

using namespace std;

class Simulation
{

private:
	int numFood; 
	int numDOCOS; 
	int numObjects; 
	int xVals[1000], yVals[1000];
	vector<int> movementInts; 
	bool simBegin; 
	DOCO * DOCOS[100]; 
	static const int WIDTHC = 100;
	static const int HEIGHTC = 100;
	int width, height; 
	int frameNum, timesToRun; 

public:
	Simulation(int setter);
	~Simulation(); 
	void initSim(Tile world[WIDTHC][HEIGHTC]);
	void display(Tile world[WIDTHC][HEIGHTC]);
	Tile findTile(Tile world[WIDTHC][HEIGHTC], int x, int y);
	void updateSim(Tile world[WIDTHC][HEIGHTC]); 
	void spawnFood(Tile world[WIDTHC][HEIGHTC]);
	void incrementFrameNumber(); 

};

#endif