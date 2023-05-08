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
	// constructs window
	Color bg(78, 102, 102);

	RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "GraphicGuru", Style::Fullscreen);
	window.setFramerateLimit(60);

	// loads font
	Font font;
	font.loadFromFile("./font/AovelSansRounded.ttf");
	UI ui(font);

	// program functions until closed
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			// handles event when mouse button is pressed
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (ui.buttonclicked(event.mouseButton.x, event.mouseButton.y)) {
						cout << "button function finished" << endl;
					}
					else if (ui.imageclicked(event.mouseButton.x, event.mouseButton.y)) {
						cout << "image colored" << endl;
					}
				}
			}
		}
		// displays program to user
		window.clear(bg);
		ui.draw(window);
		window.display();
	}
	return 0;
}