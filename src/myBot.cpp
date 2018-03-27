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
//High Card 2                   myBot 
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
#include <numeric> 
// 0D0A44B34
// 10D2PfccrccF12F24F15FcrccT22TcrccR27RcrccSA1B23A45B17A42B51A0B33W0E

using namespace std;
using namespace omp;
std::time_t t = 0;
boost::filesystem::path p("");
double normaliseHand(const double& x) {
	double max = 36874;
	double min = 4098;
	return (x - min) / (max - min);
}
void preFlopDecision(int handStr, const std::string& botPath) {
	if (handStr < 35) {
		writeToFile("r", botPath);
	}
	else if (handStr < 85) {
		writeToFile("c", botPath);
	}
	else {
		t = boost::filesystem::last_write_time(p);
		writeToFile("f", botPath);
	}

}
void flopDecision(double handStr, std::vector<int>& hand, std::vector<int>& board, const std::string& botPath) {
	// Aces 0.243501
	// Twos 0.125153
	bool handSuited = false;
	if (hand.at(0) % 4 == hand.at(1)) handSuited = true;
	int flushCount = 0;
	for (std::size_t i = 0; i < 2; ++i) {
		for (std::size_t j = 0; j < 3; ++j) {
			if (hand[i] % 4 == board[j] % 4) { flushCount++; break;}
		}
	}
	for (std::size_t i = 0; i < 2; ++i) {
		for (std::size_t j = 1; j < 3; ++j) {
			if (i != j) {
				if (board[i] % 4 == board[j] % 4) flushCount++;
			}
		}
	}
	if (handStr > 0.697096) {
		writeToFile("r", botPath);
	}
	else if (handStr > 0.62620) { //flush
		double d = getRandom();
		if (d >= 0.90) {                   //calls 10% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.499877) { //straight
		double d = getRandom();
		if (d >= 0.70) {                   //calls 30% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.374877) { //3 of a Kind
		double d = getRandom();
		if (d >= 0.60) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.249907) { //2 Pair
		double d = getRandom();
		if (d >= 0.50) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.124939) { //Pair
		double d = getRandom();
		if (d >= 0.20) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr < 0.124939) {
		if (flushCount == 4 && handSuited) { // suited hand and 2 suit on the table
			double d = getRandom();
			if (d >= 0.11) {                   //calls 89% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
		else if (flushCount == 4 && !handSuited) {
			
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
		}
		else if (flushCount == 3 && handSuited) {
			double d = getRandom();
			if (d >= 0.22) {                   //calls 78% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
	}
	else {
		t = boost::filesystem::last_write_time(p);
		writeToFile("f", botPath);
	}
}
void turnDecision(double handStr, std::vector<int>& hand, std::vector<int>& board, const std::string& botPath) {
	bool handSuited = false;
	if (hand.at(0) % 4 == hand.at(1)) handSuited = true;
	int flushCount = 0;
	for (std::size_t i = 0; i < 2; ++i) {
		for (std::size_t j = 0; j < 4; ++j) {
			if (hand[i] % 4 == board[j] % 4) { flushCount++; break; }
		}
	}
	for (std::size_t i = 0; i < 3; ++i) {
		for (std::size_t j = 1; j < 4; ++j) {
			if (i != j) {
				if (board[i] % 4 == board[j] % 4) flushCount++;
			}
		}
	}
	if (handStr > 0.697095) {
		writeToFile("r", botPath);
	}
	else if (handStr > 0.62620) { //flush
		double d = getRandom();
		if (d >= 0.90) {                   //calls 10% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.499877) { //straight
		double d = getRandom();
		if (d >= 0.70) {                   //calls 30% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.374877) { //3 of a Kind
		double d = getRandom();
		if (d >= 0.60) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.249907 ) { //2 Pair
		double d = getRandom();
		if (d >= 0.50) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.124939 ) { //Pair
		double d = getRandom();
		if (d >= 0.60) {                   //calls 40% of the time
			writeToFile("c", botPath);
		}
		else if (d > 0.50 && d < 0.599) {
			writeToFile("r", botPath);
		}
		else {
			t = boost::filesystem::last_write_time(p);
			writeToFile("f", botPath);
		}
	}
	else if (handStr < 0.124939) {
		if (flushCount == 4 && handSuited) { // suited hand and 2 suit on the table
			double d = getRandom();
			if (d >= 0.11) {                   //calls 89% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
		else if (flushCount == 4 && !handSuited) {

			t = boost::filesystem::last_write_time(p);
			writeToFile("f", botPath);
		}
		else if (flushCount == 3 && handSuited) {
			double d = getRandom();
			if (d >= 0.22) {                   //calls 78% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
	}
	else {
		t = boost::filesystem::last_write_time(p);
		writeToFile("f", botPath);
	}
}
void riverDecision(double handStr, std::vector<int>& hand, std::vector<int>& board, const std::string& botPath) {
	bool handSuited = false;
	if (hand.at(0) % 4 == hand.at(1)) handSuited = true;
	int flushCount = 0;
	for (std::size_t i = 0; i < 2; ++i) {
		for (std::size_t j = 0; j < 5; ++j) {
			if (hand[i] % 4 == board[j] % 4) { flushCount++; break; }
		}
	}
	for (std::size_t i = 0; i < 4; ++i) {
		for (std::size_t j = 1; j < 5; ++j) {
			if (i != j) {
				if (board[i] % 4 == board[j] % 4) flushCount++;
			}
		}
	}
	if (handStr > 0.697095) {
		writeToFile("r", botPath);
	}
	else if (handStr > 0.62620) { //flush
		double d = getRandom();
		if (d >= 0.90) {                   //calls 10% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.499877) { //straight
		double d = getRandom();
		if (d >= 0.70) {                   //calls 30% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.374877) { //3 of a Kind
		double d = getRandom();
		if (d >= 0.60) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.249907) { //2 Pair
		double d = getRandom();
		if (d >= 0.50) {                   //calls 80% of the time
			writeToFile("c", botPath);
		}
		else {
			writeToFile("r", botPath);
		}
	}
	else if (handStr > 0.124938) { //Pair
		double d = getRandom();
		if (d >= 0.60) {                   //calls 40% of the time
			writeToFile("c", botPath);
		}
		else if (d > 0.50 && d < 0.599) {
			writeToFile("r", botPath);
		}
		else {
			t = boost::filesystem::last_write_time(p);
			writeToFile("f", botPath);
		}
	}
	else if (handStr < 0.124939 && handStr > 0.05) {
		if (flushCount == 4 && handSuited) { // suited hand and 2 suit on the table
			double d = getRandom();
			if (d >= 0.11) {                   //calls 89% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
		else if (flushCount == 4 && !handSuited) {

			t = boost::filesystem::last_write_time(p);
			writeToFile("f", botPath);
		}
		else if (flushCount == 3 && handSuited) {
			double d = getRandom();
			if (d >= 0.22) {                   //calls 78% of the time
				writeToFile("c", botPath);
			}
			else {
				t = boost::filesystem::last_write_time(p);
				writeToFile("f", botPath);
			}
		}
	}
	else {
		t = boost::filesystem::last_write_time(p);
		writeToFile("f", botPath);
	}
}
void myBotDecision() {
	//change t river and fold
	string casinoToBotPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/casinoToBot0";
	string botToCasinoPath = "C:/Users/aiden/Desktop/pokercasino-master/botfiles/botToCasino0";
	//string botPath = "C:/botfiles/casinoToBot0";
	std::vector<int> hand(2);
	hand = getCardHand(casinoToBotPath);
	p = ("");
	t = 0;
	std::time_t n = 0;
	if (getHandNumber(casinoToBotPath) % 2 == 0) {
		//p = ("C:\\\\botfiles\\handSummaryEven");
		p = ("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryEven");
		//cout << "Path Set " << p << endl;
		cout << "Hand Number: " << getHandNumber(casinoToBotPath) << endl;
		t = boost::filesystem::last_write_time(p);
		n = time(0) * 1000;
	}
	else {
		//p = ("C:\\\\botfiles\\handSummaryOdd");
		p = ("C:\\\\Users\\aiden\\Desktop\\pokercasino-master\\botfiles\\handSummaryOdd");
		cout << "Hand Number: " << getHandNumber(casinoToBotPath) << endl;
		//cout << "Path Set " << p << endl;
		t = boost::filesystem::last_write_time(p);
		n = time(0) * 1000;
	}
	HandEvaluator eval;
	Hand h = Hand::empty(); // Final hand must include empty() exactly once!
	std::vector<int> board(5);		
	//cout << "Hand 1:" << hand.at(0) << endl;
	//cout << "Hand 2:" << hand.at(1) << endl;
	bool flopFound = false;
	bool turnFound = false;
	bool riverFound = false;

	int handStr = eval2Card(convertHandToString(hand));
	cout << handStr << endl;
	t = boost::filesystem::last_write_time(p);
	preFlopDecision(handStr, botToCasinoPath);
	double d = 0;
	while (true) {

		if (t < boost::filesystem::last_write_time(p)) {
			t = boost::filesystem::last_write_time(p);
			cout << "break hit " << endl;
			break;
		}
		if (!flopFound&& checkForFlop(casinoToBotPath)) {
			flopFound = true;
			//cout << "Found Flop" << endl;
			h = Hand::empty();
			board = getCardsFlop(casinoToBotPath);
			h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)); //checks 5 cards
			//convertHand(hand.at(0), hand.at(1));
			//convertBoard(board.at(0), board.at(1), board.at(2), board.at(2), board.at(2));
			//cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
			flopDecision(normaliseHand(eval.evaluate(h)),hand,board,botToCasinoPath);
		}
		if (!turnFound && checkForTurn(casinoToBotPath)) {
			turnFound = true;
			//cout << "Found Turn" << endl;
			h = Hand::empty();
			board.push_back(getCardsTurn(casinoToBotPath));
			//cout << board.at(0) << "!" << board.at(1) << "!" << board.at(2) << "!" << board.at(3) << "!" << endl;
			h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)); //checks 6 cards
			//convertHand(hand.at(0), hand.at(1));
			//convertBoard(board.at(0), board.at(1), board.at(2), board.at(3), board.at(3));
			//cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
		
			turnDecision(normaliseHand(eval.evaluate(h)),hand,board,botToCasinoPath);
		}
		if (!riverFound && checkForRiver(casinoToBotPath)) {
			riverFound = true;
			//cout << "Found River" << endl;
			h = Hand::empty();
			board.push_back(getCardsRiver(casinoToBotPath));
			//cout << board.at(0) << "!" << board.at(1) << "!" << board.at(2) << "!" << board.at(3) << "!" << board.at(4) << "!" << endl;
			h += Hand(hand.at(0)) + Hand(hand.at(1)) + Hand(board.at(0)) + Hand(board.at(1)) + Hand(board.at(2)) + Hand(board.at(3)) + Hand(board.at(4)); //checks 7 cards
			//convertHand(hand.at(0), hand.at(1));
			//convertBoard(board.at(0), board.at(1), board.at(2), board.at(3), board.at(4));
			//cout << "Normalised Hand: " << normaliseHand(eval.evaluate(h)) << endl;
			t = boost::filesystem::last_write_time(p);
			riverDecision(normaliseHand(eval.evaluate(h)),hand,board,botToCasinoPath);
		}
	}
}