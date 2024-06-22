#pragma once

#include "I_Printable.h"

#include <string>
using std::string;

#include <iostream>

class Player : public I_Printable
{

private:
  string name;
  unsigned int score;
  char symbol;
  static unsigned int p_count;

public:
  Player();
  Player(string name, char sym);

  Player(const Player& player);
  Player(Player&& player)=default;

  Player& operator=(const Player& player) = default;
  Player& operator=(Player&& player) = default;

  bool operator==(const Player & player);

  virtual void print(std::ostream& os) const override;
  
  string getName() const;
  void setName(string name);
  
  unsigned int getScore() const;
  void incrementScore();

  char getSymbol() const;
  void toggleSymbol();

  virtual ~Player();


};

