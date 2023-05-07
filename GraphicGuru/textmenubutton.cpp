#include "textmenubutton.h"

TextMenuButton::TextMenuButton(float& btnwidth, float& btnheight, float btnx, float btny, string btntext, Font& font) : TextButton(btnwidth, btnheight, btnx, btny, btntext, font)
{
	;
}

bool TextMenuButton::wasclicked(int& x, int& y)
{
	return MenuButton::wasclicked(x, y);
}

void TextMenuButton::draw(RenderWindow& window)
{
	TextButton::draw(window);
	if (_displaymenu) {
		MenuButton::drawmenu(window);
	}
}
