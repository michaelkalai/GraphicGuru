
#include "imagemanipulator.h"

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
}

void ImageManipulator::draw(RenderWindow& window)
{
	window.draw(_imgsprite);
}

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
	for (int i = 0; i < _imgwidth / _winwidth + 4; i++) {
		for (int j = 0; j < _imgheight / _winheight + 4; j++) {
			_img.setPixel(min((xcoord - ((_winwidth / 2 - xcoord) / 2)) / _winwidth * _imgwidth + i, (float)_imgwidth - 1), min((ycoord - ((_winheight / 2 - ycoord) / 2)) / _winheight * _imgheight + j, (float)_imgheight - 1), color);
		}
	}
	colorpixels(initialx, initialy, xcoord + 1, ycoord, color);
}

void ImageManipulator::savefile()
{
	_img.saveToFile("images/save_test.jpg");
}
