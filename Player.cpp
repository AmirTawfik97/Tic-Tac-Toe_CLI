#include "Player.h"

unsigned int Player::p_count = 0;

Player::Player() : score{ 0 }
{
  if (p_count == 0)
  {
	this->name = "Player 1";
	this->symbol = 'X';
  }
  else
  {
	this->name = "Player 2";
	this->symbol = 'O';
  }
  ++p_count;
}

Player::Player(string name, char sym) : name{ name }, score{ 0 }, symbol{sym}
{
  ++p_count;
}

Player::Player(const Player& player)
  : name{ player.name }, score{ player.score }, symbol{ player.symbol }
{
}



bool Player::operator==(const Player& player)
{
  if (name == player.name &&
	symbol == player.symbol &&
	score == player.score)
	return true;
  else
	return false;
}

void Player::print(std::ostream& os) const
{
  os << "Player Name: " << this->name <<"[" << this->symbol << "]" << "\n" << "Player Score: " << this->score;
}

string Player::getName() const
{
  return this->name;
}

void Player::setName(string name)
{
  this->name = name;
}

unsigned int Player::getScore() const
{
  return this->score;
}

void Player::incrementScore()
{
  ++(this->score);
}

char Player::getSymbol() const
{
  return symbol;
}

void Player::toggleSymbol()
{
  if (this->symbol == 'X')
	this->symbol = 'O';
  else
	this->symbol = 'X';
}

Player::~Player() { --p_count; }