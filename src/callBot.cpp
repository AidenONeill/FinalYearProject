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
#include "readWrite.h"
#include "callBot.h"

using namespace std;



void decideCallBot(){
    string path = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot2.txt";
    double d = getRandom();
        if (d>=0.05) //calls 95% of the time
        {
            writeToFile("c", path);
            cout << "Call Bot c\n";
        }
         else // folds 5% of the time
        {
            writeToFile("f", path);
            cout << "Call Bot f\n";
        }
    }


