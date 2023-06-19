/*
 * Player.hpp
 *
 *  Created on: 19 de jun. de 2023
 *      Author: hayde
 */

#ifndef ENTITIES_PLAYER_HPP_
#define ENTITIES_PLAYER_HPP_
#include <Entities/entity.hpp>
#include <Engine/gamedata.hpp>
class Player : Entity{
public:
	Player(GameDataRef data, std::string keyset, std::string texPath);
	void init();
	void update();
	void draw();
	void move();
	void drag(){};
	void animate(){};
	void collision(){};
	sf::Sprite sprite;
private:
	GameDataRef data;
	std::string keyset, texPath;
	sf::Keyboard::Key keyUp, keyDown, keyLeft, keyRight;
	sf::Texture tex;
	sf::Vector2f velocity, dir;
	float acc = 1, maxVelocity = 7;
	bool collide;
};



#endif /* ENTITIES_PLAYER_HPP_ */
