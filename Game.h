#ifndef GAME_H
#define GAME_H

// Will be used in GameState.h and cant include in both due to infinate recursion
// Just declaration here
#include <SDL.h>
#include <vector>

class GameState;

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;


	// now include window incase we use window elsewhere in the programme

	int screen_width;
	int screen_height;

	//for terminating the programme

	bool quit;

	//This is for the stack

	std::vector<GameState*>states;

	//Calculate time

	Uint32 new_time;
	Uint32 old_time;

public:
	Game(); //Default values

	bool Init(GameState* state);
	void Thread(); 
	//start the main thread and loop till quit

private:

	//loop functions
	void Update();
	void Render();

	void Quit(); //free resources and clean up


	//State management
public:
	void PushState(GameState* state);
	void PopState(); //pop check last state and not take
	
	
	void setQuit(); //will quit whatever

	//renderer used more than once  so use a get function
	SDL_Renderer* getRenderer();
};

#endif