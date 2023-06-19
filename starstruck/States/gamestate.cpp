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
Player astronaut(data, "wasd", "assets/astronaut/"), bilu(data, "arrow", "assets/etbilu/");
players.push_back(astronaut);
players.push_back(bilu);
players.at(0).init();
players.at(1).init();

}
void GameState::update(){
	players.at(0).update();
	players.at(1).update();
}
void GameState::draw() {
	//players.at(0).draw();
	//players.at(1).draw();
	sf::Sprite asf;
	sf::Texture sds;
	data->window.clear(sf::Color(157, 121, 188));
	players.at(0).draw();
	players.at(1).draw();
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

