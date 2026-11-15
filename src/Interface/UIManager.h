
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
    float Relative_Size_Difference_x = 0; // This allows for the text to scale slightly differently from the button
    float Relative_Size_Difference_y = 0;
    float Relative_Pos_Difference_Bw_Centers_x = 0; // This allows for the text to scale slightly differently from the button
    float Relative_Pos_Difference_Bw_Centers_y = 0;

    void setRelativeSizeDifference(sf::Vector2f);
    void setRelativePosDifferenceBwCenters(sf::Vector2f);

    void setSize_Minding_Relative_Size(sf::Vector2f Size);

    void move(sf::Vector2f Coordinates);

    void draw_on(sf::RenderWindow &window);

    SpriteTextBox(sf::Texture &Texture, sf::Font &Font);

    void setPosition(sf::Vector2f Coordinates);

    void Traslate_And_Centralize_OC_Text_To_Box();

    void setString(string String);
};

sf::FloatRect letterBox_Viewport_Calculator(sf::View Computer_View, sf::View Wanted_View); // Wanted view is t use macros defined in UiManager inshallah

void setSize_Sprite(sf::Sprite &Sprite, sf::Vector2f Wanted_Size); // only scaliung function exsist in sfml uses global coordinates , so we use helper function

void setSize_Text(sf::Text &Text, sf::Vector2f Wanted_Size); // only scaliung function exsist in sfml uses global coordinates , so we use helper function

void setBgSize(sf::RenderWindow &window, sf::Sprite &Sprite); // We know the size will be view size

// Correction doing & sprite, I dont think will actually sizea origanl size otherwise

void setOriginToCenter(sf::Text &Text);

// Plan, build a list data type, that does auto placement and lets us adjust sizes of each and internal differnece forr ease of ui adjustment inshallah