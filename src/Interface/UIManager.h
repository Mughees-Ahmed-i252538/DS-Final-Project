
// Bismillah hirahman nirahim
// This file contains data that helps in ui
// Including self made data types and functions for eace

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

// May separate componenets if see need, ensuring we dont duplicate addition of sfml to avoid issues and slow downs

// This is a self made extension to sfml sprite box
// This works to auto centre text in the box
// Ensure the the text scales and moves with respect to the sprite

struct SpriteTextBox
{
    sf::Sprite Sprite;
    sf::Text Text;

    void scale(sf::Vector2f factor);

    void move(sf::Vector2f Coordinates);

    void draw_on(sf::RenderWindow &window);

    SpriteTextBox(sf::Texture &Texture, sf::Font &Font);

    void setPosition(sf::Vector2f Coordinates);

    void Traslate_And_Centralize_OC_Text_To_Box();
};

sf::FloatRect letterBox_Viewport_Calculator(sf::View Computer_View, sf::View Wanted_View); // Wanted view is t use macros defined in UiManager inshallah

void setSize(sf::Sprite &Sprite, sf::Vector2f Wanted_Size); // only scaliung function exsist in sfml uses global coordinates , so we use helper function

void setBgSize(sf::RenderWindow &window, sf::Sprite &Sprite); // We know the size will be view size

// Correction doing & sprite, I dont think will actually sizea origanl size otherwise

void setOriginToCenter(sf::Text &Text);