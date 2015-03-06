#include "State_Gameplay.h" //include StateGameplay into the mix


/* .cpp translation unit, includes all definitions from stated header file. Not protected by inclusion guards
declare in .h and define in .cpp
*/
bool State_Gameplay::Init(Game* game)
{
	this->game =game; //check points to same address for variable
	return true;
}
void State_Gameplay::HandleEvents(SDL_Event* event)
{ // terminates if player wants to quit

	if(event->type == SDL_QUIT)
		game->PopState();


}
void State_Gameplay::Update(float deltaTime)
{
}
void State_Gameplay::Render()
{
}
void State_Gameplay::Quit()
{
}