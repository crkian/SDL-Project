#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include "GameState.h" // include GameState header file
#include "ResourceManager.h"
#include "Dawn.h"
#include "Level.h"
#include "Coin.h"
#include "Font.h"
#include "Wall.h"


class State_Gameplay : public GameState // derive this class from GameState
{
private:

	ResourceManager* rm;

	Dawn dawn; //has been added to the game
	Level* level;


	std::vector<Coin*> coins; //add coins to the game
	std::vector<Wall*> walls; //add walls to the game
	Font* font;

	unsigned int score;

		float blinking;	

public:
	bool Init(Game* game); //Not virtual, do not derive from this class, will need to define function bodies
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};
#endif