#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Drawer.h"
#include "Field.h"
#include "Enemy.h"
#include "Message.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;          //main window
	Vector2f      windowSize;     //window size
	Background*   background;    //background image
	Drawer*       drawer;       //drawer
	Field*        field;       //field
	Enemy*        enemy;      //enemy
	Message*      startMessage;
	

	Clock clock;
	float time;
	float timer;
	
	void processEvents();
	void update();
	void render();

public:	
	Game();
	~Game();
	void run();
	Vector2f getWindowSize();
};

