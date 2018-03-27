#include <iostream>
#include <fstream>
#include <string>
#include "Casino/random.h"
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <algorithm>
#include<vector>
#include <chrono>
#include <thread>
#include <regex>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/range/algorithm/count.hpp>
#include <boost/regex.hpp>
using namespace std;

void writeToFile(const std::string& input, const std::string& path) {
	ofstream myfile;
	myfile.open(path);
	if (myfile.is_open()) {
		myfile << input;
		myfile.close();
	}
	else {
		myfile.close();
		cout << "Error Opening File, ensure path is correct" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10 + 1));
		writeToFile(input, path);
	}
}
string readFromFile(const std::string& path) {
	ifstream infile;
	string STRING;
	infile.open(path);
	infile.close();

	return STRING;
}
vector<int> getCardHand(const std::string& path) {
	ifstream infile(path);
	string ret = "";

	if (infile) {
			infile >> ret ;		
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		vector<int> hand(2);
		hand.at(0) = 0;
		hand.at(1) = 5;
		return hand;
	}
	int c1, c2;
	boost::regex rgx("A[0-9][0-9]?B[0-9][0-9]?");
	boost::smatch sm;
	if (boost::regex_search(ret, sm, rgx)) {
		ret = sm[0];
		ret.erase(std::remove(ret.begin(), ret.end(), 'A'), ret.end());
		std::replace(ret.begin(), ret.end(), 'B', ' ');
		std::stringstream ss(ret);
		ss >> c1 >> c2;
		if ((c1 < 0 || c1>51) || (c2 < 0 || c2>51)) {
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
			vector<int> hand(2);
			hand.at(0) = 0;
			hand.at(1) = 5;
			return hand;
		}
		else {
			//cout << "C1" << c1 << endl;
			//cout << "C2" << c2 << endl;
			vector<int> hand(2);
			hand.at(0) = c1;
			hand.at(1) = c2;
			return hand;
		}
		
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		return getCardHand(path);
	}


}
bool checkForFlop(const std::string& path) {
	ifstream infile;
	string STRING;
	bool flopFound = false;
	infile.open(path);
	if (infile.is_open()) {
		while (getline(infile, STRING)) {
			boost::regex rgx("F[0-9][0-9]?F[0-9][0-9]?F[0-9][0-9]?F");
			if (boost::regex_search(STRING, rgx)) {
				flopFound = true;
			}
			else {
				flopFound = false;
			}
			infile.close();
		}
	}
	return flopFound;
}
bool checkForTurn(const std::string& path) {
	ifstream infile;
	string STRING;
	bool turnFound = false;
	infile.open(path);
	if (infile.is_open()) {
		while (getline(infile, STRING)) {
			boost::regex rgx("T[0-9][0-9]?T");
			if (boost::regex_search(STRING, rgx)) {
				turnFound = true;
			}
			else {
				turnFound = false;
			}
			infile.close();
		}
	}
	return turnFound;
}
bool checkForRiver(const std::string& path) {
	ifstream infile;
	string STRING;
	bool riverFound = false;
	infile.open(path);
	if (infile.is_open()) {
		while (getline(infile, STRING)) {
			boost::regex rgx("R[0-9][0-9]?R");
			if (boost::regex_search(STRING, rgx)) {
				riverFound = true;
			}
			else {
				riverFound = false;
			}
			infile.close();
		}
	}
	return riverFound;
}
vector<int> getCardsFlop(const std::string& path) {
	ifstream infile;
	string STRING;
	string ret;
	infile.open(path);
	if (infile.is_open()) {
		while (getline(infile, STRING)) {
			ret = STRING;
			cout << "Ret " << ret << endl;

		}
		infile.close();
	}
	int c1, c2, c3;
	boost::regex rgx("F[0-9][0-9]?F[0-9][0-9]?F[0-9][0-9]?F");
	boost::smatch sm;
	if (boost::regex_search(ret, sm, rgx)) {
		ret = sm[0];
		//cout << "Ret " << ret << endl;
		boost::replace_all(ret, "F", " ");
	}

	std::stringstream ss(ret);
	ss >> c1 >> c2 >> c3;
	if ((c1 < 0 || c1>51) || (c2 < 0 || c2>51) || (c3 < 0 || c3>51)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		vector<int> hand(3);
		hand.at(0) = 10;
		hand.at(1) = 15;
		hand.at(2) = 23;
		return hand;
	}
	else {
		vector<int> hand(3);
		//cout << "cFlop1: " << c1 << endl;
		//cout << "cFlop2: " << c2 << endl;
		//cout << "cFlop2: " << c3 << endl;
		hand.at(0) = c1;
		hand.at(1) = c2;
		hand.at(2) = c3;
		return hand;
	}
	
}
int getCardsTurn(const std::string& path) {
	ifstream infile;
	string STRING;
	string ret;
	infile.open(path);
	if (infile) {
		infile >> ret;
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		return 28;
		
	}
	int c1;
	boost::regex rgx("T[0-9][0-9]?T");
	boost::smatch sm;
	if (boost::regex_search(ret, sm, rgx)) {
		ret = sm[0];
		//cout << "Ret " << ret << endl;
		boost::replace_all(ret, "T", " ");
	}

	std::stringstream ss(ret);
	ss >> c1;
	if (c1 < 0 || c1>51) {
		return 28;
	}
	else {
		//cout << "cTurn1: " << c1 << endl;
		return c1;
	}
	

}
int getCardsRiver(const std::string& path) {
	ifstream infile;
	string STRING;
	string ret;
	infile.open(path);
	if (infile) {
		infile >> ret;
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		return 39;

	}
	int c1;
	boost::regex rgx("R[0-9][0-9]?R");
	boost::smatch sm;
	if (boost::regex_search(ret, sm, rgx)) {
		ret = sm[0];
		//cout << "Ret " << ret << endl;
		boost::replace_all(ret, "R", " ");
	}

	std::stringstream ss(ret);
	ss >> c1;
	if (c1 < 0 || c1>51) {
		return 39;
	}
	else {
		//cout << "cTurn1: " << c1 << endl;
		return c1;
	}

}
int getHandNumber(const std::string& path) {
	ifstream infile;
	string STRING;
	string ret;
	infile.open(path);
	if (infile.is_open()) {
		while (getline(infile, STRING)) {

			ret = STRING;

		}
		infile.close();
	}
	int c1;
	boost::regex rgx("\d+D");
	boost::smatch sm;
	if (boost::regex_search(ret, sm, rgx)) {
		ret = sm[0];
		boost::replace_all(ret, "D", " ");
	}
	std::stringstream ss(ret);
	ss >> c1;
	return c1;
}
void convertHand(int a, int b) {

	static const std::string Suit[4]{ "Spades", "Clubs", "Hearts", "Diamonds" };
	static const std::string Rank[13]{ "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };


	int suit1 = a % 4;
	int rank1 = a / 4;
	int suit2 = b % 4;
	int rank2 = b / 4;
	std::cout << "Hand Cards | " << Rank[rank1] << " of " << Suit[suit1] << " | "
							   << Rank[rank2] << " of " << Suit[suit2] << " | "<< endl;

} //not used for during implementation but useful for debugging
void convertBoard(int a, int b, int c, int d, int e) {

	static const std::string Suit[4]{ "Spades", "Clubs", "Hearts", "Diamonds" };
	static const std::string Rank[13]{ "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

	int suit1 = a % 4;
	int rank1 = a / 4;
	int suit2 = b % 4;
	int rank2 = b / 4;
	int suit3 = c % 4;
	int rank3 = c / 4;
	int suit4 = d % 4;
	int rank4 = d / 4;
	int suit5 = e % 4;
	int rank5 = e / 4;

	std::cout << "Board Cards| " << Rank[rank1] << " of " << Suit[suit1] << " | "
		<< Rank[rank2] << " of " << Suit[suit2] << " | "
		<< Rank[rank3] << " of " << Suit[suit3] << " | "
		<< Rank[rank4] << " of " << Suit[suit4] << " | "
		<< Rank[rank5] << " of " << Suit[suit5] << " | " << endl;


}//not used for during implementation but useful for debugging