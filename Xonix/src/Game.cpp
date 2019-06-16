#include "Game.h"
#include <iostream>
Game::Game() {
	windowSize.x = 1600;
	windowSize.y = 900;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix");	
	background = new Background("src/images/background/space.png");
	field = new Field();
	drawer = new Drawer("src/images/drawers/bird1.png",*field);	
	enemy = new Enemy("src/images/drawers/enemy.png", *field);
	String start = " Welcome to the game!.\nPress ENTER to start.";
	startMessage = new Message(start, "src/fonts/Main.ttf", 100, 350, 250);
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
	this->enemy->update(time);
	
	this->field->updatePercentage();
	this->drawer->update(time);
	if(this->drawer->on_the_field() == false)
	          this->field->update(time);

	std::cout << "\t\t\t\t" << this->field->getFieldPercentage() << std::endl;
	
}
void Game::render() {
	window->clear();
	//TODO
	window->draw(background->getImage());
	field->draw(window);
	window->draw(enemy->getSprite());
	window->draw(drawer->getSprite());	
	startMessage->show(window);
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

