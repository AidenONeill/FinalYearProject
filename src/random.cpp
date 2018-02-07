/* 
 * File:   random.cpp
 * Author: aiden
 *
 * Created on 2nd December 2017, 18:41
 */

#include "Casino/random.h"

#include <windows.h>
#include <iostream>

unsigned int getRandomUint()
{
  unsigned int r;

  HMODULE hLib=LoadLibrary("ADVAPI32.DLL");
  if (hLib) {
   BOOLEAN (APIENTRY *pfn)(void*, ULONG) =
        (BOOLEAN (APIENTRY *)(void*,ULONG))GetProcAddress(hLib,"SystemFunction036");
   if (pfn) {
    char buff[4];
    ULONG ulCbBuff = sizeof(buff);
    if(pfn(buff,ulCbBuff)) {

     r = buff[0] + 256 * buff[1] + 256 * 256 * buff[2] + 256 * 256 * 256 * buff[3];

    }
   }

   FreeLibrary(hLib);
  }

  return r;
}


double getRandom()
{
  return getRandomUint() / 4294967296.0;
}

int getRandom(int low, int high)
{
  return getRandomUint() % (high - low + 1) + low;
}
