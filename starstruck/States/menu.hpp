/*
 * menu.hpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef STATES_MENU_HPP_
#define STATES_MENU_HPP_
#include <Engine/state.hpp>
#include <Engine/type.hpp>
#include <stdafx.hpp>


class MenuState: public State {
public:
	MenuState(GameDataRef data);
	void init();
	void draw(const float dt);


private:
	GameDataRef data;
	sf::Texture button_tex;
	sf::Sprite button;


};

#endif /* STATES_MENU_HPP_ */
