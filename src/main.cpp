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
#include "handCount.h"
#include "myBot.h"
#include "readWrite.h"
#include <atlstr.h>
using namespace std;

int main() {
	setHandCount(1);
	//cout << getHandCount() << endl;
	int handCount = getHandCount();
	


	HANDLE  ChangeHandle;
	bool botfileChanged = false;
	while (true)
	{
		handCount = getHandCount();
		string boardPath = "";
		if (handCount % 2 == 0) {
			boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathEven.txt";
		}
		else if (handCount % 2 == 1) {
			boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathOdd2.txt";
		}
		

		ChangeHandle = FindFirstChangeNotification(_T("C:\\\Users\\aiden\\Desktop\\PokerTesterGCC-master\\simulationFiles\\bots"), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
		if (handInPlay(boardPath)) {
			DWORD Wait = WaitForSingleObject(ChangeHandle, INFINITE);
			if (Wait == WAIT_OBJECT_0) {
				
				botfileChanged = true;

			}
			else {
				break;
			}

			if (botfileChanged) {
				botfileChanged = false;

				std::thread td1(myBotDecision);
				std::thread td2(decideCallBot);
				std::cout << "Started 2 threads. Waiting for them to finish..." << std::endl;
				td1.join();
				td2.join();
				FindCloseChangeNotification(ChangeHandle);

			}
			

			
			setHandCount(getHandCount() + 1);
			cout << getHandCount() << endl;
		}
	}


}

//int main() {
//
//	HANDLE  ChangeHandle;
//	bool botfileChanged = false;
//	cout << validHand("C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot1.txt") << endl;
//	while (true)
//	{
//		botfileChanged = false;
//		ChangeHandle = FindFirstChangeNotification(_T("C:\\\Users\\aiden\\Desktop\\PokerTesterGCC-master\\simulationFiles\\bots"), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
//
//		DWORD Wait = WaitForSingleObject(ChangeHandle, INFINITE);
//		if (Wait == WAIT_OBJECT_0) {
//
//			botfileChanged = true;
//			FindCloseChangeNotification(ChangeHandle);
//		}
//		else {
//			break;
//		}
//
//		if (botfileChanged) {
//			
//			cout << "testing" << endl;
//		}
//
//	}
//}




