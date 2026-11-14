// Bismillah hirahman nirahim

// This file will contain the main game mechanics
// It views the overall scene like declaring the main varibales, calling the uis
// So on inshallah

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

void Game()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fill The Vault", sf::Style::Default, sf::State::Windowed); // This opens in style of default with title bar and the size is of desktop, fullscreened (sfml 3 split fullscreen from style to a 4th paramter state)

    while (window.isOpen())
    {
        window.display();
    }
}