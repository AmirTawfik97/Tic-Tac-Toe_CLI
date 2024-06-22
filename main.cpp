#include "GameEngine.h"
#include "ErrorTypes.h"


int main()
{
  /*
  * Start A new Game
  * Instantiate a new GameEngine
  */

  GameEngine* game = GameEngine::getInstance();
 // try
 // {
	//game->StartNewGame();
 // }
 // catch (const InvalidInputException& ex)
 // {
	//std::cout << ex.what() << ": Select 1";
 // }
  
  int pos = 0;
  ErrorType inputStatus;
  
  /* Game Super Loop */
  for (;;)
  {
	
	game->startRound();
	game->resetWinner();
	/* Round Super Loop */
	for (;;)
	{
	  do
	  {
		cout << game->getCurrentPlayer()->getName() << "'s imput: ";
		cin >> pos;
		inputStatus = game->playerInput(game->getCurrentPlayer(), pos);
		switch (inputStatus)
		{
		case NoErr:
		  game->setMap(game->getCurrentPlayer(), pos);
		  break;
		case invalid:
		  cout << "This position is already occupied" << endl;
		  break;
		case out_of_bound:
		  cout << "Input is outside" << endl;
		  break;
		}
	  } while (inputStatus != 0);

	  cout << "***********************************" << endl;
	  game->printMap();
	  cout << "***********************************" << endl;
	  game->switchCurrentPlayer();

	  if (game->checkWinner() == Win)
	  {
		game->terminateRound(game->getWinner());
		cout << "***********************************" << endl;
		break;
	  }
	  else if (game->checkWinner() == Draw)
	  {
		game->terminateRound();
		cout << "***********************************" << endl;
		break;
	  }
	  else
	  {
		// game->checkWinner() returns Pass
		// Keep the round going
	  }
	  
	}
	game->showPlayerScores();
	cout << "***********************************" << endl;
	if (game->maxScoreReached())
	{
	  game->terminateGame();
	  break;
	}
	else
	  continue;
  }

  



  char terminate{ '_' };
  cout << "Thank You for Playing !\nPress any key to terminate...";
  cin >> terminate;





  return 0;
}