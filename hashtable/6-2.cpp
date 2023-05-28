#include "6-2.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <uchar.h>
using namespace std;

extern const int MAX_SUIT = 4;
extern const int MAX_RANK = 13;
extern const int Ace = 1;
extern const int Jack = 11;
extern const int Queen = 12;
extern const int King = 13;

Card::Card() {}

Card::Card(string str) {
  int l = str.length();
  assert(l == 2 || l == 3);
  string s = str.substr(l - 1, 1);
  string r = str.erase(l - 1, 1);
  suit = strToSuit(s);
  rank = strToRank(r);
}

Card::Card(int r, Suit s) {
  if ((r >= 1) && (MAX_RANK >= r))
    rank = r;
  else {
    cout << "Bad Rank!";
    exit(1);
  }
  suit = s;
}

Suit Card::getSuit() { return suit; }

int Card::getRank() { return rank; }

string Card::toString() {
  string rStr = rankToString(rank);
  string sStr = suitToString(suit);

  return rStr + sStr;
}

Card::~Card() {}

string Card::rankToString(int r) {
  string str;
  switch (r) {
  case Ace:
    str = "A";
    break;

  case Queen:
    str = "Q";
    break;

  case Jack:
    str = "J";
    break;

  case King:
    str = "K";
    break;

  default:
    ostringstream os;
    os << r;
    str = os.str();
    break;
  }
  return str;
}

string Card::suitToString(Suit s) {
  string str;
  switch (s) {
  case Spades:
    str = "S";
    break;

  case Clubs:
    str = "C";
    break;

  case Hearts:
    str = "H";
    break;

  case Diamonds:
    str = "D";
    break;
  default:
    str = "Error: Invalid";
  }
  return str;
}

int Card::strToRank(string str) {
  if ((str.length() < 1) || (str.length() > 2)) {
    cout << "Bad Rank!";
    exit(1);
  }
  int r;
  char c = str[0];
  switch (c) {
  case 'A':
    r = 1;
    break;

  case 'Q':
    r = 12;
    break;

  case 'J':
    r = 11;
    break;

  case 'K':
    r = 13;
    break;

  default:
    istringstream is;
    int value = 0;
    is >> value >> ws;
    r = value;
    break;
  }
  return r;
}

Suit Card::strToSuit(string str) {
  Suit s;
  char c = str[0];
  switch (c) {
  case 'S':
    s = Spades;
    break;

  case 'C':
    s = Clubs;
    break;

  case 'H':
    s = Hearts;
    break;

  case 'D':
    s = Diamonds;
    break;
  }
  return s;
}

std::ostream &operator<<(std::ostream &os, Card d) {
  os << d.toString();
  return os;
}

Suit operator++(Suit &s, int) {
  Suit old = s;
  s = Suit(s + 1);
  return old;
}

bool operator==(const Card &card1, const Card &card2) {
  return (card1.suit == card2.suit) && (card1.rank == card2.rank);
}

bool operator!=(const Card &card1, const Card &card2) {
  return !(card1 == card2);
}

bool operator<(const Card &card1, const Card &card2) {
  if (card1.suit == card2.suit)
    return card1.rank < card2.rank;
  else
    return card1.suit < card2.suit;
}

bool operator>(const Card &card1, const Card &card2) {
  if (card1.suit == card2.suit)
    return card1.rank > card2.rank;
  else
    return card1.suit > card2.suit;
}

bool operator<=(const Card &card1, const Card &card2) {
  return !(card1 > card2);
}

bool operator>=(const Card &card1, const Card &card2) {
  return !(card1 < card2);
}
