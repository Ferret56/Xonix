#include "Game.h"

Game::Game() {
	windowSize.x = 1920;
	windowSize.y = 1080;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix");
	background = new Background("src/images/background/space.png");
	drawer = new Drawer("src/images/drawers/bird.png");
}

Game::~Game() {}

void Game::processEvents() {
	//TODO time
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window->close();

	}
}

void Game::update() {
	//TODO
	this->drawer->update();
}
void Game::render() {
	window->clear();
	//TODO
	window->draw(background->getImage());
	window->draw(drawer->getSprite());
	window->display();
}
void Game::run() {
	while (window->isOpen()) {
		processEvents();
		update();
		render();
	}
}
