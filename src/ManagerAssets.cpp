#include "../include/ManagerAssets.hpp"

namespace Minesweeper
{

	sf::Texture &ManagerAssets::LoadAndGetTexture(std::string fileName)
	{
		sf::Texture tex;
		if(tex.loadFromFile(fileName))
			_textures[fileName] = tex;
		return _textures.at(fileName);
	}

	sf::Font &ManagerAssets::LoadAndGetFont(std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
			_fonts[fileName] = font;
		return _fonts.at(fileName);
	}
}