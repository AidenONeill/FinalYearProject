/* 
 * File:   foldBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:06
 * 
 * folds unless his opening hand is top 10%
 */
#include <iostream>
#include <string>
#include "Casino/random.h"
#include <chrono>
#include "readWrite.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
using namespace std;


void decideFoldBot() {

	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot3";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino3";


	boost::filesystem::path p("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryEven");
	boost::filesystem::path p2("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryOdd");
	std::time_t t = boost::filesystem::last_write_time(p);
	std::time_t t2 = boost::filesystem::last_write_time(p2);

	while (true) {

		if ((t < boost::filesystem::last_write_time(p)) || (t2 < boost::filesystem::last_write_time(p2))) {
			t = boost::filesystem::last_write_time(p);
			//cout << "Fold Bot Hand End " << endl;
			break;
		}

		double d = getRandom();
		if (d >= 0.05) //calls 95% of the time
		{
			writeToFile("f", botToCasinoPath);
			//cout << "Fold Bot Folds" << endl;
		}
		else // folds 5% of the time
		{
			//cout << "Fold Bot Calls" << endl;
			writeToFile("c", botToCasinoPath);
		}

	}
}

