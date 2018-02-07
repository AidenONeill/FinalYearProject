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

using namespace std;

void decideRandomBot(){
     string path =  "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot2.txt";
    double d = getRandom();
        if (d>=0.30){                   //calls 70% of the time
            writeToFile("c", path);
            cout << "Random Bot c\n";
        }
        else if(d>=0.10 && d<0.30){     // raises 20% of the time
            writeToFile("r", path);
            cout << "Random Bot r\n";
        }
        else {                          // folds 10% of the time
            writeToFile("f", path);
            cout << "Random Bot f\n";
        }
    }





