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
	selected_index = 0;
	enter = false;
}
void MenuState::init() {
	arcadefont.loadFromFile("assets/arcade.ttf");
	menuMusic.openFromFile("assets/highway_to_hell.wav");
	menuMusic.setLoop(true);
	menuMusic.setVolume(40);
	menuMusic.play();
	selectBuf.loadFromFile("assets/switch.ogg");
	select.setBuffer(selectBuf);
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
		menu[i].setPosition(ww / 2,
				wh / 2 + distance);
		distance += 100;
	}

	selected_index = 0;
	menu[selected_index].setFillColor(selected);

}
void MenuState::draw() {
	data->window.clear(sf::Color::White);
	for (int i = 0; i < 3; i++) {
		data->window.draw(menu[i]);
	}
	data->window.display();
}

void MenuState::update() {
	if (selected_index > 0 && moveUp) { //it will only move up when current selected option is not the first one
		select.play();
		menu[selected_index].setFillColor(unselected);
		selected_index--;
		menu[selected_index].setFillColor(selected);
		moveUp = false;
	}
	if (selected_index < 2 && moveDown) { //it will only move up when current selected option is not the last one
		select.play();
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

		if (event.type == sf::Event::Closed) {
			data->window.close();
		}
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
		menuMusic.setLoop(false);
		menuMusic.stop();
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

