#include "menubutton.h"

// defaults menu display to off
MenuButton::MenuButton()
{
	_displaymenu = false;
}

// draws each button in the menu
void MenuButton::drawmenu(RenderWindow& window)
{
	for (int i = 0; i < _menu.size(); i++) {
		_menu[i]->draw(window);
	}
}

// checks to see if any of the displayed buttons were clicked
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

// adds button to menu
void MenuButton::addbutton(Button* btnptr)
{
	_menu.push_back(btnptr);
}

// moves buttons to their correct positions
void MenuButton::alignmenu()
{
	Button* btnptr;
	for (int i = 1; i < _menu.size() + 1; i++) {
		btnptr = _menu[i - 1];
		btnptr->setbtny(btnptr->getbtny() + (btnptr->getbtnheight() * i));
		btnptr->movebutton();
	}
}

// enables/disables menu display
void MenuButton::enactfunction()
{
	_displaymenu = !_displaymenu;
}
