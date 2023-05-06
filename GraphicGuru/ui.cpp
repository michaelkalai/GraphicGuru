#include "ui.h"

UI::UI(Font& font)
{
	string text = "File";
	float btnwidth = 60;
	float btnheight = 30;
	cout << "began constructing ui" << endl;
	_buttons.push_back(new TextButton(btnwidth, btnheight, 0, 0, "File", font));
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
		if (_buttons[i]->getbgptr()->getLocalBounds().contains(x, y)) {
			return true;
		}
	}
	return false;
}
