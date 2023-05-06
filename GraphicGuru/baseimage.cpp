#include "baseimage.h"

void BaseImage::savefile(string& filetype, string& filename)
{
	if (filetype == "jpg") {
		stbi_write_jpg(filename.c_str(), _width, _height, _channels, _img, 100);
	}
	else if (filetype == "png") {
		stbi_write_png(filename.c_str(), _width, _height, _channels, _img, _width * _channels);
	}
}

unsigned char* BaseImage::getimageptr()
{
	return _img;
}
