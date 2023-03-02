/************************
*File: DOCO.cpp
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

#include "DOCO.h"

DOCO::DOCO()
{
	direction = 0; 
	energy = 0; 
	xPos = 0; 
	yPos = 0; 
	height = 0; 
	width = 0;


}

DOCO::DOCO(int x, int y, int h, int w)
{

	int randDir = rand() % 8 + 1; 
	randDir--; 

	direction = randDir; 
	//cout << endl << "DOCO direction: ";
	//cout << direction << endl; 
	energy = 500;
	xPos = x;
	yPos = y;
	height = h;
	width = w;

}

DOCO::~DOCO()
{
}

int DOCO::getEnergy()
{
	return energy;
}

bool DOCO::checkForDeath()
{
	if (getEnergy() <= 0) {
		return true; 
	}

	else {
		return false; 
	}
}

void DOCO::move(Tile world[WIDTHCO][HEIGHTCO])
{

	smell(world);

	switch (direction) {

	case 0:
		if (world[xPos][yPos + 1].getType(4)) {

			
			world[xPos][yPos].clearTypes(); 
			//cout << endl << "Types cleared" << endl; 
			world[xPos][yPos].setType(3);
			
			world[xPos][yPos + 1].clearTypes(); 
			world[xPos][yPos + 1].setType(2); 

			yPos = yPos + 1; 
			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood(); 

		}

		else if (world[xPos][yPos + 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			//cout << endl << "Types cleared" << endl;
			world[xPos][yPos].setType(3);

			world[xPos][yPos + 1].clearTypes();
			world[xPos][yPos + 1].setType(2);

			yPos = yPos + 1;

		}

		else if (world[xPos][yPos + 1].getType(1) || world[xPos][yPos + 1].getType(2) || world[xPos][yPos + 1].getType(5)) {
			changeDirection(0, world); 
		}

		break;
	case 1:
		if (world[xPos + 1][yPos + 1].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos + 1].clearTypes();
			world[xPos + 1][yPos + 1].setType(2);

			xPos = xPos + 1; 
			yPos = yPos + 1;
			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos + 1][yPos + 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos + 1].clearTypes();
			world[xPos + 1][yPos + 1].setType(2);

			xPos = xPos + 1;
			yPos = yPos + 1;

		}

		else if (world[xPos + 1][yPos + 1].getType(1) || world[xPos + 1][yPos + 1].getType(2) || world[xPos + 1][yPos + 1].getType(5)) {
		
			changeDirection(1, world);

		}
		break;
	case 2:
		if (world[xPos + 1][yPos].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos].clearTypes();
			world[xPos + 1][yPos].setType(2);

			xPos = xPos + 1;

			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos + 1][yPos].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos].clearTypes();
			world[xPos + 1][yPos].setType(2);

			xPos = xPos + 1;

		}

		else if (world[xPos + 1][yPos].getType(1) || world[xPos + 1][yPos].getType(2) || world[xPos + 1][yPos].getType(5)) {

			changeDirection(2, world);

		}
		break;
	case 3:
		if (world[xPos + 1][yPos - 1].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos - 1].clearTypes();
			world[xPos + 1][yPos - 1].setType(2);

			xPos = xPos + 1;
			yPos = yPos - 1;
			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos + 1][yPos - 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos + 1][yPos - 1].clearTypes();
			world[xPos + 1][yPos - 1].setType(2);

			xPos = xPos + 1;
			yPos = yPos - 1;

		}

		else if (world[xPos + 1][yPos - 1].getType(1) || world[xPos + 1][yPos - 1].getType(2) || world[xPos + 1][yPos - 1].getType(5)) {

			changeDirection(3, world);

		}
		break;
	case 4:
		if (world[xPos][yPos - 1].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos][yPos - 1].clearTypes();
			world[xPos][yPos - 1].setType(2);

			yPos = yPos - 1;

			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos][yPos - 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos][yPos - 1].clearTypes();
			world[xPos][yPos - 1].setType(2);

			yPos = yPos - 1;

		}

		else if (world[xPos][yPos - 1].getType(1) || world[xPos][yPos - 1].getType(2) || world[xPos][yPos - 1].getType(5)) {

			changeDirection(4, world);

		}
		break;
	case 5:
		if (world[xPos - 1][yPos - 1].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos - 1].clearTypes();
			world[xPos - 1][yPos - 1].setType(2);

			xPos = xPos - 1;
			yPos = yPos - 1;
			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos - 1][yPos - 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos - 1].clearTypes();
			world[xPos - 1][yPos - 1].setType(2);

			xPos = xPos - 1;
			yPos = yPos - 1;

		}

		else if (world[xPos - 1][yPos - 1].getType(1) || world[xPos - 1][yPos - 1].getType(2) || world[xPos - 1][yPos - 1].getType(5)) {

			changeDirection(5, world);

		}
		break;
	case 6:
		if (world[xPos - 1][yPos].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos].clearTypes();
			world[xPos - 1][yPos].setType(2);

			xPos = xPos - 1;

			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos - 1][yPos].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos].clearTypes();
			world[xPos - 1][yPos].setType(2);

			xPos = xPos - 1;

		}

		else if (world[xPos - 1][yPos].getType(1) || world[xPos - 1][yPos].getType(2) || world[xPos - 1][yPos].getType(5)) {

			changeDirection(6, world);

		}
		break;
	case 7:
		if (world[xPos - 1][yPos + 1].getType(4)) {


			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos + 1].clearTypes();
			world[xPos - 1][yPos + 1].setType(2);

			xPos = xPos - 1;
			yPos = yPos + 1;
			eat(world[xPos][yPos].getFoodAmount());
			world[xPos][yPos].clearFood();

		}

		else if (world[xPos - 1][yPos + 1].getType(3)) {

			world[xPos][yPos].clearTypes();
			world[xPos][yPos].setType(3);

			world[xPos - 1][yPos + 1].clearTypes();
			world[xPos - 1][yPos + 1].setType(2);

			xPos = xPos - 1;
			yPos = yPos + 1;

		}

		else if (world[xPos - 1][yPos + 1].getType(1) || world[xPos - 1][yPos + 1].getType(2) || world[xPos - 1][yPos + 1].getType(5)) {

			changeDirection(7, world);

		}
		break;
	default:
		// Should not occur 
		cout << "Error" << endl; 
		break; 


	}

	addEnergy(-10);


}

void DOCO::smell(Tile world[WIDTHCO][HEIGHTCO])
{

	Tile leftTile, rightTile, aboveTile, belowTile, upRight, downRight, upLeft, downLeft; 
	leftTile = findTile(world, xPos - 1, yPos);
	rightTile = findTile(world, xPos + 1, yPos); 
	aboveTile = findTile(world, xPos, yPos + 1); 
	belowTile = findTile(world, xPos, yPos - 1); 
	upRight = findTile(world, xPos + 1, yPos + 1); 
	downRight = findTile(world, xPos + 1, yPos - 1); 
	upLeft = findTile(world, xPos - 1, yPos + 1); 
	downLeft = findTile(world, xPos - 1, yPos - 1); 

	if (aboveTile.getType(4)) {
		// cout << endl << "Food smelled" << endl; 
		// Food smelled
		direction = 0; 

	}

	else if (upRight.getType(4)) {

		direction = 1; 

	}

	else if (rightTile.getType(4)) {

		direction = 2;

	}

	else if (downRight.getType(4)) {

		direction = 3;

	}

	else if (belowTile.getType(4)) {

		direction = 4; 

	}

	else if (downLeft.getType(4)) {

		direction = 5;

	}

	else if (leftTile.getType(4)) {

		direction = 6;

	}

	else if (upLeft.getType(4)) {

		direction = 7;

	}
}

void DOCO::eat(int numPellets)
{

//	cout << endl << "Trying to eat" << endl;
	for (int i = 0; i < numPellets; i++) {

		addEnergy(50); 
		//cout << endl << "Ate a food" << endl;

	}
}

void DOCO::addEnergy(int amount)
{

	energy += amount; 

}

void DOCO::changeDirection(int prevDir, Tile world[WIDTHCO][HEIGHTCO])
{
	
	int newDir = rand() % 7 + 1;

	switch (prevDir) {

	case 0:
		switch (newDir) {

		case 1:
			direction = 1; 
			break;
		case 2:
			direction = 2;
			break;
		case 3:
			direction = 3;
			break;
		case 4:
			direction = 4;
			break;
		case 5:
			direction = 5;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break; 
		}
		break;

	case 1:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 2;
			break;
		case 3:
			direction = 3;
			break;
		case 4:
			direction = 4;
			break;
		case 5:
			direction = 5;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 2:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 3;
			break;
		case 4:
			direction = 4;
			break;
		case 5:
			direction = 5;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 3:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 2;
			break;
		case 4:
			direction = 4;
			break;
		case 5:
			direction = 5;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 4:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 2;
			break;
		case 4:
			direction = 3;
			break;
		case 5:
			direction = 5;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 5:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 2;
			break;
		case 4:
			direction = 3;
			break;
		case 5:
			direction = 4;
			break;
		case 6:
			direction = 6;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 6:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 2;
			break;
		case 4:
			direction = 3;
			break;
		case 5:
			direction = 4;
			break;
		case 6:
			direction = 5;
			break;
		case 7:
			direction = 7;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;
		}
		break;

	case 7:
		switch (newDir) {

		case 1:
			direction = 0;
			break;
		case 2:
			direction = 1;
			break;
		case 3:
			direction = 2;
			break;
		case 4:
			direction = 3;
			break;
		case 5:
			direction = 4;
			break;
		case 6:
			direction = 5;
			break;
		case 7:
			direction = 6;
			break;
		default:
			cout << "Error" << endl; // Should not occur
			break;

		}
		break;
	}
	//cout << endl << "Direction Changed" << endl; 
	move(world); 

}

Tile DOCO::findTile(Tile world[WIDTHCO][HEIGHTCO], int x, int y)
{
	Tile theTile;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {

			if (world[w][h].getX() == x && world[w][h].getY() == y) {

				theTile = world[w][h];

			}

		}

	}

	return theTile;

}

void DOCO::die(Tile world[WIDTHCO][HEIGHTCO])
{

	world[xPos][yPos].clearTypes(); 
	world[xPos][yPos].setType(3); 

}
