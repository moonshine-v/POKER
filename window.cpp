#include "word2.h"
#include "window.h"
#include "title.h" 
#include "OptionWindow.h"
#include "credits.h"
#include "LoginWindow.h"
#include "table.h"
//---------------------- Gia
void window::option(sf::Event sukien, float x, float y)
{
	sf::Font font;
	font.loadFromFile("Pangolin-Regular.ttf");
	sf::Text op("Option", font, 70);
	op.setPosition(170, 430 + 2 * 100);
	if (sukien.type == sf::Event::MouseButtonPressed && sukien.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i toadochuot = sf::Mouse::getPosition(Window);
		if (op.getGlobalBounds().contains(toadochuot.x, toadochuot.y))
		{
			Window.close();
			OptionWindow newWindow;
			newWindow.run();
		}

	}
}
//-----------------------------

/*LoginWindow Loginwindow;*/ // Ensure this instance is declared

window::window() : Window(sf::VideoMode::getDesktopMode(), "poker")
{
import();
	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) Window.close();
			guest(event, 170, 430 + 100);
			//------------------- Gia
			option(event, 170, 430 + 2 * 100);
			//-------------------
			credits(event, 170, 430 + 2 * 100);
			//-------------------
			//Loginwindow.handleEvent(Window, event); // Use the instance here
			//-------------------

		}
		screen();
	}
	screen();
}
void window::import()
{
	image.loadFromFile("background.jpg");
	visual.setTexture(image);
	visual.setScale(
		Window.getSize().x / visual.getGlobalBounds().width,
		Window.getSize().y / visual.getGlobalBounds().height
	);
}
void window::word(std::string chu, float x, float y)
{
	word2 t;
	t.play(chu, x, y);
	Window.draw(t.getText());
}
void window::screen()
{
	title c;
	c.play();
	Window.clear();
	Window.draw(visual);
	float cong = 100;
	word("Login", 170, 430);
	word("Guest", 170, 430 + cong);
	word("Option", 170, 430 + 2 * cong);
	word("Credit", 170, 430 + 3 * cong);
	Window.draw(c.getText());
	Window.display();
}


//----------------------------Ngoc
void window::credits(sf::Event sukien, float x, float y)
{
	sf::Font font;
	font.loadFromFile("Pangolin-Regular.ttf");
	sf::Text op("Credits", font, 70);
	op.setPosition(250.f, 430.f + 3 * 100);
	if (sukien.type == sf::Event::MouseButtonPressed && sukien.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i toadochuot = sf::Mouse::getPosition(Window);
		if (op.getGlobalBounds().contains(toadochuot.x, toadochuot.y))
		{
			Window.close();
			CreditsWindow newWindow;
			newWindow.run();
		}

	}
}

//------------------------------
void window::guest(sf::Event sukien, float x, float y)
{
	sf::Font font;
	font.loadFromFile("Pangolin-Regular.ttf");
	sf::Text guestText("Guest", font, 70);
	guestText.setPosition(170, 430 + 100);
	if (sukien.type == sf::Event::MouseButtonPressed && sukien.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i toadochuot = sf::Mouse::getPosition(Window);
		if (guestText.getGlobalBounds().contains(toadochuot.x, toadochuot.y))
		{
			TableWindow table;
			Window.close();
			GameState currentState = MENU;

			table.showMenu(currentState);
			if (currentState == GAME_VS_PLAYER) {
				table.showGameTable(true);
			}
			else if (currentState == GAME_VS_BOT) {
				table.showGameTable(false);
			}
		}

	}
}


