#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Platform {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float x;
	float y;
	float width;
	float height;
public:
	Platform(float fx, float fy, float fwidth, float fheight): 
		x{ fx }, y{ fy }, width{ fwidth }, height{fheight}
	{
		texture.loadFromFile(PLATFORM_IMG);
		sprite.setTexture(texture);
		sprite.setScale(width / getHitBox().width, height / getHitBox().height);
		sprite.setPosition(x, y);
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::Vector2f getPosition() { return sf::Vector2f(x, y); }
	void update() {}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};