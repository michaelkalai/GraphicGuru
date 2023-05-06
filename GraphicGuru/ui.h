#pragma once
#include <iostream>
#include <vector>
#include "button.h"
#include "textbutton.h"

using namespace std;

class UI
{
	vector<Button*> _buttons;
public:
	UI(Font& font);
	void draw(RenderWindow& window);
	bool buttonclicked(int& x, int& y);
};

