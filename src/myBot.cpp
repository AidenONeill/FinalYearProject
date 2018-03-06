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
#include "handStrength.h"
#include "Casino/random.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>
// 0D0A44B34
// 10D2PfccrccF12F24F15FcrccT22TcrccR27RcrccSA1B23A45B17A42B51A0B33W0E



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

	//string botPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot0";
	string botPath = "E:/botfiles/casinoToBot0";
	std::vector<int> hand(2);
	hand = getCardHand(botPath);
	boost::filesystem::path p("");
	std::time_t t = 0;
	std::time_t n = 0;
	if (getHandNumber(botPath) % 2 == 0) {
		p = ("E:\\\\botfiles\\handSummaryEven");
		//p = ("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryEven");
		cout << "Path Set " << p << endl;
		cout << "Hand Number: " << getHandNumber(botPath) << endl;
		t = boost::filesystem::last_write_time(p);
		n = time(0) * 1000;
	}
	else {
		p = ("E:\\\\botfiles\\handSummaryOdd");
		//p = ("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryOdd");
		cout << "Hand Number: " << getHandNumber(botPath) << endl;
		cout << "Path Set " << p << endl;
		t = boost::filesystem::last_write_time(p);
		n = time(0) * 1000;
	}


	HandEvaluator eval;
	Hand h = Hand::empty(); // Final hand must include empty() exactly once!

	std::vector<int> board(5);

	cout << "Hand 1:" << hand.at(0) << endl;
	cout << "Hand 2:" << hand.at(1) << endl;
	bool flopFound = false;
	bool turnFound = false;
	bool riverFound = false;


	int handStr = eval2Card(convertHandToString(hand));
	cout << handStr << endl;
	double d = 0;
	while (true) {
		if (t < boost::filesystem::last_write_time(p)) {
			t = boost::filesystem::last_write_time(p);
			cout << "break hit " << endl;
			break;
		}
		
			//cout << "waiting..." << endl;
			if (!flopFound&& checkForFlop(botPath)) {
				flopFound = true;
				cout << "Found Flop" << endl;
				h = Hand::empty();
				board = getCardsFlop(botPath);
				h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)); //checks 5 cards
				cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
			}
			if (!turnFound && checkForTurn(botPath)) {
				turnFound = true;
				cout << "Found Turn" << endl;
				h = Hand::empty();
				board.push_back(getCardsTurn(botPath));
				cout << board.at(0) << "!" << board.at(1) << "!" << board.at(2) << "!" << board.at(3) << "!" << endl;
				h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)); //checks 6 cards
				cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
			}
			if (!riverFound && checkForRiver(botPath)) {
				riverFound = true;
				cout << "Found River" << endl;
				h = Hand::empty();
				board.push_back(getCardsRiver(botPath));
				cout << board.at(0) << "!" << board.at(1) << "!" << board.at(2) << "!" << board.at(3) << "!" << board.at(4) << "!" << endl;
				h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)) + Hand(board.at(4)); //checks 7 cards
				cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
			}
		







	}

}
