#include "ui.h"

UI::UI(Font& font)
{
	generatefilebtn(font);
}

void UI::draw(RenderWindow& window)
{
	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->draw(window);
	}
}

bool UI::buttonclicked(int& x, int& y)
{
	for (int i = 0; i < _buttons.size(); i++) {
		if (_buttons[i]->wasclicked(x, y)) {
			return true;
		}
	}
	return false;
}

void UI::generatefilebtn(Font& font)
{
	string text = "File";
	float btnwidth = 100;
	float btnheight = 50;
	TextMenuButton* btnptr = new TextMenuButton(btnwidth, btnheight, 0, 0, "File", font);
	btnptr->addbutton(new TextMenuButton(btnwidth, btnheight, 0, 0, "M1BTN", font));
	btnptr->alignmenu();
	_buttons.push_back(btnptr);
}
