#pragma once
#include <SFML/Graphics.hpp>
#include"String"
using namespace sf;

class Game {
private:
	RenderWindow* window;	  //main window
	Vector2f windowSize;	 //window size



	void processEvents();
	void update();
	void render();

public:
	Game();
	~Game();
	void run();
};

