#include "Game.h"
#include "State_Gameplay.h"
#include "State_Menu.h"

int main(int argc, char** args)
{
	Game g;
	//creates state gameplay and sends it to init function, else terminates
	if(g.Init(new State_Gameplay()))
		g.Thread();

	return 0;
}