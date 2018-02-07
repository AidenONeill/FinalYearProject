/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deck.cpp
 * Author: aiden
 *
 * Created on 2nd December 2017, 16:48
 */




#include "deck.h"
#include "random.h"

Deck::Deck()
: index(0)
{
  for(size_t i = 0; i < 52; i++) cards[i].setIndex(i);
}

void Deck::shuffle()
{
  index = 0;

  Card old[52];
  for(size_t i = 0; i < 52; i++) old[i] = cards[i];

  for(size_t i = 0; i < 52; i++)
  {
    int r = (int)(getRandom() * (52 - i));
    cards[i] = old[r];
    std::swap(old[r], old[(52 - 1 - i)]);

  }
}

Card Deck::next()
{
  if(index >= 52) return Card();

  Card result = cards[index];
  index++;
  return result;
}
