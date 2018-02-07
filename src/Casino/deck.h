#pragma once

#include "card.h"


class Deck
{
  /*
  Deck of cards, that can be randomly shuffled using the true random.h, and
  allows easily selecting next cards.
  */

  private:

    Card cards[52]; //card 0 is the top card
    int index;

  public:

    Deck();
    void shuffle();
    Card next();
};
