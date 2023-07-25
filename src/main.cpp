#include "PCH.h"

#include <SDL2/SDL.h>

using namespace VL::Display;

int main() 
{
	
	Window window = Window("VL", 640, 480);
	
	//Hack to get window to stay up
	SDL_Event e; 
	bool quit = false; 
	while(quit == false)
	{
		while(SDL_PollEvent(&e))
		{ 
			if( e.type == SDL_QUIT ) quit = true;
		}
	}
}