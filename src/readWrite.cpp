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
using namespace std;

void writeToFile(const std::string& input ,const std::string& path) {
  ofstream myfile;
  myfile.open (path);
  if (myfile.is_open()) {
  cout << input <<endl;
  myfile << input;
  myfile.close();
  }
  else{ 
  myfile.close();
  cout << "TESTING" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10 + 1));
    writeToFile(input, path);
    }
}
string readFromFile(const std::string& path) {
  ifstream infile;
  string STRING;
  infile.open (path);
  infile.close();
  
  return STRING;  
}
vector<int> getCardHand(const std::string& path) {
  ifstream infile;
  string STRING;
  string ret;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){        
            ret = STRING;            
    }
    infile.close();
  }
    int c1 ,c2;
    std::stringstream ss(ret);    
    ss >> c1 >> c2;
    
    vector<int> hand (2);
    hand.at(0)= c1;
    hand.at(1)= c2;    
    return hand;  
}
vector<int> getCardsFlop(const std::string& path) {
  ifstream infile;
  string STRING;
  string ret;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){
        if(STRING.find("*** FLOP ***") != string::npos){ //change "bot1" to whatever bot file you are writing to.
            ret = STRING;
              }   
    }
    infile.close();
  }
    int c1 ,c2, c3;
    string t;
    ret.erase(std::remove(ret.begin(), ret.end(), '*'), ret.end());
    ret.erase(std::remove(ret.begin(), ret.end(), '['), ret.end());
    std::stringstream ss(ret);    
    ss >> t >> c1 >> c2 >> c3;
    
    vector<int> hand (3);
    hand.at(0)= c1;
    hand.at(1)= c2;
    hand.at(2)= c3;      
    return hand;  
}
vector<int> getCardsTurn(const std::string& path) {
  ifstream infile;
  string STRING;
  string ret;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){
        if(STRING.find("*** TURN ***") != string::npos){ //change "bot1" to whatever bot file you are writing to.
            ret = STRING;            
              }   
    }
    infile.close();
  }
    int c1 ,c2, c3, c4;
    string t;
    ret.erase(std::remove(ret.begin(), ret.end(), '*'), ret.end());
    ret.erase(std::remove(ret.begin(), ret.end(), '['), ret.end());
    std::stringstream ss(ret);    
    ss >> t >> c1 >> c2 >> c3 >> c4;
    
    vector<int> hand (4);
    hand.at(0)= c1;
    hand.at(1)= c2;
    hand.at(2)= c3;
    hand.at(3)= c4;
    return hand;  
}
vector<int> getCardsRiver(const std::string& path) {
  ifstream infile;
  string STRING;
  string ret;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){
        if(STRING.find("*** RIVER ***") != string::npos){ //change "bot1" to whatever bot file you are writing to.
            ret = STRING;
              }   
    }
    infile.close();
  }
    int c1 ,c2, c3, c4, c5;
    string t;
    ret.erase(std::remove(ret.begin(), ret.end(), '*'), ret.end());
    ret.erase(std::remove(ret.begin(), ret.end(), '['), ret.end());
    std::stringstream ss(ret);    
    ss >> t >> c1 >> c2 >> c3 >> c4 >> c5;
    
    vector<int> hand (5);
    hand.at(0)= c1;
    hand.at(1)= c2;
    hand.at(2)= c3;
    hand.at(3)= c4; 
    hand.at(4)= c5; 

    return hand;  
}
int getPotAmount(const std::string& path){
  ifstream infile;
  string STRING;
  int pot;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){
        if(STRING.find("Current ") != string::npos){ 
            pot=12;
        }
        if(STRING.find("called:") != string::npos){ 
            pot += 4;
        }
        if(STRING.find("raised:") != string::npos){
            pot += 4;
        }
        }
    infile.close();
  }
    return pot;
}
bool handInPlay(const std::string& path){
  ifstream infile;
  string STRING;
  bool inPlay;
  infile.open (path);
  if (infile.is_open()){
    while (getline(infile,STRING)){
        if(STRING.find("Current ") != string::npos){ 
            inPlay = true;
            cout << inPlay << endl;
        }
        if(STRING.find("won") != string::npos){ 
            inPlay = false;
            cout << inPlay << endl;
        }       
        }
    infile.close();
    
}
}
void convertHand(int a, int b){
    
    static const std::string Suit[4]{ "Spades", "Clubs", "Hearts", "Diamonds" };
    static const std::string Rank[13]{ "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    
    
    int suit1 = a % 4;
    int rank1 = a / 4;
    int suit2 = b % 4;
    int rank2 = b / 4;
    std::cout << "you have" << " received card " << Rank[rank1] << " of " << Suit[suit1] << endl;
    std::cout << "you have" << " received card " << Rank[rank2] << " of " << Suit[suit2] << endl;

} //not used for during implementation but useful for debugging
void convertBoard(int a, int b,int c,int d,int e){
    
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
    
    std::cout << "Board Cards " << Rank[rank1] << " of " << Suit[suit1] << " | "
                                << Rank[rank2] << " of " << Suit[suit2] << " | "
                                << Rank[rank3] << " of " << Suit[suit3] << " | "
                                << Rank[rank4] << " of " << Suit[suit4] << " | "
                                << Rank[rank5] << " of " << Suit[suit5] << " | " <<endl;
    

}//not used for during implementation but useful for debugging