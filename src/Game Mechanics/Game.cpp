// Bismillah hirahman nirahim

// This file will contain the main game mechanics
// It views the overall scene like declaring the main varibales, calling the uis
// Also does the job of actually opening and closing the window, the other (screen) funcitons exit without closing
// So on inshallah

#include <iostream>
// #include <SFML/Graphics.hpp>//included via main sc file
#include "../Interface/MainSc.cpp"
using namespace std;

void Game()
{
    cout << "Bismillah hirahman nirahim Game Started" << endl;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fill The Vault", sf::Style::Default, sf::State::Windowed); // This opens in style of default with title bar and the size is of desktop, fullscreened (sfml 3 split fullscreen from style to a 4th paramter state)
    cout << "Bismillah hirahman nirahim Window Made" << endl;

    MainSc(window); // Window given to main sc
    // The first screen toa actually display

    window.close();

    cout << "Alhamdulilah rab al alameen game ended" << endl;
}