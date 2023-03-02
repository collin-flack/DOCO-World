/************************
*File: Simulation.cpp
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

#include "Simulation.h"
#include <vector> 

using namespace std; 

Simulation::Simulation(int setter)
{

	char move[5000];
	const char dataFile[15] = "DOCOData02.xml";
	DataParser * tester;
	tester = DataParser::getInstance(dataFile); 
	numDOCOS = tester->getDOCOCount() + 1; // Adjusted by one so that all values when getDOCOData is called are valid
	height = tester->getDOCOWorldHeight();
	width = tester->getDOCOWorldWidth();
	numFood = tester->getFoodCount();
	frameNum = 0; 
	timesToRun = setter;
	int iter = 0;
	while (iter < numDOCOS) {

		int index = iter + 1; 
		tester->getDOCOData(move, &xVals[index], &yVals[index]);
		iter++;
	}
	
	movementInts = tester->getMovementInts(); 

/*
	for (int i = 0; i < movementInts.size(); i++) {

		switch (movementInts[i]) {
		case 1:

			cout << "Vertical" << endl;
			break;

		case 2:

			cout << "Horizontal" << endl;
			break;

		case 3:

			cout << "Diagonal" << endl;
			break;

		default: 

			cout << "Error" << endl; 
			break;
		}
	}
*/
	
	height = height + 3; // Adjusting for boundary values
	width = width + 3;
	simBegin = true;

	Tile theWorld[WIDTHC][HEIGHTC];

	
	initSim(theWorld); 

	

}

Simulation::~Simulation()
{
}

void Simulation::initSim(Tile world[WIDTHC][HEIGHTC])
{

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {

			Tile * cell = new Tile(w, h); 
			world[w][h] = *cell; 

		}

	}

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {

			if (h == 0 || h == 1 || w == 0 || w == 1 || w == width || h == height) {

				world[w][h].setType(1); 

			}

			else {

				world[w][h].setType(3); 

			}

			if ((w > 1 && w < width && h == 0) || (w > 1 && w < width && h == 1)) {

				world[w][h].setType(5); 

			}

			else if ((h > 1 && h < height && w == 0) || (h > 1 && h < height && w == 1)) {

				world[w][h].setType(5); 

			}

		}

	}
	//cout << endl << frameNum << endl;
	//display(world); 
	updateSim(world); 

}

void Simulation::display(Tile world[WIDTHC][HEIGHTC])
{

	int countOne = 0, countTen = 0, countTenH = 0, countOneH = 0, countOnePrint = 0, countOnePrintH = 0; 

	for (int h = 0; h < height; h++) {
		cout << endl; 
		for (int w = 0; w < width; w++) {

			if ((h == 0 && w == 0) || (h == 0 && w == 1) || (h == 1 && w == 0) || (h == 1 && w == 1)) {

				cout << " ";

			}

			if (h == 0 && world[w][h].getType(5)) {

				cout << countTen; 

			}

			if (h == 1 && world[w][h].getType(5)) {

				cout << countOnePrint; 

			}

			if ((h > 1 && w > 1) && (h < height && w < width)) {

				if (world[w][h].getType(2)) {

					cout << "*";

				}

				else if (world[w][h].getType(3)) {

					cout << "-";

				}

				else if (world[w][h].getType(4)) {

					cout << ".";

				}
			}

			
			if (w == 0 && world[w][h].getType(5)) {

				cout << countTenH; 

			}

			if (w == 1 && world[w][h].getType(5)) {

				cout << countOnePrintH; 

			}

			if (w > 1 && w < width) {

				countOne++;

				if (countOne == 10) {

					countTen++;
					countOne = 0; 

				}

			}

			if (w > 1 && w < width && h == 1) {

				countOnePrint++;

				if (countOnePrint == 10) {

					countOnePrint = 0; 

				}

			}

			if ((h > 1 && h < height) && w == 0) {

				countOneH++;

				if (countOneH == 10) {

					countTenH++;
					countOneH = 0;

				}

			}

			if (h > 1 && h < height && w == 1) {

				countOnePrintH++;

				if (countOnePrintH == 10) {

					countOnePrintH = 0; 

				}

			}

		}
	}

}

Tile Simulation::findTile(Tile world[WIDTHC][HEIGHTC], int x, int y)
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

void Simulation::updateSim(Tile world[WIDTHC][HEIGHTC])
{


	Tile alterTile; 

	if (simBegin) {

		cout << endl << endl << "Frame ";
		cout << frameNum; 
		incrementFrameNumber(); 

		for (int i = 1; i < numDOCOS; i++) {

			int indexer = i;
	
			int xPos = xVals[indexer] + 2;
			int yPos = yVals[indexer] + 2;

			DOCO * thisDOCO = new DOCO(xPos, yPos, height, width);

			// cout << endl << yPos << endl; 

			if (world[xPos][yPos].getType(3)) {

				world[xPos][yPos].clearTypes();
				world[xPos][yPos].setType(2); 
				DOCOS[i] = thisDOCO;

			}


		}

		for (int i = 1; i < numFood; i++) {

			spawnFood(world);

		}
		simBegin = false;
		display(world);
	}

	// ONE SECOND DELAY
	Sleep(1000);

	for (int d = 1; d < numDOCOS; d++) {

		DOCOS[d]->move(world); 
		if (DOCOS[d]->checkForDeath()) {

			DOCOS[d]->die(world);
			DOCOS[d]->~DOCO();

		}

	} 
	
	int food = rand() % 10 + 1;

	for (int i = 1; i < food; i++) {

		spawnFood(world); 

	}
	cout << endl << endl << "Frame "; 
	cout << frameNum;
	incrementFrameNumber(); 
	display(world);
	if (frameNum < (timesToRun + 1)) {
		updateSim(world);
	}
}

void Simulation::spawnFood(Tile world[WIDTHC][HEIGHTC]) // Spawns a food pellet . in an empty tile randomly. Run per amount of pellets wanted. 
{


	vector<Tile> emptyTiles; 

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {

			if (world[w][h].getType(3)) {

				emptyTiles.push_back(world[w][h]); 

			}

		}

	}

	int iter = emptyTiles.size(); 

	int indexForFood = rand() % iter + 1; 
	indexForFood--;

	int xTile = emptyTiles[indexForFood].getX(); 
	int yTile = emptyTiles[indexForFood].getY(); 

	world[xTile][yTile].setFood(); 
	world[xTile][yTile].clearTypes();
	world[xTile][yTile].setType(4); 



}

void Simulation::incrementFrameNumber()
{

	frameNum++;

}

