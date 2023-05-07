#pragma once
#include "button.h"
#include <iostream>

using namespace std;
class MenuButton : virtual public Button
{
protected:
	vector<Button*> _menu;
	bool _displaymenu;
public:
	MenuButton();
	void drawmenu(RenderWindow& window);
	bool wasclicked(int& x, int& y);
	void addbutton(Button* btnptr);
	void alignmenu();
};

