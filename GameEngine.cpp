#include "GameEngine.h"

GameEngine* GameEngine::gameEngine_Ptr = nullptr;
int GameEngine::round = 1;

//GameEngine::GameEngine() 
//  : map{ Map() }, playerList{}, currPlayer{nullptr},
//  winner{ nullptr }, maxScore{0}
//{
//
//}


GameEngine::GameEngine() : winner{ NULL }
{

    int gameMode = 0;
    cout << "\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t" << endl;
    cout << "\t\t\t**********************************" << endl;
    //cout << "Main Menu:" << endl;
    //cout << "1 - Singleplayer" << endl;
    //cout << "1 - Multiplayer" << endl;
    string player1Name = "Player 1";
    string player2Name = "Player 2";
    int randVal = 0;
    /*switch (gameMode)
    {
    case 1:
      playerList[0] = Player("CPU", 'X');
      cout << "Enter Player Name: ";
      cin >> player1Name;
      playerList[1] = Player(player1Name, 'O');
      mode = SP;
      break;
    case 2:
      srand(time(0));
      randVal = (rand() % (2 - 1 + 1)) + 1;
      cout << "Enter Player 1 Name: ";
      cin >> player1Name;
      cout << "Enter Player 2 Name: ";
      cin >> player2Name;
      switch (randVal)
      {
      case 1:
        playerList[0] = Player(player1Name, 'X');
        playerList[1] = Player(player2Name, 'O');
        break;
      case 2:
        playerList[0] = Player(player1Name, 'O');
        playerList[1] = Player(player2Name, 'X');
        break;
      }
      mode = MP;
      break;
    }*/
    srand(time(0));
    randVal = (rand() % (2 - 1 + 1)) + 1;
    cout << "Enter Player 1 Name: ";
    cin >> player1Name;
    cout << "Enter Player 2 Name: ";
    cin >> player2Name;
    switch (randVal)
    {
    case 1:
        playerList[0] = Player(player1Name, 'X');
        playerList[1] = Player(player2Name, 'O');
        break;
    case 2:
        playerList[0] = Player(player1Name, 'O');
        playerList[1] = Player(player2Name, 'X');
        break;
    }
    mode = MP;
    cout << "***********************************" << endl;

    while (maxScore == 0 || maxScore > 10)
    {
        cout << "Set Maximum Score: ";
        cin >> maxScore;
        cout << "Invalid Max score. Enter Score between 1 and 10" << endl;
    }

    cout << "***********************************" << endl;


    cout << playerList[0] << "\n" << "------------------\n" << playerList[1] << endl;
    cout << "***********************************" << endl;
    cout <<
        "     |     |     \n"
        << "  " << "1" << "  |  " << "2" << "  |  " << "3" << " \n"
        << "_____|_____|_____\n"
        << "     |     |     \n"
        << "  " << "4" << "  |  " << "5" << "  |  " << "6" << " \n"
        << "_____|_____|_____\n"
        << "     |     |     \n"
        << "  " << "7" << "  |  " << "8" << "  |  " << "9" << " \n"
        << "     |     |     " << endl;

    cout << "***********************************" << endl;
    if (playerList[0].getSymbol() == 'X')
        currPlayer = playerList;
    else
        currPlayer = playerList + 1;

    map = Map();

}



void GameEngine::StartNewGame()
{
    int gameMode = 0;
    cout << "\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t" << endl;
    cout << "\t\t\t**********************************" << endl;
    cout << "Main Menu:" << endl;
    // cout << "1 - Singleplayer" << endl;
    cout << "1 - Multiplayer Local" << endl;

    while (gameMode != 1)
        cin >> gameMode;

}
void GameEngine::printMap() const
{
    cout << map << endl;
}

void GameEngine::showPlayerScores() const
{
    cout << playerList[0] << endl;
    cout << "***********************************" << endl;
    cout << playerList[1] << endl;
}

void GameEngine::startRound()
{
    cout << "Round " << round << ":" << endl;
    cout << currPlayer->getName() << " starts" << endl;
    cout << "***********************************" << endl;
    printMap();
    cout << "***********************************" << endl;
}

ErrorType GameEngine::playerInput(Player* currPlayer, int pos)
{
    if (pos >= 1 || pos <= 9)
    {
        if (map.getPos(pos) == ' ')
            return NoErr;
        else
            return invalid;
    }
    else
        return out_of_bound;
}

void GameEngine::terminateRound(Player* winner)
{
    if (winner != NULL)
    {
        winner->incrementScore();
        cout << winner->getName() << " Won this round!" << endl;
    }
    else
    {
        cout << "This Round is a draw!" << endl;
    }

    ++round;

    playerList[0].toggleSymbol();
    playerList[1].toggleSymbol();

    if (playerList[0].getSymbol() == 'X')
        currPlayer = playerList;
    else
        currPlayer = playerList + 1;

    map.resetMap();

}

RoundStatus GameEngine::checkWinner()
{
    if (map.checkColumnComplete('O') || map.checkRowsComplete('O') || map.checkDiagonalComplete('O'))
    {
        if (playerList[0].getSymbol() == 'O')
            winner = &(playerList[0]);
        else
            winner = &(playerList[1]);

        return Win;
    }
    else if (map.checkColumnComplete('X') || map.checkRowsComplete('X') || map.checkDiagonalComplete('X'))
    {
        if (playerList[0].getSymbol() == 'X')
            winner = &(playerList[0]);
        else
            winner = &(playerList[1]);

        return Win;
    }
    else if (!map.checkEmptyCell())
        return Draw;
    else
        return Pass;
}

bool GameEngine::maxScoreReached()
{
    if (playerList[0].getScore() >= maxScore ||
        playerList[1].getScore() >= maxScore)
    {
        return true;
    }
    else
        return false;
}

void GameEngine::terminateGame()
{
    if (playerList[0].getScore() > playerList[1].getScore())
    {
        cout << "!!!" << playerList[0].getName() << " is WINNER !!!" << endl;
    }
    else
        cout << "!!! " << playerList[1].getName() << " is WINNER !!!" << endl;
}

Player* GameEngine::getCurrentPlayer() const
{
    return this->currPlayer;
}

void GameEngine::switchCurrentPlayer()
{
    if (*currPlayer == playerList[0])
        currPlayer = playerList + 1;
    else
        currPlayer = playerList;
}

Player* GameEngine::getWinner()
{
    return this->winner;
}

void GameEngine::setWinner(Player winner)
{
    this->winner = &winner;
}

void GameEngine::resetWinner()
{
    this->winner = NULL;
}

void GameEngine::setMap(const Player* curr, const int pos)
{
    map.updateMap(pos, curr->getSymbol());
}

GameEngine* GameEngine::getInstance()
{
    if (gameEngine_Ptr == NULL)
    {
        gameEngine_Ptr = new GameEngine();
        return gameEngine_Ptr;
    }
    else
        return gameEngine_Ptr;
}

GameEngine::~GameEngine()
{
    delete gameEngine_Ptr;
    gameEngine_Ptr = NULL;
}