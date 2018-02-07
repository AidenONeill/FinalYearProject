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

using namespace std;

void decideFoldBot () {
    string path = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathOdd.txt";
    string botPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot1.txt";
    std::vector<int> hand (2); 
    hand = getCardHand(path);
    double handStr = eval2Card(convertHandToString(hand));    
    if(handStr>18){                 //checks if the hand strength is greater than 18 out of 169 possible hands
        writeToFile("f", botPath);
    }
    else{
        writeToFile("c", botPath);
    }
    
    
    
    
   
}

