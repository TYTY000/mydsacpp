#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <regex>
#include <string>

extern const int MAX_SUIT;
extern const int MAX_RANK;
extern const int ACE;
extern const int JACK;
extern const int QUEEN;
extern const int KING;

enum Suit {
  None,
  Spades,
  Hearts,
  Clubs,
  Diamonds,
};

class Card {
private:
  int rank;
  Suit suit;
  std::string rankToString(int r);
  std::string suitToString(Suit s);
  int strToRank(std::string r);
  Suit strToSuit(std::string s);

public:
  Card();
  Card(std::string str);
  Card(int rank, Suit suit);
  Card &operator=(Card &&) = default;
  Card &operator=(const Card &) = default;
  int getRank();
  Suit getSuit();
  std::string toString();
  ~Card();

  friend bool operator==(const Card &str1, const Card &str2);
  friend bool operator!=(const Card &str1, const Card &str2);
  friend bool operator<=(const Card &str1, const Card &str2);
  friend bool operator>=(const Card &str1, const Card &str2);
  friend bool operator>(const Card &str1, const Card &str2);
  friend bool operator<(const Card &str1, const Card &str2);
};

std::ostream &operator<<(std::ostream &os, Card d);
Suit operator++(Suit &s, int);

#endif
