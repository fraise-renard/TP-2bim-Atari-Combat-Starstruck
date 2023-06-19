/*
 * player.cpp
 *
 *  Created on: 19 de jun. de 2023
 *      Author: hayde
 */

#include <Entities/player.hpp>
Player::Player(GameDataRef data, std::string keyset, std::string texPath) :
		data(data), keyset(keyset), texPath(texPath) {
}
void Player::init() {
	std::stringstream path;
	path << texPath << 0 << ".png";
	tex.loadFromFile(path.str());
	sprite.setTexture(tex);
	sprite.setPosition(ww/2,wh/2);
	if (keyset == "arrow") {
		keyUp = sf::Keyboard::Up;
		keyDown = sf::Keyboard::Down;
		keyLeft = sf::Keyboard::Left;
		keyRight = sf::Keyboard::Right;
	}
	if (keyset == "wasd") {
		keyUp = sf::Keyboard::W;
		keyDown = sf::Keyboard::S;
		keyLeft = sf::Keyboard::A;
		keyRight = sf::Keyboard::D;
	}
}
void Player::move() {
	velocity = (sf::Vector2f(0, 0));
	if (sf::Keyboard::isKeyPressed(keyUp)) {
		dir.y = -1;
		if (velocity.y > -maxVelocity) {
			velocity.y += acc * dir.y;
		}
	}
	if (sf::Keyboard::isKeyPressed(keyLeft)) {
		dir.x = -1;
		if (velocity.x > -maxVelocity) {
			velocity.x += acc * dir.x;
		}
	}
	if (sf::Keyboard::isKeyPressed(keyDown)) {
		dir.y = 1;
		if (velocity.y < maxVelocity) {
			velocity.y += acc * dir.y;
		}
	}
	if(sf::Keyboard::isKeyPressed(keyRight)){
		dir.x = 1;
		if(velocity.x < maxVelocity){
			velocity.x += acc * dir.x;
		}
	}

}
void Player::draw(){
	data->window.draw(sprite);
}
void Player::update() {
	//int multiplier = 60;
	move();
	drag();
	sprite.move(velocity);
}

