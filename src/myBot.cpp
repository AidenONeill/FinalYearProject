/* 
 * File:   myBot.cpp
 * Author: aiden
 *
 * Created on 3nd December 2017, 11:03
 */    
    //Royal Flush                   36874   
    //Straight Flush A,2,3,4,5      36865
    //Four of a Kind A,A,A,A,K      32937
    //Four of a Kind 2,2,2,2        32769    
    //Full House Aces Over Kings    28828
    //Full House twos Over 3s       28673
    //Flush A,K,Q,J,9               26946
    //Flush 2,3,4,5,7               24623
    //Straight A,K,Q,J,10           20490
    //Straight A,2,3,4,5            20481 
    //3 of a kind Aces              17411
    //3 of a kind Twos              16385
    //Two Pair Aces Kings           13224
    //Two Pair Twos Threes          12290
    //Pair Aces                     12079
    //Pair Twos                     8193
    //High Card A,K,Q,J,9           6466
    //High Card 2,3,4,5,7           4128
    //High Card 2                   4098 
#include <cstdlib>
#include "HandEval/omp/HandEvaluator.h"
#include <iostream>
#include "readWrite.h"
#include <string>
#include "handStrength.h"


using namespace std;
using namespace omp;
double normaliseHand(const double& x){
    double max = 36874;
    double min = 4098;  
    return (x-min) / (max-min);    
}
double getPotOdds(const double& x){
    double d =  4 /(x + 4); 
    return d;
}
void myBotDecision(){
    
    string boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathOdd2.txt";
    string botPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot1.txt";
    HandEvaluator eval;
    Hand h = Hand::empty(); // Final hand must include empty() exactly once!
    std::vector<int> hand (2);
    std::vector<int> board (5); 
    hand = getCardHand(botPath);
    cout << getPotAmount(boardPath) << endl;
    cout << getPotOdds(getPotAmount(boardPath)) << endl;
    int handStr = eval2Card(convertHandToString(hand));
    cout << handStr << endl;
    if(handStr < 35){
        writeToFile("r",botPath);
    }
    else if(handStr <85){
         writeToFile("c",botPath);
    }
    else{
        writeToFile("f",botPath);        
    }    
    
    //flop
    h = Hand::empty();
    board = getCardsFlop(boardPath);   
    h += Hand(hand.at(0))+Hand(hand.at(1))+Hand(board.at(0))+Hand(board.at(1))+Hand(board.at(2)); //checks 5 cards
        
    //turn
    h = Hand::empty();
    board = getCardsTurn(boardPath);
    h += Hand(hand.at(0))+Hand(hand.at(1))+Hand(board.at(0))+Hand(board.at(1))+Hand(board.at(2))+Hand(board.at(3)); //checks 6 cards
    double d =normaliseHand(eval.evaluate(h));
    writeToFile("r",botPath);
    //river
    h = Hand::empty();
    board = getCardsRiver(boardPath);     
    h += Hand(hand.at(0))+Hand(hand.at(1))+Hand(board.at(0))+Hand(board.at(1))+Hand(board.at(2))+Hand(board.at(3))+Hand(board.at(4));  //checks 7 cards  
    writeToFile("r",botPath);
    convertHand(hand.at(0),hand.at(1));
    convertBoard(board.at(0),board.at(1),board.at(2),board.at(3),board.at(4));
    d =normaliseHand(eval.evaluate(h));
    
    cout << "Hand Strength With River "<< (eval.evaluate(h)) << endl;
    cout << "Normalise Hand "<< d << "%" << endl;
    
}


