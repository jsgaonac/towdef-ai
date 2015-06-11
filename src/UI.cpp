#include "UI.hpp"

ui::UI::UI()
{
	loopMethod = nullptr;
	geneticPtr = nullptr;
}

void ui::UI::setGameLoop(gameMethodPtr loopMethod)
{
	this->loopMethod = loopMethod;
}

void ui::UI::setGenetic(ai::Genetic *genetic)
{
	geneticPtr = genetic;
}

ui::UI::~UI()
{
	// Do nothing.
}