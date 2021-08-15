#pragma once
#include <SFML/Graphics.hpp>
class SpriteLoader
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	

	SpriteLoader(sf::Texture& texture, sf::Sprite& sprite);

	void LoadSprite(std::string filepath);

	void DrawSprite();

};

