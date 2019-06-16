#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Message {
private:
	Font font;
	Text text;

public:
	Message(const String msg, const String path_to_the_font, const int size, const float x, const float y);
	void setTextPosition(const float x, const float y);
	void show(RenderWindow* window);


};