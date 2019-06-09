#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
using namespace sf;

class Game {
private:
	RenderWindow* window;	      //main window
	Vector2f      windowSize;	 //window size
	Background*   background;	//background


	void processEvents();
	void update();
	void render();

public:
	Game();
	~Game();
	void run();
};

