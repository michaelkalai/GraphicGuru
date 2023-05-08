#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <String>
#include "forward.h"


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
	UI* _ui;
	void(FunctionHandler::* _funcptr)(UI*);
	FunctionHandler * _funch;
public:
	Button();
	void generatebg();
	virtual void draw(RenderWindow& window) = 0;
	virtual void setbtny(float y) = 0;
	virtual void movebutton() = 0;
	float getbtny();
	float getbtnheight();
	virtual bool wasclicked(int& x, int& y);
	RectangleShape* getbgptr();
	virtual void enactfunction();
};

