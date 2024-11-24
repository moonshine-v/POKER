#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class window
{
public:
	void screen();
	void import();
	window();
	//------------------ Gia
	void option(sf::Event, float, float);
	//-------------------
	void word(std::string, float, float);
	void credits(sf::Event, float, float);
	void guest(sf::Event, float, float);
private:
	sf::RenderWindow Window;
	sf::Texture image;
	sf::Sprite visual;
	//word2 t;
};

#pragma once
