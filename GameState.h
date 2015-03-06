#ifndef GAME_STATE_H // inclusion quards stop gamestate being included more than once
#define GAME_STATE_H

#include "Game.h"

class GameState
{
protected:
	Game* game;

public:
	virtual bool Init(Game* game)=0; //virtual means if another class inherits gamestate they overide parent classes
	virtual void HandleEvents(SDL_Event* event) = 0; // ending with 0 means abstract, cannot be instantiated
	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;
	virtual void Quit()=0;
};
#endif