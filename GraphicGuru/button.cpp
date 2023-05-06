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

RectangleShape* Button::getbgptr()
{
	return &_btnbg;
}
