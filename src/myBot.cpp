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
#include <chrono>
#include <thread>
#include "handCount.h"
#include "handStrength.h"
#include "Casino/random.h"



using namespace std;
using namespace omp;
double normaliseHand(const double& x) {
	double max = 36874;
	double min = 4098;
	return (x - min) / (max - min);
}
double getPotOdds(const double& x) {
	double d = 4 / (x + 4);
	return d;
}

void preFlopDecision(int handStr, const std::string& botPath) {

	if (handStr < 35) {
		writeToFile("r", botPath);
	}
	else if (handStr < 85) {
		writeToFile("c", botPath);
	}
	else {
		writeToFile("f", botPath);
	}
}
void myBotDecision() {

	int handCount = getHandCount();
	string boardPath = "";
	if (handCount % 2 == 0) {
		boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathEven.txt";
	}
	else if (handCount % 2 == 1) {
		boardPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/playAreaPathOdd2.txt";
	}
	cout << boardPath << endl;
	string botPath = "C:/Users/aiden/Desktop/PokerTesterGCC-master/simulationFiles/bots/bot1.txt";
	HandEvaluator eval;
	Hand h = Hand::empty(); // Final hand must include empty() exactly once!
	std::vector<int> hand(2);
	std::vector<int> board(5);
	hand = getCardHand(botPath);
	cout << "Hand 1:" << hand.at(0) << endl;
	cout << "Hand 2:" << hand.at(1) << endl;
	bool flopFound = false;
	bool turnFound = false;
	bool riverFound = false;


	//    cout << "Pot Amount: " << getPotAmount(boardPath) << endl;
	//    cout << "Pot Odds: " << getPotOdds(getPotAmount(boardPath)) << endl;
	int handStr = eval2Card(convertHandToString(hand));
	cout << handStr << endl;
	double d = 0;
	if (!checkForFlop(boardPath)) {
		cout << "Hit here" << endl;
		preFlopDecision(handStr, botPath);
	}

	while (true){
		if (handInPlay(boardPath)) {
			if (checkForFlop(boardPath) && !flopFound) {
				flopFound = true;
				cout << "Found Flop" << endl;
				h = Hand::empty();
				board = getCardsFlop(boardPath);
				if ((hand.at(0) < 0 || hand.at(0) > 51) || (hand.at(1) < 0 || hand.at(1) > 51) || (board.at(0) < 0 || board.at(0) > 51) || (board.at(1) < 0 || board.at(1) > 51) || (board.at(2) < 0 || board.at(2) > 51)) {
					writeToFile("c", botPath);
				}
				else {
					h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)); //checks 5 cards
					cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
					d = normaliseHand(eval.evaluate(h)) / getPotOdds(getPotAmount(boardPath));
				}				
			}
			if (checkForTurn(boardPath) && !turnFound) {
				turnFound = true;
				cout << "Found Turn" << endl;
				h = Hand::empty();
				board = getCardsTurn(boardPath);

				if ((hand.at(0) < 0 || hand.at(0) > 51) || (hand.at(1) < 0 || hand.at(1) > 51) || (board.at(0) < 0 || board.at(0) > 51) || (board.at(1) < 0 || board.at(1) > 51) || (board.at(2) < 0 || board.at(2) > 51) || (board.at(3) < 0 || board.at(3) > 51)) {
					writeToFile("c", botPath);
				}
				else {
					h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)); //checks 6 cards
					cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
					d = normaliseHand(eval.evaluate(h)) / getPotOdds(getPotAmount(boardPath));
				}
				
			}
			if (checkForRiver(boardPath) && !riverFound) {
				riverFound = true;
				cout << "Found River" << endl;
				h = Hand::empty();
				board = getCardsRiver(boardPath);

				if ((hand.at(0) < 0 || hand.at(0) > 51) || (hand.at(1) < 0 || hand.at(1) > 51) || (board.at(0) < 0 || board.at(0) > 51) || (board.at(1) < 0 || board.at(1) > 51) || (board.at(2) < 0 || board.at(2) > 51) || (board.at(3) < 0 || board.at(3) > 51) || (board.at(4) < 0 || board.at(4) > 51)) {
					writeToFile("c", botPath);
				}
				else {
					h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)) + Hand(board.at(4));  //checks 7 cards
					cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
					d = normaliseHand(eval.evaluate(h)) / getPotOdds(getPotAmount(boardPath));
				}
				
			}


			if (d > 5) {
				cout << "If Hit " << d << endl;
				writeToFile("r", botPath);
			}
			else if (d > 2.5) {
				cout << "else If 1 hit: " << d << endl;
				writeToFile("c", botPath);
			}
			else if (d > 0 && d < 1.8) {
				cout << "else If 2 hit: " << d << endl;
				double  bluff = getRandom();
				if (bluff > 0.06) {
					writeToFile("c", botPath);
				}
				else {
					writeToFile("f", botPath);
				}
			}
			else if (d < 0) {
				cout << "Hit Else" << endl;
				writeToFile("f", botPath);
			}

			if (!handInPlay(boardPath)) {
				break;
			}

		}



	}
}
	





