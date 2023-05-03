#pragma warning(disable : 4996)
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>

//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
//#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

using namespace std;
using namespace sf;
int main()
{
	int width, height, channels;
	unsigned char* img = stbi_load("images/test_image1.jpg", &width, &height, &channels, 0);
	if (img == NULL) {
		cout << "Error in loading image" << endl;
	}
	else {
		cout << "Loaded image with width: " << width << " height: " << height << " channels: " << channels << endl;
		stbi_write_png("images/test_image_output1.png", width, height, channels, img, width * channels);
		stbi_write_jpg("images/test_image_output2.jpg", width, height, channels, img, 100);
		cout << "Done" << endl;
	}
	RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Red);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}