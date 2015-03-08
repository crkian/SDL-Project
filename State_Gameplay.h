#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include"GameState.h" // include GameState header file
#include "ResourceManager.h"
#include "Dawn.h"

class State_Gameplay : public GameState // derive this class from GameState
{
private:

	ResourceManager* rm;
	SDL_Texture* test_tex; //pointer to SDL Texture

	Dawn dawn; //has been added to the game
public:
	bool Init(Game* game); //Not virtual, do not derive from this class, will need to define function bodies
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};
#endif