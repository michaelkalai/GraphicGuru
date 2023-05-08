#include "button.h"

Button::Button()
{
	;
}

// generates button background
void Button::generatebg()
{
	_btnbg.setPosition(_btnx, _btny);
	_btnbg.setSize(Vector2f(_btnwidth, _btnheight));
	_btnbg.setFillColor(Color(105, 95, 135, 100));
	_btnbg.setOutlineColor(Color(50, 50, 50));
	_btnbg.setOutlineThickness(5);
}

// gets vertical position of button
float Button::getbtny()
{
	return _btny;
}

// gets button height
float Button::getbtnheight()
{
	return _btnheight;
}

// checks to see if button was clicked and enacts button functionality
bool Button::wasclicked(int& x, int& y)
{
	if (_btnbg.getGlobalBounds().contains(x, y)) {
		enactfunction();
		return true;
	}
	return false;
}

// returns pointer to button background
RectangleShape* Button::getbgptr()
{
	return &_btnbg;
}

// enacts buttion functionality based on passed in function at button construction
void Button::enactfunction()
{
	if (_funcptr == nullptr) {
		cout << "nullptr" << endl;
	}
	else {
		(_funch->*_funcptr)(_ui);
	}
}
