#include "button.h"

Button::Button()
{
	;
}

void Button::generatebg()
{
	_btnbg.setPosition(_btnx, _btny);
	_btnbg.setSize(Vector2f(_btnwidth, _btnheight));
	_btnbg.setFillColor(Color(105, 95, 135, 100));
	_btnbg.setOutlineColor(Color(50, 50, 50));
	_btnbg.setOutlineThickness(5);
}

float Button::getbtny()
{
	return _btny;
}

float Button::getbtnheight()
{
	return _btnheight;
}

bool Button::wasclicked(int& x, int& y)
{
	return _btnbg.getGlobalBounds().contains(x, y);
}

RectangleShape* Button::getbgptr()
{
	return &_btnbg;
}
