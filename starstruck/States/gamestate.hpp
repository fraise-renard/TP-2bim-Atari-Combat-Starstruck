/*
 * menu.hpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef STATES_GAMESTATE_HPP_
#define STATES_GAMESTATE_HPP_
#include <Engine/state.hpp>
#include <Engine/type.hpp>
#include <stdafx.hpp>


class GameState: public State {
public:
	GameState(GameDataRef data);
	void init();
	void handleInput();
	void draw(const float dt);
	//void handleInput();
	//void update(const float dt);
	//void handleInput();

private:
	GameDataRef data;
	sf::Texture button_tex;
	sf::Sprite button;
};

#endif /* STATES_GAMESTATE_HPP_ */
