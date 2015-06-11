#include "TextUI.hpp"
#include "defines.hpp"

#include <iostream>

ui::TextUI::TextUI()
{
	
}

void ui::TextUI::create(int w, int h, int bpp)
{
	// Do nothing.
}

void ui::TextUI::show(logic::Game* gameInstance)
{
	// Run the game loop until the game is over.
	while ((gameInstance->*loopMethod)())
	{}
}
