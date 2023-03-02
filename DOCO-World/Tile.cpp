/************************
*File: Tile.cpp
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

#include "Tile.h"

Tile::Tile()
{

	isABoundary = false;
	isADOCO = false;
	isEmpty = false;
	isFood = false;
	isABoundaryNum = false;
	foodAmount = 0;
	xPos = 0;
	yPos = 0;

}

Tile::Tile(int x, int y)
{
	isABoundary = false; 
	isADOCO = false; 
	isEmpty = false; 
	isFood = false; 
	isABoundaryNum = false; 
	foodAmount = 0; 
	xPos = x; 
	yPos = y; 

}

Tile::~Tile()
{
}

bool Tile::getType(int typeCount)
{
	switch (typeCount) {

	case 1:
		if (isABoundary) {

			return true; 

		}

		else {

			return false; 
		}
		break; 

	case 2:
		if (isADOCO) {

			return true;

		}

		else {

			return false; 

		}
		break; 

	case 3:
		if (isEmpty) {

			return true; 

		}

		else {

			return false; 

		}
		break; 

	case 4:
		if (isFood) {

			return true; 

		}

		else {

			return false; 

		}
		break;

	case 5: 
		if (isABoundaryNum) {

			return true;

		}
		
		else {

			return false; 

		}
		break; 

	default:
		return false;
		break; 

	}
	
}

void Tile::setType(int typeCount)
{
	switch (typeCount) {

	case 1:
		isABoundary = true;
		break; 
	case 2:
		isADOCO = true; 
		break; 
	case 3: 
		isEmpty = true; 
		break; 
	case 4:
		isFood = true; 
		break; 
	case 5:
		isABoundaryNum = true; 
		break; 
	default:
		break; 


	}
}

int Tile::getX()
{
	return xPos;
}

int Tile::getY()
{
	return yPos;
}

void Tile::clearTypes()
{

	isABoundary = false;
	isADOCO = false;
	isEmpty = false;
	isFood = false;
	isABoundaryNum = false;

}

int Tile::getFoodAmount()
{
	return foodAmount; 
}

void Tile::clearFood()
{

	foodAmount = 0; 

}

void Tile::setFood()
{

	if (foodAmount < 3) {

		foodAmount++;

	}

}

