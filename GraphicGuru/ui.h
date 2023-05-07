#pragma once
#include <iostream>
#include <vector>
#include "button.h"
#include "textbutton.h"
#include "textmenubutton.h"

using namespace std;

class UI
{
	vector<Button*> _buttons;
public:
	UI(Font& font);
	void draw(RenderWindow& window);
	bool buttonclicked(int& x, int& y);
	void generatefilebtn(Font& font);
};

