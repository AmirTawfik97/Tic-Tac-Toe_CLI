#pragma once

//#include <vector>
//using std::vector;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <time.h>

#include "Map.h"
#include "Player.h"

#include "ErrorTypes.h"
#include "GameMode.h"
#include "RoundStatus.h"



class GameEngine
{

private:
  Map map;
  Player playerList[2];
  Player* currPlayer;
  Player* winner;
  static int round;
  unsigned int maxScore = 0;
  GameMode mode;
  // Singleton Class
  static GameEngine* gameEngine_Ptr;
  GameEngine();

  
public:
  
  static GameEngine* getInstance();
  GameEngine(const GameEngine& GEngine) = delete;

  // Game Engine Functions
  
  void StartNewGame();
  void showPlayerScores() const;
  void printMap() const;
  void startRound();
  ErrorType playerInput(Player* currPlayer, int pos);
  RoundStatus checkWinner();
  bool maxScoreReached();
  void terminateRound(Player* winner = NULL);
  void terminateGame();
  
  Player* getCurrentPlayer() const;
  void switchCurrentPlayer();
  Player* getWinner();
  void setWinner(Player winner);
  void resetWinner();
  void setMap(const Player* curr ,const int pos);


  virtual ~GameEngine();

};

