#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Minesweeper
{
	class ManagerAssets
	{
	public:
		sf::Texture &LoadAndGetTexture(std::string fileName);
		sf::Font &LoadAndGetFont(std::string fileName);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}
