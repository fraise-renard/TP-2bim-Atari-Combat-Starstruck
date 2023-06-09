/*
 * type.hpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */

#ifndef ENGINE_TYPE_HPP_
#define ENGINE_TYPE_HPP_
#include <Engine/statemachine.hpp>

struct GameData{
	StateMachine machine;
	sf::RenderWindow window;
};
typedef std::shared_ptr<GameData> GameDataRef;



#endif /* ENGINE_TYPE_HPP_ */
