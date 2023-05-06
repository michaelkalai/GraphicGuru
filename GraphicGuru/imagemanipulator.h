#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <String>
#include <algorithm>
using namespace sf;
using namespace std;
class ImageManipulator
{
	Image _img;
	Texture _imgtext;
	Sprite _imgsprite;
	int _imgwidth;
	int _imgheight;
	float _winwidth;
	float _winheight;
	float _scalex;
	float _scaley;

public:
	ImageManipulator(string& filename);
	void draw(RenderWindow& window);
	void colorpixels(int& initialx, int& initialy, int xcoord, int ycoord, Color& color);
	void savefile();
};

