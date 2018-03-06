/*
 * File:   callBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:09
 *
 * will call 95% of hands
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Casino/random.h"
#include <stdlib.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "readWrite.h"
#include "callBot.h"
#include "handCount.h"

using namespace std;



void decideCallBot() {
	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot1";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino1";
	while (true) {

		if (handInPlay(botPath)) {
			double d = getRandom();
			if (d >= 0.05) //calls 95% of the time
			{
				writeToFile("c", botToCasinoPath);
				//            cout << "Call Bot c\n";
			}
			else // folds 5% of the time
			{
				writeToFile("f", botToCasinoPath);
				//            cout << "Call Bot f\n";
			}
		}
		else {
			break;
		}
	}
}
		
	


