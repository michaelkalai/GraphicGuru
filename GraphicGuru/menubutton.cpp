#include "menubutton.h"

MenuButton::MenuButton()
{
	_displaymenu = true;
}

void MenuButton::drawmenu(RenderWindow& window)
{
	for (int i = 0; i < _menu.size(); i++) {
		_menu[i]->draw(window);
	}
}

bool MenuButton::wasclicked(int& x, int& y)
{
	if (Button::wasclicked(x, y)) {
		return true;
	}
	else if (_displaymenu) {
		for (int i = 0; i < _menu.size(); i++) {
			if (_menu[i]->wasclicked(x, y)) {
				return true;
			}
		}
	}
	return false;
}

void MenuButton::addbutton(Button* btnptr)
{
	_menu.push_back(btnptr);
}

void MenuButton::alignmenu()
{
	Button* btnptr;
	for (int i = 1; i < _menu.size() + 1; i++) {
		btnptr = _menu[i - 1];
		btnptr->setbtny(btnptr->getbtny() + (btnptr->getbtnheight() * i));
		btnptr->movebutton();
	}
}
