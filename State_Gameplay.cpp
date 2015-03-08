#include "State_Gameplay.h" //include StateGameplay into the mix


/* .cpp translation unit, includes all definitions from stated header file. Not protected by inclusion guards
declare in .h and define in .cpp
*/

// resource manager is a pointer here, passing Game*.Needs to be deleted otherwise added to the memory load. Deconstructor called on delete frees all resources

bool State_Gameplay::Init(Game* game)
{
	//load all four images

	this->game =game; //check points to same address for variable

	rm = new ResourceManager(game);

	try // if image goes wrong try and catch detects it, prints error and exitsprogramme
	{
		rm->loadTexture("images/character.png");
		rm->loadTexture("images/tile_01.png");
		rm->loadTexture("images/font_texture.png");
		rm->loadTexture("images/item.png");
	}
	catch(std::runtime_error &e)
	{
		std::cerr<<e.what()<< std::endl;
		return false;
	}

	//this is the pointer return for the test

	test_tex=rm->getTexture("images/character.png");
	
	//called after the textures

	dawn.Init(game, rm);
	
	return true;

}

void State_Gameplay::HandleEvents(SDL_Event* event)
{ // terminates if player wants to quit

	if(event->type == SDL_QUIT)
		game->PopState();


}
void State_Gameplay::Update(float deltaTime)
{
	// keyboard input

	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

// no if else so we can move in a diagonal

	if(keyboard[SDL_SCANCODE_RIGHT])
		dawn.Move(1,0);
	if(keyboard[SDL_SCANCODE_LEFT])
		dawn.Move(-1,0);
	if(keyboard[SDL_SCANCODE_UP])
		dawn.Move(0,-1);
	if(keyboard[SDL_SCANCODE_DOWN])
		dawn.Move(0,1);


	//this causes no delay to the framerate
	dawn.Update(deltaTime);
}
void State_Gameplay::Render()
{
	SDL_Rect dst;
	dst.x=32;
	dst.y=32;
	dst.w=64;
	dst.h=128;

	SDL_RenderCopy(game->getRenderer(), test_tex, NULL, &dst);

	dawn.Render();
}
void State_Gameplay::Quit()
{
	delete rm; //deletes the resource manager
}