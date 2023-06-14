/*
 * menu.cpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#include <iostream> //temporary
#include <States/menuState.hpp>

MenuState::MenuState(GameDataRef data) {
	this->data = data;
}
void MenuState::init() {
	arcadefont.loadFromFile("assets/arcade.ttf");

	menu[0].setString("Play");
	menu[1].setString("Options");
	menu[2].setString("Exit");

	float distance = -100;
	sf::FloatRect textbounds;
	for (int i = 0; i < 3; i++) {
		menu[i].setFont(arcadefont);
		menu[i].setFillColor(unselected);
		menu[i].setCharacterSize(100);
		textbounds = menu[i].getLocalBounds();
		menu[i].setOrigin(textbounds.width / 2, textbounds.height / 2);
		menu[i].setPosition(data->window.getSize().x / 2,
				data->window.getSize().y / 2 + distance);
		distance += 100;
	}

	selected_index = 0;
	menu[selected_index].setFillColor(selected);

}
void MenuState::draw(const float dt) {
	data->window.clear(sf::Color::White);
	for (int i = 0; i < 3; i++) {
		data->window.draw(menu[i]);
	}
	data->window.display();
}

void MenuState::update(const float dt) {
	if (selected_index > 0 && moveUp) { //it will only move up when current selected option is not the first one
		menu[selected_index].setFillColor(unselected);
		selected_index--;
		menu[selected_index].setFillColor(selected);
		moveUp = false;
	}
	if (selected_index < 2 && moveDown) { //it will only move up when current selected option is not the last one
		menu[selected_index].setFillColor(unselected);
		selected_index++;
		menu[selected_index].setFillColor(selected);
		moveDown = false;
	}
	if(enter){
		options();
	}
}

void MenuState::handleInput() {
	sf::Event event;
	while (data->window.pollEvent(event)) {

		if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Escape)
			data->window.close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				moveUp = true;
				break;
			}
			if (event.key.code == sf::Keyboard::Down) {
				moveDown = true;
				break;
			}
			if (event.key.code == sf::Keyboard::Enter) {
				enter = true;
				break;
			}
		}

	}
}

void MenuState::options() { //happens when entering an option
	switch(selected_index){ //current index entered
	case 0:
		std::cout << "Play!";
		data->machine.addState(StateRef(new GameState(data)), true);
		enter = false;
		break;
	case 1:
		std::cout << "Options!";
		enter = false;
		break;
	case 2:
		data->window.close();
		break;
	}
}

