// Bismillah hirahman nirahim

// This file will contain the logic of the main screen

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int MainSc(sf::RenderWindow &window) // returns outputs for debugging or forwarding (tentative exact puroose but kept this way for flexibilluty may not be used in current version)
{
    sf::Texture MainSc_Bg_Texture;

    if (!MainSc_Bg_Texture.loadFromFile("../Assets/images/MainSc_Bg.jpg.jpeg")) // starts from build folder
    {
        cout << "Failed to Load MainSc_Bg_Texture" << endl;
    }

    sf::Sprite MainSc_Bg_Sprite(MainSc_Bg_Texture); // No default cosntructor exsist hence must give texture at start

    while (window.isOpen()) // had done if instead of while, windows only opened for a brief moment
    {
        while (std::optional event = window.pollEvent()) // This is the sfml 3 syntax, the 2 syntax was make an sf::Event event and do while(window.pollevent(event)), which is no longer usable as eents can no longer be empty (they did it to upgrade from c to c++ usage , it puts safety checks...)
        {                                                // And yes we can and are initializing a variable inside the paranthesis of while, i think if no event is present it returns std::nullopt the std::optional converts to false, (it converts to true if it holds a value), when it becomes false we get out of poll loop...
            if (event->is<sf::Event::Closed>())
            {
                return 0;
            } // Exit is working ALhamdulilah
        }
        window.draw(MainSc_Bg_Sprite);
        window.display();
    }

    // return 0;
}