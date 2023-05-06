#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <String>

using namespace sf;
using namespace std;

class Button
{
protected:
	RectangleShape _btnbg;
	float _btnwidth;
	float _btnheight;
	float _btnx;
	float _btny;
public:
	Button();
	void generatebg();
	virtual void draw(RenderWindow& window) = 0;
	RectangleShape* getbgptr();
};

