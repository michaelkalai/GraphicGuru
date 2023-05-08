#pragma once
#include <iostream>
#include <vector>
#include "forward.h"
#include "button.h"
#include "textbutton.h"
#include "textmenubutton.h"
#include "imagemanipulator.h"
#include "functionhandler.h"

using namespace std;

class UI
{
	vector<Button*> _buttons;
	vector<ImageManipulator*> _images;
	ImageManipulator* _selimage;
	FunctionHandler* _funch;
public:
	UI(Font& font);
	void draw(RenderWindow& window);
	bool buttonclicked(int& x, int& y);
	void generatefilebtn(Font& font);
	void addimage();
	bool imageclicked(int& x, int& y);
	ImageManipulator* getselimageptr();
};

