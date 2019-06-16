#include "Game.h"
#include <iostream>
Game::Game() {
	windowSize.x = 1600;
	windowSize.y = 900;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix", Style::Fullscreen);	
	background = new Background("src/images/background/space1.png");
	field = new Field();
	drawer = new Drawer("src/images/drawers/bird1.png",*field);	
	enemy = new Enemy("src/images/drawers/enemy.png", *field);
	String start = " Welcome to the game!.\nPress ENTER to start.";
	startMessage = new Message(start, "src/fonts/Main.ttf", 100, 350, 300);
	is_start = false;
	status = Game::NORMAL;
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
		if (Keyboard::isKeyPressed(Keyboard::Enter))
			is_start = true;

	}
}

void Game::update() {	

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;
		timer += time;
		this->enemy->update(time);

		this->field->updatePercentage();
		this->drawer->update(time);
		if (this->drawer->on_the_field() == false)
			this->field->update(time);

		std::cout << "\t\t\t\t" << this->field->getFieldPercentage() << std::endl;

		if (this->drawer->is_drawer_win())
			Game::status = Game::WIN;

		if (!this->enemy->is_enemy_alive())
			Game::status = Game::LOSE;
	
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
		if (is_start) {
			switch (status) {
			     case Game::NORMAL:
				      update();
				      render();
				      break;
			     case Game::LOSE:
					 window->clear();
					 window->draw(background->getImage());
					 startMessage->setText(Game::LOSE_MESSAGE);
					 startMessage->setTextPosition(150, 250);
					 startMessage->show(window);
					 window->display();
					 break;
				 case Game::WIN:
					 window->clear();
					 window->draw(background->getImage());
					 startMessage->setText(Game::WIN_MESSAGE);
					 startMessage->setTextPosition(400, 250);
					 startMessage->show(window);
					 window->display();
					 break;
			}
		}
		else {
			window->clear();
			window->draw(background->getImage());
			startMessage->show(window);
			window->display();
		}


	}
}
Vector2f Game::getWindowSize() {
	return windowSize;
}

