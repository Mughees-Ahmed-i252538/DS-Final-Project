// Bismillah hirahman nirahim
#include "UIManager.h"

void SpriteTextBox::setSize_Minding_Relative_Size(sf::Vector2f Wanted_Size)
{
    ::setSize_Sprite(Sprite, Wanted_Size); // We renamed this fucniton but the :: tell it to look in global scope and not the funciton inside class, else recursive call

    float Size_For_Text_Minding_Relative_Difference_x = Wanted_Size.x + Relative_Size_Difference_x;
    float Size_For_Text_Minding_Relative_Difference_y = Wanted_Size.y + Relative_Size_Difference_y;

    sf::Vector2f Size_For_Text(Size_For_Text_Minding_Relative_Difference_x, Size_For_Text_Minding_Relative_Difference_y);

    ::setSize_Text(Text, Size_For_Text); // Relative differnece in size is box - text size
}

void SpriteTextBox::move(sf::Vector2f Coordinates)
{
    Sprite.move(Coordinates);
    Traslate_And_Centralize_OC_Text_To_Box();
}

void SpriteTextBox::setRelativeSizeDifference(sf::Vector2f Relative_Size_Difference)
{
    Relative_Size_Difference_x = Relative_Size_Difference.x;
    Relative_Size_Difference_y = Relative_Size_Difference.y;
}

void SpriteTextBox::setRelativePosDifferenceBwCenters(sf::Vector2f RelativePosDifferenceBwCenters)
{
    Relative_Pos_Difference_Bw_Centers_x = RelativePosDifferenceBwCenters.x;
    Relative_Pos_Difference_Bw_Centers_y = RelativePosDifferenceBwCenters.y;
}

// Simple texture and font were crashing perhaps reason is getting them as simply texture and font?
// Yes i thinnk so, it stooped crashing Alhamdulilah
SpriteTextBox::SpriteTextBox(sf::Texture &Texture, sf::Font &Font) : Sprite(Texture), Text(Font) // Initializer list
{
    /*
    cout << "Oringal origin" << Text.getOrigin().x << " " << Text.getOrigin().y << endl;
    setOriginToCenter(Text); // Makes its origin at center for easier centralizeing
    cout << "New origin" << Text.getOrigin().x << " " << Text.getOrigin().y << endl;
    Traslate_And_Centralize_OC_Text_To_Box(); // This centralizes text to box
    // std::cout << "Centralized Text to box" << endl;
    */
    // Issue. The setOrign runs although no string assigned yet, moved this logic to the set sting new fucntion
}

void SpriteTextBox::draw_on(sf::RenderWindow &window)
{
    window.draw(Sprite);
    window.draw(Text);
}

void SpriteTextBox::setPosition(sf::Vector2f Coordinates)
{
    Sprite.setPosition(Coordinates);
    Traslate_And_Centralize_OC_Text_To_Box();
}

void SpriteTextBox::Traslate_And_Centralize_OC_Text_To_Box()
{
    // Cosnidering teext is centralized already but sprite may not have been made  the centre as the origin
    float Sprite_Global_Bounds_x = Sprite.getGlobalBounds().size.x;
    float Sprite_Global_Bounds_y = Sprite.getGlobalBounds().size.y;

    sf::Vector2f Sprite_Geometric_Center(Sprite_Global_Bounds_x / 2, Sprite_Global_Bounds_y / 2);

    float Sprite_pos_x = Sprite.getPosition().x;
    float Sprite_pos_y = Sprite.getPosition().y;
    sf::Vector2f Sprite_pos(Sprite_pos_x, Sprite_pos_y); // Mistake was we were only centring not traslating

    sf::Vector2f Relative_Pos_Difference_bw_Centers(Relative_Pos_Difference_Bw_Centers_x, Relative_Pos_Difference_Bw_Centers_y);

    Text.setPosition(Sprite_pos + Sprite_Geometric_Center + Relative_Pos_Difference_bw_Centers); // First traslated to the position of the sprite, then centered in it trasnlated to its origin
    // also included the relative difference for fine tuning
}

void SpriteTextBox::setString(string String)
{
    Text.setString(String);
    setOriginToCenter(Text); // This funciton was moved here instead to fix the issue
    Traslate_And_Centralize_OC_Text_To_Box();
}

