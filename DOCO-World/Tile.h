/************************
*File: Tile.h
*Author: Collin L. Flack
*Assignment 2: DOCO Simulation
*
*This program is entirely my own work.
Design Summary: The Tile mainly consists of types and a food amount in the case of it becoming a food tile (isFood is true). The types
				are notably utilized by Simulation's display and most other of the project's methods.

Methods:
	Tile() -- Creates a Tile with all of its boolean values such as isABoundary set to false.
	getType() -- Returns true if the integer coinciding with the Tile's type is true of that Tile.
	setType() -- Sets a Tile's type based upon an integer passed.
	getX() -- Returns a Tile's x-coordinate (width)
	getY() -- Returns a Tile's y-coordinate (height)
	clearTypes() -- Sets all of the boolean values such as isABoundary referring to a Tile's type.
	getFoodAmount() -- Returns the number of food pellets on a Tile.
	clearFood() -- Reduces the number of food pellets on a Tile to 0.
	setFood() -- Increments the number of food pellets on a Tile by 1 if there are less than 3 pellets.

*************************/

#ifndef TILE_H
#define TILE_H

#include <iostream>

using namespace std;

class Tile
{
private:
	bool isABoundary; 
	bool isADOCO; 
	bool isEmpty; 
	bool isFood; 
	bool isABoundaryNum; 
	int foodAmount; 
	int xPos, yPos; 

public:
	Tile(); 
	Tile(int x, int y); 
	~Tile(); 
	bool getType(int typeCount); 
	void setType(int typeCount); 
	int getX(); 
	int getY(); 
	void clearTypes(); 
	int getFoodAmount(); 
	void clearFood(); 
	void setFood();
};

#endif