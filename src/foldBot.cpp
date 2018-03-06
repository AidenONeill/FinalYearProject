/* 
 * File:   foldBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:06
 * 
 * folds unless his opening hand is top 10%
 */
#include "readWrite.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "handStrength.h"
#include "Casino/random.h"

using namespace std;

void decideFoldBot() {
	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot3";
	std::vector<int> hand(2);
	hand = getCardHand(botPath);
	double handStr = eval2Card(convertHandToString(hand));
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino3";
	while (true) {

		if (handInPlay(botPath)) {
			double d = getRandom();
			if (d <= 0.05) //calls 95% of the time
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

