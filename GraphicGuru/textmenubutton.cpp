#include "textmenubutton.h"


TextMenuButton::TextMenuButton(FunctionHandler* funch, void(FunctionHandler::* funcptr)(UI*), UI* ui, float& btnwidth, float& btnheight, float btnx, float btny, string btntext, Font& font) : TextButton(funch, funcptr, ui, btnwidth, btnheight, btnx, btny, btntext, font)
{
	;
}

bool TextMenuButton::wasclicked(int& x, int& y)
{
	return MenuButton::wasclicked(x, y);
}

// draws button and draws menu if the menu display is enabled
void TextMenuButton::draw(RenderWindow& window)
{
	TextButton::draw(window);
	if (_displaymenu) {
		MenuButton::drawmenu(window);
	}
}
