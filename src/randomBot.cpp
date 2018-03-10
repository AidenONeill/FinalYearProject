/* 
 * File:   randomBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:04
 * 
 * calls folds and raises at random
 */
#include <iostream>
#include <string>
#include "Casino/random.h"
#include <chrono>
#include "readWrite.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
using namespace std;

void decideRandomBot() {

	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot1";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino1";

	boost::filesystem::path p("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryEven");
	boost::filesystem::path p2("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryOdd");
	std::time_t t = boost::filesystem::last_write_time(p);
	std::time_t t2 = boost::filesystem::last_write_time(p2);

	while (true) {

		if ((t < boost::filesystem::last_write_time(p)) || (t2 < boost::filesystem::last_write_time(p2))) {
			t = boost::filesystem::last_write_time(p);
			//cout << "Random Bot Hand End " << endl;
			break;
		}
		
			double d = getRandom();
			if (d >= 0.50) {                   //calls 50% of the time
				//cout << "Random Bot Calls" << endl;
				writeToFile("c", botToCasinoPath);

			}
			else if (d >= 0.10 && d < 0.50) {     // raises 40% of the time
				//cout << "Random Bot Raised" << endl;
				writeToFile("r", botToCasinoPath);

			}
			else {                          // folds 10% of the time
				//cout << "Random Bot Folds" << endl;
				writeToFile("f", botToCasinoPath);

			}
			
		}
	}






