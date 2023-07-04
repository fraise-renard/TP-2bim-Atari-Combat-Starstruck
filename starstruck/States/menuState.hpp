/*
 * menu.hpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef STATES_MENUSTATE_HPP_
#define STATES_MENUSTATE_HPP_
#include <Engine/gamedata.hpp>
#include <States/gameState.hpp>
#include <Engine/statemachine.hpp>
#include <stdafx.hpp>


class MenuState: public State {
public:
	MenuState(GameDataRef data);
	void init();
	void draw();
	void handleInput();
	void options();
	//void update();
	void update();
	//void handleInput();

private:
	GameDataRef data;
	sf::Music menuMusic;
	sf::SoundBuffer selectBuf;
	sf::Sound select;
	sf::Font arcadefont;
	sf::Text menu[3];
	int selected_index;
	sf::Color unselected{0,0,0}; //black
	sf::Color selected{255,0,0}; //red

	bool moveUp, moveDown, enter;
};

#endif /* STATES_MENUSTATE_HPP_ */
