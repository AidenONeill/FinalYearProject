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

	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot2";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino2";
	while (true) {

		if (handInPlay(botPath)) {
			double d = getRandom();
			if (d >= 0.30) {                   //calls 70% of the time
				writeToFile("c", botToCasinoPath);

			}
			else if (d >= 0.10 && d < 0.30) {     // raises 20% of the time
				writeToFile("r", botToCasinoPath);

			}
			else {                          // folds 10% of the time
				writeToFile("f", botToCasinoPath);

			}
			
		}
		else{
			break;
		}
	}
}






