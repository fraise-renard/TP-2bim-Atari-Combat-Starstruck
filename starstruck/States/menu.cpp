/*
 * menu.cpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#include <States/menu.hpp>

MenuState::MenuState(GameDataRef data){
	this -> data = data;
}
void MenuState::init(){
	button_tex.loadFromFile("assets/sonic.png");
	button.setTexture(button_tex);
}
void MenuState::draw(float dt){
	data->window.clear(sf::Color::White);
	data->window.draw(button);
	data->window.display();
}



