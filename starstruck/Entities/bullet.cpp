/*
 * bullet.cpp
 *
 *  Created on: 2 de jul. de 2023
 *      Author: hayde
 */
#include <Entities/bullet.hpp>
Bullet::Bullet(int currentDir, sf::Sprite origin, GameDataRef data,
		std::string texPath) {
	this->data = data;
	this->texPath = texPath;
	this->origin = origin;
	pos = origin.getPosition();
	switch (currentDir) {
	case south:
		angle = 270;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case southwest:
		angle = 225;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case west:
		angle = 180;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = std::sin(angleRad);
		break;
	case northwest:
		angle = 135;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case north:
		angle = 90;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case northeast:
		angle = 45;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case east:
		angle = 0;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case southeast:
		angle = 315;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = -std::sin(angleRad);
		break;
	case 8:
		angle = 270;
		angleRad = angle * (3.14 / 180.0);
		x = std::cos(angleRad);
		y = std::sin(angleRad);
		break;
	}
}
void Bullet::init() {
	texture.loadFromFile(texPath);
	bullet.setOrigin(bullet.getGlobalBounds().width / 2,
			bullet.getGlobalBounds().height / 2);
	bullet.setPosition(pos.x - origin.getGlobalBounds().width / 2,
			pos.y - origin.getGlobalBounds().height / 2);
}
bool Bullet::testCollision(sf::Sprite target){
	if(bullet.getGlobalBounds().intersects(target.getGlobalBounds())){
		return true;
	}else{
		return false;
	}
}
bool Bullet::testCollision(sf::RectangleShape wall){
	if(bullet.getGlobalBounds().intersects(wall.getGlobalBounds())){
		return true;
	}else{
		return false;
	}
}
void Bullet::draw() {
	bullet.setTexture(texture);

	bullet.setScale(0.11, 0.11);

	data->window.draw(bullet);
}
void Bullet::update(float dt) {
	velocity.x += x * 10;
	velocity.y += y * 10;
	bullet.move(velocity * dt);
}
