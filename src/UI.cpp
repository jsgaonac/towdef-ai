#include "UI.hpp"

ui::UI::UI()
{
	loopMethod = nullptr;
}

void ui::UI::setGameLoop(gameMethodPtr loopMethod)
{
	this->loopMethod = loopMethod;
}

ui::UI::~UI()
{
	// Do nothing.
}