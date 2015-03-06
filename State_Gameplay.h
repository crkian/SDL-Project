#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include"GameState.h" // include GameState header file

class State_Gameplay : public GameState // derive this class from GameState
{
private:
public:
	bool Init(Game* game); //Not virtual, do not derive from this class, will need to define function bodies
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};
#endif