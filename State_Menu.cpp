#include "State_Menu.h"
#include "State_Gameplay.h"

bool State_Menu::Init(Game* game)
{
	this->game = game;

	rm = new ResourceManager(game);

	try
	{		
		rm->loadTexture("font_texture.png");		
	}
	catch(std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}

	font = new Font(game, rm->getTexture("font_texture.png"), 16, 16, 8, 16);	

	blinking = 0.0f;

	return true;
}
void State_Menu::HandleEvents(SDL_Event* event)
{
	if(event->type == SDL_QUIT)
		game->PopState();	
}
void State_Menu::Update(float deltaTime)
{
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	if(keyboard[SDL_SCANCODE_SPACE])
	{
		game->PushState(new State_Gameplay());		
	}	

	blinking += 2 * deltaTime;
	if(blinking >= 2.0f)
		blinking = 0.0f;
}
void State_Menu::Render()
{	
	std::string text = "PRESS SPACEBAR TO START";
	float x = text.length() * 8 / 2;	

	if((int)blinking > 0)
		font->RenderString(160 - x, 140, text);

	text = "T H E   C O I N   C O L L E C T O R";
	x = text.length() * 8 / 2;	

	font->RenderString(160 - x, 32, text);
}
void State_Menu::Quit()
{
	delete font;
	delete rm;
}