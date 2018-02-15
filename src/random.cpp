/* 
 * File:   random.cpp
 * Author: aiden
 *
 * Created on 2nd December 2017, 18:41
 */

#include <windows.h>
#include <iostream>
#include <random>
#include <time.h>
#include <functional>

double getRandom()
{
 srand ( time(0)*time(0) );
 
     double d = rand() / (RAND_MAX + 1.);
     
     if(d<0.0 || d>1.0){
         getRandom();
     }
     else return d;
}

