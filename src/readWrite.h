/* 
 * File:   readWrite.h
 * Author: aiden
 *
 * Created on 03 January 2018, 20:51
 */
//taken from OOpoker as my main focus should be the bot, not casino

#pragma once
#include <string>
#include <vector>
using namespace std;

void writeToFile(const std::string& input,const std::string& path);
string readFromFile(const std::string& path);
std::vector<int> getCardHand(const std::string& path);
std::vector<int> getCardsFlop(const std::string& path);
std::vector<int> getCardsTurn(const std::string& path);
std::vector<int> getCardsRiver(const std::string& path);
int getPotAmount(const std::string& path);
bool handInPlay(const std::string& path);
void convertHand(int a, int b);
void convertBoard(int a, int b,int c,int d,int e);