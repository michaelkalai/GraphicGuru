#include "textbutton.h"

// centers the text within the text rectangle
void TextButton::centertext()
{
	FloatRect textRect = _btntext.getLocalBounds();
	_btntext.setOrigin(textRect.left + textRect.width / 2.0f,
	textRect.top + textRect.height / 2.0f);
	_btntext.setPosition(Vector2f(_btnx + (_btnwidth / 2), _btny + (_btnheight / 2)));
}

// constructs button and text
TextButton::TextButton(FunctionHandler* funch, void(FunctionHandler::* funcptr)(UI*), UI* ui, float& btnwidth, float& btnheight, float btnx, float btny, string btntext, Font& font)
{
	_funch = funch;
	_ui = ui;
	_funcptr = funcptr;
	_btnwidth = btnwidth;
	_btnheight = btnheight;
	_btnx = btnx;
	_btny = btny;
	_btntext.setString(btntext);
	_btntext.setPosition(Vector2f(_btnx, _btny));
	generatebg();
	_btntext.setFont(font);
	_btntext.setCharacterSize(20);
	_btntext.setLetterSpacing(2);
	centertext();
}

// draws button
void TextButton::draw(RenderWindow& window)
{
	window.draw(_btnbg);
	window.draw(_btntext);
}

// moves button to new position
void TextButton::movebutton()
{
	_btnbg.setPosition(Vector2f(_btnx, _btny));
	_btntext.setPosition(Vector2f(_btnx, _btny));
	centertext();
}

// changes the button's associated y value
void TextButton::setbtny(float btny)
{
	_btny = btny;
}
