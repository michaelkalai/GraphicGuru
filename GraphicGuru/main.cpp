#pragma warning(disable : 4996)
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imagemanipulator.h"
#include "ui.h"

using namespace std;
using namespace sf;
int main()
{
	int width, height, channels;
	string filename = "images/test_image1.jpg";
	Color red = Color::Red;
	Color bg(78, 102, 102);
	ImageManipulator image(filename);

	RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "SFML works!", Style::Fullscreen);
	window.setFramerateLimit(60);

	Font font;
	font.loadFromFile("./font/AovelSansRounded.ttf");
	UI ui(font);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (ui.buttonclicked(event.mouseButton.x, event.mouseButton.y)) {
						cout << "saving file" << endl;
						image.savefile();
						cout << "save complete" << endl;
					}
					else if (image.getspriteptr()->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						image.colorpixels(event.mouseButton.x, event.mouseButton.y, event.mouseButton.x, event.mouseButton.y, red);
					}
				}
			}
		}
		window.clear(bg);
		image.draw(window);
		ui.draw(window);
		window.display();
	}
	return 0;
}