#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Drawer.h"
#include "Field.h"
#include "Enemy.h"
#include "Message.h"
using namespace sf;

/*The main class that contains all the game elements*/
class Game {
private:
	RenderWindow* window;                   //main window
	Vector2f      windowSize;              //window size
	Background*   background;             //background image
	Drawer*       drawer;                //drawer
	Field*        field;                //field
	Enemy*        enemy;               //enemy
	Message*      startMessage;       //start message
	Message*      scoreInformation;  //score message
	

	Clock clock;                    //Clock(SFML library)
	float time;                    // time(for timing)
	

	bool is_start;                //Has the game started?
	
	void processEvents();        //event handling
	void update();              //gameplay update
	void render();             //drawing

public:	
	Game();                                 
	~Game();
	void run();	
	Vector2f getWindowSize();
	enum { NORMAL, WIN, LOSE } status;

	const String LOSE_MESSAGE = "\t\t Oh, you lost.I'm sorry.\n   Do not worry.Next time maybe";
	const String WIN_MESSAGE = "\t  You are win!\n\tCongratulations";
	String TARGET = "TARGET: ";
	String SUCCESS = "SUCCESS: ";

};

