#include "State_Gameplay.h" //include StateGameplay into the mix


/* .cpp translation unit, includes all definitions from stated header file. Not protected by inclusion guards
declare in .h and define in .cpp
*/

// resource manager is a pointer here, passing Game*.Needs to be deleted otherwise added to the memory load. Deconstructor called on delete frees all resources

bool State_Gameplay::Init(Game* game)
{
	/*load all five images*/

	this->game =game; //check points to same address for variable

	rm = new ResourceManager(game);

	try // if image goes wrong try and catch detects it, prints error and exitsprogramme
	{
		rm->loadTexture("Data/character.png");
		rm->loadTexture("Data/map.png");
		rm->loadTexture("Data/font_texture.png");
		rm->loadTexture("Data/item.png");
		rm->loadTexture("Data/wall.png");
	}
	catch(std::runtime_error &e)
	{
		std::cerr<<e.what() << std::endl;
		return false;
	}

	font= new Font(game, rm->getTexture("Data/font_texture.png"),16,16,8,16);

	level=new Level(game, rm);
	level->Init();

	/*called after the textures*/

	dawn.Init(game, rm);

	for(int i=0; i < 30; i++)
	{
		coins.push_back(new Coin());
		coins.back()->Init(game,rm);
	}

	for(int i=0; i < 10; i++)
	{
		walls.push_back(new Wall());
		walls.back()->Init(game,rm);
	}

	score= 0;
	blinking = 0.0f;

	return true;

}

void State_Gameplay::HandleEvents(SDL_Event* event)
{ // terminates if player wants to quit

	if(event->type == SDL_QUIT)
		game->PopState();


}
void State_Gameplay::Update(float deltaTime)
{



	/* keyboard input*/

	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	/* no if else so we can move in a diagonal*/

	if(keyboard[SDL_SCANCODE_RIGHT])
		dawn.Move(1,0);
	if(keyboard[SDL_SCANCODE_LEFT])
		dawn.Move(-1,0);
	if(keyboard[SDL_SCANCODE_UP])
		dawn.Move(0,-1);
	if(keyboard[SDL_SCANCODE_DOWN])
		dawn.Move(0,1);

			if(keyboard[SDL_SCANCODE_SPACE])
		{
			game->PushState(new State_Gameplay());
		}

	/*this causes no delay to the framerate*/
	dawn.Update(deltaTime);



	for(int i=0; i<coins.size(); i++)
	{
		coins[i]->Update(deltaTime);
		if(coins[i]->collidesWith(&dawn))
		{
			coins[i]->Relocate();
			score++;
		}
	}

	for(int i=0; i<walls.size(); i++)
	{
		walls[i]->Update(deltaTime);
		if(walls[i]->collidesWith(&dawn))
		{
			walls[i]->Relocate();
			score=score+2;
		}
	}



	blinking += 2 * deltaTime;
	if(blinking >= 2.0f)
		blinking = 0.0f;

}



void State_Gameplay::Render()
{

	level->Render();

	for(int i=0; i<coins.size(); i++)
	{
		coins[i]->Render();
	}

	for(int i=0; i<walls.size(); i++)
	{
		walls[i]->Render();
	}

	dawn.Render();

	char buffer[64];
	font->RenderString(20, 20, "SCORE: " + std::string(SDL_itoa(score, buffer, 10)));

	if(score >10)
	{

		std::string text = "PRESS SPACEBAR TO RESTART";
		float x = text.length() * 8 / 2;	

		if((int)blinking > 0)
			font->RenderString(320 - x, 350, text);


	}	

}
void State_Gameplay::Quit()
{

	/*remove the coins*/

	for(int i=0; i<coins.size(); i++)
	{
		delete coins[i];
	}
	coins.clear();

	for(int i=0; i<walls.size(); i++)
	{
		delete walls[i];
	}
	walls.clear();
	delete font;
	delete level;
	delete rm;

}