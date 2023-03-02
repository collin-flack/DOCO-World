/************************
*File: DOCO.h
*Author: Collin L. Flack
*Assignment 2: DOCO Simulation
*
*This program is entirely my own work.
Design Summary: DOCOs are implemented by mainly the behaviors move, eat, smell, changeDirection, and die. Most of these behaviors are relative
				to an array of Tiles.

Methods:
	DOCO() -- Creates a tile with an x Position and y Position respective of the width and height that the DOCO is specified to have.
			  Defines a random direction in the form of a random integer.
	getEnergy() -- Returns the integer value for the DOCO's energy.
	checkForDeath() -- Returns true if the DOCO's energy is less than or equal to 0.
	move() -- Based off of the DOCO's direction, move looks ahead to see the destination Tile's type. If food, the DOCO moves to that Tile and
			  eats the food. If it's not food, but the Tile is empty, the DOCO moves to the tile. However, if a case occurs where the DOCO
			  attempts to go to a boundary Tile or a Tile holding another DOCO, the DOCO changes direction.
	changeDirection () -- Change direction takes the previous direction and based upon that decides a new random direction. changeDirection then
						  calls move again so that the DOCO will continue trying to move until a possible move is available.
	smell() -- DOCO checks all neighboring Tiles. If any of them contain food, the DOCO sets its direction towards the food.
	eat() -- The DOCO eats an amount of food pellets and restores 50 energy for each amount.
	addEnergy() -- Energy incremented by passed value.
	die() -- DOCO's "home" Tile is reset. Coinciding this call, the DOCO is removed from memory in the vector of DOCOs in updateSim of Simulation.
*************************/

#ifndef DOCO_H
#define DOCO_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tile.h"

using namespace std;

class DOCO
{

private:
	int xPos, yPos; 
	int direction; 
	int energy; 
	static const int WIDTHCO = 100;
	static const int HEIGHTCO = 100;
	int height;
	int width; 

public:
	DOCO(); 
	DOCO(int x, int y, int h, int w); 
	~DOCO(); 
	int getEnergy(); 
	bool checkForDeath(); 
	void move(Tile world[WIDTHCO][HEIGHTCO]);
	void smell(Tile world[WIDTHCO][HEIGHTCO]);
	void eat(int numPellets); 
	void addEnergy(int amount); 
	void changeDirection(int prevDir, Tile world[WIDTHCO][HEIGHTCO]);
	Tile findTile(Tile world[WIDTHCO][HEIGHTCO], int x, int y); 
	void die(Tile world[WIDTHCO][HEIGHTCO]);

};


#endif