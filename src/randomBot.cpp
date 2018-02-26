/* 
 * File:   randomBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:04
 * 
 * calls folds and raises at random
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Casino/random.h"
#include <stdlib.h>
#include <conio.h>
#include "readWrite.h"
#include "handCount.h"

using namespace std;

void decideRandomBot() {

	string path = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot2.txt";

	int handCount = getHandCount();
	string boardPath = "";
	if (handCount % 2 == 0) {
		boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathEven.txt";
	}
	else if (handCount % 2 == 1) {
		boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathOdd2.txt";
	}

	while (true) {

		double d = getRandom();
		if (d >= 0.30) {                   //calls 70% of the time
			writeToFile("c", path);
	
		}
		else if (d >= 0.10 && d < 0.30) {     // raises 20% of the time
			writeToFile("r", path);
		
		}
		else {                          // folds 10% of the time
			writeToFile("f", path);
		
		}
		if (!handInPlay(boardPath)) {
			break;
		}
	}
}





