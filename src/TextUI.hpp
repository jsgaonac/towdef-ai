#ifndef _TEXT_UI_HPP
#define _TEXT_UI_HPP

#include "UI.hpp"
#include "Genetic.hpp"

namespace ui
{
	class TextUI;
}

class ui::TextUI : public ui::UI
{
	//Private
	

public:

	TextUI();

	void create(int w, int h, int bpp = 32) override;

	void show(logic::Game* gameInstance) override;

	double showGeneticStats() override;
};


#endif