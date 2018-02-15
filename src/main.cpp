/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aiden
 *
 * Created on 03 February 2018, 20:49
 */

#include <cstdlib>
#include "callBot.h"
#include "randomBot.h"
#include "foldBot.h"
#include "HandEval/omp/EquityCalculator.h"
#include <iostream>
#include <string>
#include <thread>

#include "myBot.h"
#include "readWrite.h"
using namespace std;

int main(){
        
        
       
        std::thread td1(myBotDecision);
        std::thread td2(decideCallBot);
        std::cout << "Started 2 threads. Waiting for them to finish..." << std::endl;
        td1.join();
        td2.join();             

   
    
//    cout << checkForTurn(path) << endl;
//    cout << checkForRiver(path) << endl;
   // decideRandomBot();

//    decideFoldBot();
}
    


