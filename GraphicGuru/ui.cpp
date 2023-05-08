#include "ui.h"

// constructs buttons and adds a basic image (for testing)
UI::UI(Font& font)
{
	generatefilebtn(font);
	addimage();
}

// draws all buttons and the selected image
void UI::draw(RenderWindow& window)
{
	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->draw(window);
	}
	_selimage->draw(window);
}

// returns true if mouse position is within a button when clicked
bool UI::buttonclicked(int& x, int& y)
{
	for (int i = 0; i < _buttons.size(); i++) {
		if (_buttons[i]->wasclicked(x, y)) {
			return true;
		}
	}
	return false;
}

// generates file drop down button and buttons within it
void UI::generatefilebtn(Font& font)
{
	UI* ui = &*this;
	string text = "File";
	float btnwidth = 100;
	float btnheight = 50;
	TextMenuButton* btnptr = new TextMenuButton(nullptr, nullptr, ui, btnwidth, btnheight, 0, 0, "File", font);
	btnptr->addbutton(new TextButton(_funch, &FunctionHandler::save, ui, btnwidth, btnheight, 0, 0, "Save", font));
	btnptr->alignmenu();
	_buttons.push_back(btnptr);
}

// loads additional image
void UI::addimage()
{
	string filename = "images/test_image1.jpg";
	_images.push_back(new ImageManipulator(filename));
	_selimage = _images[0];
}

// colors pixels if image sprite is clicked
bool UI::imageclicked(int& x, int& y)
{

	if (_selimage->getspriteptr()->getGlobalBounds().contains(x, y)) {
		Color red = Color::Red;
		_selimage->colorpixels(x, y, x, y, red);
		return true;
	}
	return false;
}

// returns pointer to selected image
ImageManipulator* UI::getselimageptr()
{
	return _selimage;
}
