/*
 * gamestate.cpp
 *
 *  Created on: 14 de jun. de 2023
 *      Author: hayde
 */
#include <States/gameState.hpp>

GameState::GameState(GameDataRef data) {
	this->data = data;
}

void GameState::init() {
	button_tex.loadFromFile("assets/sonic.png");
	button.setTexture(button_tex);
	button.setOrigin(button.getLocalBounds().width/2,
			button.getLocalBounds().height/2);
	button.setPosition(data->window.getSize().x / 2,
			data->window.getSize().y / 2);
}
void GameState::draw(const float dt) {
	data->window.clear(sf::Color(157, 121, 188));
	data->window.draw(button);
	data->window.display();
}

void GameState::handleInput() {
	sf::Event event;
	while (data->window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Escape)
			data->window.close();
	}
}

