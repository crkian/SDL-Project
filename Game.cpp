#include "Game.h"
#include "GameState.h"

#include <iostream>
#include <time.h>

Game::Game()
{
	window = NULL;
	renderer=NULL;

	screen_width=320;
	screen_height=340;

	old_time=0;
	quit=false;
}

bool Game::Init(GameState* state)
{ 
	/* Calls and starts SDL, system could fail so need failsafes*/
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}
	/* incase of window fail log error and exit*/
	window = SDL_CreateWindow("Blaster", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if(window==NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}
	/* same with renderer incase of fail, log error and exit*/
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer==NULL)
	{
		std::cerr << SDL_GetError() << std::endl;// cerr is better for logging errors of cout, seperates from standard output
		return false;
	}

	srand(time(NULL)); //random number generator

	PushState(state);

	return true;
}

void Game::Thread() //check stackempty and does updating
{
	while(quit==false)
	{
		Update();
		Render();
	}
	Quit();
}

/* Update function, checks the stack and updates it*/

void Game::Update()
{
	/*check events queue and go process particular states*/

	while(SDL_PollEvent(&event))
	{
		if(states.size() > 0)
			states.back()->HandleEvents(&event);
	}

	/*Check to see if stack is empty asit might stillhold events*/

	if(states.size() > 0)
	{
		old_time = new_time;
		new_time = SDL_GetTicks();

		if(new_time > old_time)
		{
			float deltaTime = (float)(new_time - old_time) / 1000.0f;
			states.back()->Update(deltaTime);
		}
	}
}

/* Render function for the SDL stuff*/

void Game::Render()
{
	/* clear buffer back*/
	SDL_RenderClear(renderer);

	/*render onto buffer back*/
	if(states.size() > 0)
		states.back()->Render();

	/*switch buffers*/

	SDL_RenderPresent(renderer);
}

void Game::Quit()
{
	/* As mentioned before if quit is called states on stack might need removing*/
	while(states.size() > 0);
	/* delete the space used*/
	{
		states.back()->Quit();
		delete states.back();
		states.pop_back();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::setQuit()
{
	quit=true;
}
SDL_Renderer* Game::getRenderer()
{
	return renderer;
}