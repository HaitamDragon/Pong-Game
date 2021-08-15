#include "SpriteLoader.h"
#include <iostream>

SpriteLoader::SpriteLoader(sf::Texture& texture, sf::Sprite& sprite)
{
	
	texture = m_texture;
	sprite = m_sprite;
}

void SpriteLoader::LoadSprite(std::string filepath)
{
	m_texture.loadFromFile(filepath);

	if (!m_texture.loadFromFile(filepath))
	{
		std::cout << "Error loading a texture" << std::endl;
	}
}

void SpriteLoader::DrawSprite()
{
	m_sprite.setTexture(m_texture);
}