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

	font= new Font(game, rm->getTexture("font_texture.png"),16,16,8,16);




	level=new Level(game, rm);
	level->Init();

		//called after the textures

	dawn.Init(game, rm);
	
	for(size_t i=0; i < 10; i++)
	{
		coins.push_back(new Coin());
		coins.back()->Init(game,rm);
	}

	score= 0;

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

	for(size_t i=0; i < coins.size(); i++)
	{
		coins[i]->Update(deltaTime);
		if(coins[i]->collidesWith(&dawn))
		{
			coins[i]->Relocate();
			score++;
		}
	}

}
void State_Gameplay::Render()
{

	level->Render();

		for(size_t i=0; i < coins.size(); i++)
	{
		coins[i]->Render();
	}

	dawn.Render();



}
void State_Gameplay::Quit()
{
	delete rm; //deletes the resource manager

//remove the coins

	for(size_t i=0; i<coins.size(); i++)
	{
		delete coins[i];
	}
	coins.clear();
	delete font;
	delete level;
delete rm;

}