#include "Game.h"



Game::Game() {
	windowSize.x = 1280;
	windowSize.y = 720;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix");
}

Game::~Game() {}

void Game::processEvents() {
	//TODO time

	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

	}
}

void Game::update() {
	//TODO
}
void Game::render() {
	//TODO
	window->display();
}
void Game::run() {
	while (window->isOpen()) {
		processEvents();
		update();
		render();
	}
}
