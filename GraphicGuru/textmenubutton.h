#pragma once
#include "menubutton.h"
#include "textbutton.h"

class TextMenuButton : public MenuButton, public TextButton
{
public:
	TextMenuButton(FunctionHandler* funch, void(FunctionHandler::* funcptr)(UI*), UI* ui, float& btnwidth, float& btnheight, float btnx, float btny, string btntext, Font& font);
	bool wasclicked(int& x, int& y);
	void draw(RenderWindow& window);
};

