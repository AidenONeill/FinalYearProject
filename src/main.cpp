/*
* File:   main.cpp
* Author: aiden
*
* Created on 03 February 2018, 20:49
*/

#include <cstdlib>
#include "callBot.h"
#include "randomBot.h"
#include "foldBot.h"
#include "HandEval/omp/EquityCalculator.h"
#include <iostream>
#include <string>
#include <thread>
#include "myBot.h"
#include "readWrite.h"
#include <atlstr.h>
#include <boost\filesystem.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
using namespace std;

int main() {
	//string botPath = "C:/botfiles/casinoToBot0";
	string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casintoToBot0";
	//boost::filesystem::path p("C:\\\\botfiles\\casinoToBot0");
	boost::filesystem::path p("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\casinoToBot0");
	std::time_t t1 = boost::filesystem::last_write_time(p);
	std::time_t n1 = time(0) * 1000;
	while (true)
	{
		//cout << "t" << t1 << endl;
		//cout << "t2" << boost::filesystem::last_write_time(p) << endl;
		if (t1 < boost::filesystem::last_write_time(p)) {	
				std::thread td1(myBotDecision);
				std::thread td2(decideRandomBot);
				std::thread td3(decideCallBot);
				std::thread td4(decideFoldBot);
				std::cout << "Started 2 threads. Waiting for them to finish..." << std::endl;
				td1.join();
				t1 = boost::filesystem::last_write_time(p);
				td2.join();
				td3.join();
				td4.join();
		}
	}

}




