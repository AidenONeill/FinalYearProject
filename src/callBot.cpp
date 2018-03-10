/*
 * File:   callBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:09
 *
 * will call 95% of hands
 */
#include <iostream>
#include <string>
#include "Casino/random.h"
#include <chrono>
#include "readWrite.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
using namespace std;

void decideCallBot() {

	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot2";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino2";


	boost::filesystem::path p("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryEven");
	boost::filesystem::path p2("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryOdd");
	std::time_t t = boost::filesystem::last_write_time(p);
	std::time_t t2 = boost::filesystem::last_write_time(p2);

	while (true) {

		if ((t < boost::filesystem::last_write_time(p)) || (t2 < boost::filesystem::last_write_time(p2))) {
			t = boost::filesystem::last_write_time(p);
			//cout << "Call Bot Hand End " << endl;
			break;
		}

		double d = getRandom();
		if (d >= 0.10) //calls 90% of the time
		{
			//cout << "Call Bot Calls" << endl;
			writeToFile("c", botToCasinoPath);
		}
		else // folds 10% of the time
		{
			//cout << "Call Bot Folds" << endl;
			writeToFile("f", botToCasinoPath);
		}

	}
}
		
	


