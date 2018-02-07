#pragma once

//these methods use the true-random facilities provided by the operating system (non blocking, so not necessarily every returned value is true random!)
//it uses SystemFunction036 on Windows, /dev/urandom on Linux.
unsigned int getRandomUint();
double getRandom(); //returns random double in range 0.0-1.0
int getRandom(int low, int high); //returns random in the given range. high is included.
