
#include "imagemanipulator.h"

// loads image file and displays image in center of screen (resizes as necessary and records relevant values)
ImageManipulator::ImageManipulator(string& filename)
{
	_img.loadFromFile(filename);
	_imgtext.loadFromImage(_img);
	_imgsprite.setTexture(_imgtext);
	cout << _imgsprite.getLocalBounds().width << " Height: " << _imgsprite.getLocalBounds().height << endl;
	_imgwidth = _imgsprite.getLocalBounds().width;
	_imgheight = _imgsprite.getLocalBounds().height;
	_winwidth = VideoMode::getDesktopMode().width;
	_winheight = VideoMode::getDesktopMode().height;
	_scalex = VideoMode::getDesktopMode().width / _imgsprite.getLocalBounds().width / 1.5;
	_scaley = VideoMode::getDesktopMode().height / _imgsprite.getLocalBounds().height / 1.5;
	_imgsprite.setPosition(_winwidth / 2 - (_imgwidth * _scalex / 2), _winheight / 2 - (_imgheight * _scaley / 2));
	_imgsprite.setScale(_scalex, _scaley);
	cout << _imgwidth / _winwidth << endl;
	cout << _imgheight / _winheight << endl;
}

// draws image
void ImageManipulator::draw(RenderWindow& window)
{
	window.draw(_imgsprite);
}

// changes the color of the pixels within the image (currently modifies a 300 by 300 area with the mouse as the origin)
void ImageManipulator::colorpixels(int& initialx, int& initialy, int xcoord, int ycoord, Color& color)
{
	if (xcoord > initialx + 300) {
		if (ycoord > initialy + 299) {
			_imgtext.loadFromImage(_img);
			_imgsprite.setTexture(_imgtext);
		}
		return;
	}
	else if (xcoord == initialx and ycoord == initialy) {
		for (int i = 1; i < 301; i++) {
			colorpixels(initialx, initialy, xcoord, ycoord + i, color);
		}
	}
	for (int i = 0; i < _imgwidth / _winwidth * 1.5; i++) {
		for (int j = 0; j < _imgheight / _winheight * 1.5; j++) {
			_img.setPixel(min((xcoord - ((_winwidth / 2 - xcoord) / 2)) / _winwidth * _imgwidth + i, (float)_imgwidth - 1), min((ycoord - ((_winheight / 2 - ycoord) / 2)) / _winheight * _imgheight + j, (float)_imgheight - 1), color);
		}
	}
	colorpixels(initialx, initialy, xcoord + 1, ycoord, color);
}

// saves file
void ImageManipulator::savefile()
{
	_img.saveToFile("images/save_test.jpg");
}

// returns pointer to sprite
Sprite* ImageManipulator::getspriteptr()
{
	return &_imgsprite;
}
