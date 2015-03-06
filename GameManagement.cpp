#include "Game.h"
#include "GameState.h"

void Game::PushState(GameState* state)
	// sets state totop of stack, if it goes wrong quit flag=true
{
	states.push_back(state);
if(state->Init(this)==false)
{
	quit=true;
}
}

//now the reverse, if last state popped continue quit

void Game::PopState()
{
	states.back()->Quit();
	delete states.back();
	states.pop_back();

	if (states.size()==0)
	{
		quit = true;
	}
}

