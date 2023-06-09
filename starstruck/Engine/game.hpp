/*
 * game.hpp
 *
 *  Created on: 3 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef ENGINE_GAME_HPP_
#define ENGINE_GAME_HPP_
#include <States/menu.hpp>
#include <stdafx.hpp>
#include <Engine/type.hpp>

class Game{
public:
	Game(int width, int height);
private:
	const float dt= 1.0/60; //60 updates per second (framerate)
	sf::Clock clock;
	sf::Event event;
	GameDataRef game_data = std::make_shared<GameData>();


	void Run();
};




#endif /* ENGINE_GAME_HPP_ */