sf::FloatRect letterBox_Viewport_Calculator(sf::View Computer_View, sf::View Wanted_View) // Wanted view is t use macros defined in UiManager inshallah
{
    // Makes a view such that left right or up down get black boxed and displays ratio of choosen size in order for no stretching
    // Resizing formbidden through fullscreen modes

    int Computer_View_x = Computer_View.getSize().x;
    int Computer_View_y = Computer_View.getSize().y;
    int Wanted_View_x = Wanted_View.getSize().x;
    int Wanted_View_y = Wanted_View.getSize().y;

    float posX = 0, posY = 0, sizeX = 1, sizeY = 1; // cuz pos are starts and size are ends

    // Now if the ratio x:y of orignal is > then ratio of wanted
    // it will stretch in x axsis so we need buffer on x axsis

    float Computer_Ratio = Computer_View_x / Computer_View_y;
    float Wanted_Ratio = Wanted_View_x / Wanted_View_y;

    float Extra_Space = 0;

    if (Computer_Ratio > Wanted_Ratio)
    {
        // The extra space (ratio based: so bw 0 and 1) on x axsis is given by
        Extra_Space = Computer_Ratio - Wanted_Ratio;
        // To fix this we add this extra space's half in starting pos of x and subtract from ending size of x
        posX += Extra_Space / 2;
        sizeX -= Extra_Space / 2;
    }
    else if (Computer_Ratio < Wanted_Ratio) // If computer ratio greater in y direction
    {
        Extra_Space = Wanted_Ratio - Computer_Ratio;
        posY += Extra_Space / 2;
        sizeY -= Extra_Space / 2;
    }

    sf::FloatRect letterbox_Viewport(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY)); // sfml now dont take separte, but needs 2 separte vecotrs2f for floatrect

    return letterbox_Viewport;

    // Because renderview::viewport (the camera thaat shows the game world) takes 0-1 fractions from pox x,y , size x,y
    // We need ratios of real and wanted, to put black boxes and avoid stretching
}

void setSize_Sprite(sf::Sprite &Sprite, sf::Vector2f Wanted_Size)
{
    float Local_Size_x = Sprite.getLocalBounds().size.x;
    float Local_Size_y = Sprite.getLocalBounds().size.y;

    float Wanted_Size_x = Wanted_Size.x;
    float Wanted_Size_y = Wanted_Size.y;

    float Size_Ratio_x = Wanted_Size_x / Local_Size_x;
    float Size_Ratio_y = Wanted_Size_y / Local_Size_y; // Note local bounds is the orignal object size not affected by scale or rotation, setScale uses this,
    // Global bounds on the other hand is the ssize affectedby scaling

    // Now say we want the size that was twice as big as orignal in x axsis
    // ratio becomes 2
    // Scale should also be 2

    Sprite.setScale(sf::Vector2f(Size_Ratio_x, Size_Ratio_y));
}

void setSize_Text(sf::Text &Text, sf::Vector2f Wanted_Size) // For some reason compiler can differentiate bw the two based on data types hence we have to rename funtion to seaprate it
{
    float Local_Size_x = Text.getLocalBounds().size.x;
    float Local_Size_y = Text.getLocalBounds().size.y;

    float Wanted_Size_x = Wanted_Size.x;
    float Wanted_Size_y = Wanted_Size.y;

    float Size_Ratio_x = Wanted_Size_x / Local_Size_x;
    float Size_Ratio_y = Wanted_Size_y / Local_Size_y; // Note local bounds is the orignal object size not affected by scale or rotation, setScale uses this,
    // Global bounds on the other hand is the ssize affectedby scaling

    // Now say we want the size that was twice as big as orignal in x axsis
    // ratio becomes 2
    // Scale should also be 2

    Text.setScale(sf::Vector2f(Size_Ratio_x, Size_Ratio_y));
}

void setBgSize(sf::RenderWindow &window, sf::Sprite &Sprite) // We know the size will be view size
{
    int Window_View_Size_x = window.getView().getSize().x; // these are needed to be able to set sizes of our sprites
    int Window_View_Size_y = window.getView().getSize().y;

    sf::Vector2f Wanted_View_Size(Window_View_Size_x, Window_View_Size_y);

    setSize_Sprite(Sprite, Wanted_View_Size);
}

void setOriginToCenter(sf::Text &Text) // Issue found, the string was empty when this ran, restructuring the call of this fucniton to fix
{
    // std::cout << "Set Text Origin to its center" << endl;
    float Text_Global_Bounds_x = Text.getGlobalBounds().size.x;
    float Text_Global_Bounds_y = Text.getGlobalBounds().size.y;

    sf::Vector2f Text_Geometric_Center(Text_Global_Bounds_x / 2, Text_Global_Bounds_y / 2); // cuz orignial origin is at left top

    // cout << "Found Origin " << Text_Global_Bounds_x << " " << Text_Global_Bounds_y << endl;

    // Fixed Alhamdulilah

    Text.setOrigin(Text_Geometric_Center); // Because ddefault constructors dont exist for either sprite or font
}

bool Sprite_has_cursor_on_it(sf::Sprite &Sprite, sf::Vector2f Cursor_Coordiantes)
{
    if (Sprite.getGlobalBounds().contains(Cursor_Coordiantes))
    {
        return true;
    }
    else
    {
        return false;
    }
}