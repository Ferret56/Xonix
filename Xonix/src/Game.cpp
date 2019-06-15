#include "Game.h"

Game::Game() {
	windowSize.x = 1600;
	windowSize.y = 900;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix");	
	background = new Background("src/images/background/space.png");
	drawer = new Drawer("src/images/drawers/bird.png");	
	field = new Field();
	enemy = new Enemy("src/images/drawers/enemy.png", *field);	
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
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 500;
	timer += time;
	//if(timer > 150){
		this->enemy->update(time);
		//timer = 0;
	//}	
	this->drawer->update(time);
	this->field->update(time);
	
}
void Game::render() {
	window->clear();
	//TODO
	window->draw(background->getImage());
	field->draw(window);
	window->draw(enemy->getSprite());
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

Vector2f Game::getWindowSize() {
	return windowSize;
}

