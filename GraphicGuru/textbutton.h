#pragma once
#include "button.h"
class TextButton : virtual public Button
{
protected:
	Text _btntext;
	void centertext();
public:
	TextButton(float& btnwidth, float& btnheight, float btnx, float btny, string btntext, Font& font);
	void draw(RenderWindow& window);
	void movebutton();
	void setbtny(float btny);
};

