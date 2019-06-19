#include "Game.h"

//Standart constructor to initialize variables
Game::Game() {
	windowSize.x = 1600;
	windowSize.y = 900;
	window = new RenderWindow(VideoMode(windowSize.x, windowSize.y), "Xonix");	
	background = new Background("src/images/background/space1.png");
	field = new Field("src/images/field/plate.png",600,200);
	drawer = new Drawer("src/images/drawers/bird1.png",*field);	
	enemy = new Enemy("src/images/drawers/enemy.png", *field);
	String start = " Welcome to the game!.\nPress ENTER to start.";
	startMessage = new Message(start, "src/fonts/Main.ttf", 100, 350, 300);
	TARGET += std::to_string(this->drawer->getTarget()) + "%\n";
	scoreInformation = new Message(Game::TARGET + Game::SUCCESS, "src/fonts/font.ttf", 50, 1200, 50);
	is_start = false;
	status = Game::NORMAL;
}

//Standart desctructor to destroy variables	
Game::~Game() {
	delete this->window;
	delete this->background;
	delete this->drawer;
	delete this->field;
	delete this->enemy;
	delete this->startMessage;
	delete this->scoreInformation;
}

//handle events
void Game::processEvents() {	
	Event event;
	while (window->pollEvent(event)){	
		if (event.type == sf::Event::Closed)
			window->close();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window->close();		
		if (Keyboard::isKeyPressed(Keyboard::Enter))
			is_start = true;
		
		this->drawer->processEvents();   //handle drawer events
	}
}

//update the game logic
void Game::update() {
     	time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		this->enemy->update();
		this->field->updatePercentage();
		this->drawer->update(time);
		if (this->drawer->on_the_field() == false)
			this->field->update(time);

		if (this->drawer->is_drawer_win())
			Game::status = Game::WIN;

		if (!this->enemy->is_enemy_alive())
			Game::status = Game::LOSE;	

		scoreInformation->setText(Game::TARGET + Game::SUCCESS + 
			 std::to_string(100 - this->field->getFieldPercentage()) + "%");	
}

//drawing graphics
void Game::render() {
	window->clear();	
	window->draw(background->getImage());
	field->draw(window);
	window->draw(enemy->getSprite());
	window->draw(drawer->getSprite());	
	scoreInformation->show(window);
	window->display();
}

//run the game
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
//getter or the window size
Vector2f Game::getWindowSize() {
	return windowSize;
}

