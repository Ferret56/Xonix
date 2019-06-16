#include "Message.h"

Message::Message(const String msg, const String path_to_the_font, const int size, const float x, const float y) {
	font.loadFromFile(path_to_the_font);
	text.setFont(font);
	text.setString(msg);
	text.setCharacterSize(size);
	text.setPosition(x, y);
}


void Message::setTextPosition(const float x, const float y) {
	text.setPosition(x, y);
}

void Message::setText(const String msg) { this->text.setString(msg); }

void Message::setSize(const int size) { this->text.setCharacterSize(size); }



void Message::show(RenderWindow * window) {
	window->draw(text);
}

