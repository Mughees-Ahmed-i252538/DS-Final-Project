// Bismillah hirahman nirahim

// This file will contain the logic of the main screen

#include <iostream>
// #include <SFML/Graphics.hpp> done in ui manager.cpp (although oindirectly through a more forward file)
#include "UIManager.cpp"
#include "CampaignMapSc.cpp"
#include "../Game Mechanics/LevelManager.cpp"
#include "../Game Mechanics/LeaderBoard.cpp"
using namespace std;

// sELF: GETTING issues while sending without refrence, I think copying issue ; logic should have been with refrence
int MainSc(sf::RenderWindow &window, LevelManager &Level_Manager) // returns outputs for debugging or forwarding (tentative exact puroose but kept this way for flexibilluty may not be used in current version)
{
    int Window_View_Size_x = window.getView().getSize().x; // these are needed to be able to set sizes of our sprites
    int Window_View_Size_y = window.getView().getSize().y;

    sf::Vector2f Wanted_View_Size(Window_View_Size_x, Window_View_Size_y);

    sf::Texture MainSc_Bg_Texture;

    if (!MainSc_Bg_Texture.loadFromFile("../src/Assets/images/MainSc/MainSc_Bg.jpg")) // starts from build folder
    {
        cout << "Failed to Load MainSc_Bg_Texture" << endl;
    } // issue: file suggestion offerned by intellesnece are relative to this file, but actual checks are relative to build folder.. it was mossing the src in file path
    // Unlikd this the #include is reolved at compile time so it uses location of including file as starter

    sf::Sprite MainSc_Bg_Sprite(MainSc_Bg_Texture); // No default cosntructor exsist hence must give texture at start

    // MainSc_Bg_Sprite we cant directly set size, in sfml , we can set scale
    // This set scale is wrt its actual global size
    // So we make a set size helper function

    // setSize(MainSc_Bg_Sprite, Wanted_View_Size); // to serve as the bg we need it to take whole screen
    setBgSize(window, MainSc_Bg_Sprite); // Sees window view to set size directly ( helpef function)
    // I think we can make afucniton
    // Set bg using view if need be

    sf::Texture MainSc_Button_Texture;

    if (!MainSc_Button_Texture.loadFromFile("../src/Assets/images/MainSc/MainSc_Button.png"))
    {
        cout << "Failed to Load MainSc_Button_Texture" << endl;
    }

    sf::Font MainSc_Button_Text_Font;

    if (!MainSc_Button_Text_Font.openFromFile("../src/Assets/fonts/MainSc/Aquire.otf")) // fonts use open from file insteado f load from file from sfml 3 because it streams on demand not store in memory
    {
        cout << "Failed to Open MainSc_Button_Text_Font" << endl;
    }

    SpriteTextBox Campaign_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font); // for some reason this was saying default constructor delted (apparently this happens if a datamemebr cant be constructed by default compiler cant make a default constructor for the holder class...)
    Campaign_Button_ST.setString("Campaign");
    Campaign_Button_ST.setRelativeSizeDifference(sf::Vector2f(-300, -100)); // This is relative size differnece bw text and box sizes
    Campaign_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Campaign_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Campaign_Button_ST.setPosition(sf::Vector2f(1093, 130));

    SpriteTextBox Endless_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font);
    Endless_Button_ST.setString("Endless");
    Endless_Button_ST.setRelativeSizeDifference(sf::Vector2f(-300, -100)); // This is relative size differnece bw text and box sizes
    Endless_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Endless_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Endless_Button_ST.setPosition(sf::Vector2f(1093, 270));

    SpriteTextBox Sandbox_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font);
    Sandbox_Button_ST.setString("Sandbox");
    Sandbox_Button_ST.setRelativeSizeDifference(sf::Vector2f(-300, -100)); // This is relative size differnece bw text and box sizes
    Sandbox_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Sandbox_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Sandbox_Button_ST.setPosition(sf::Vector2f(1093, 407));

    SpriteTextBox Leaderboard_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font);
    Leaderboard_Button_ST.setString("Leaderboard");
    Leaderboard_Button_ST.setRelativeSizeDifference(sf::Vector2f(-200, -100)); // This is relative size differnece bw text and box sizes
    Leaderboard_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Leaderboard_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Leaderboard_Button_ST.setPosition(sf::Vector2f(1093, 547));

    SpriteTextBox Settings_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font);
    Settings_Button_ST.setString("Settings");
    Settings_Button_ST.setRelativeSizeDifference(sf::Vector2f(-250, -100)); // This is relative size differnece bw text and box sizes
    Settings_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Settings_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Settings_Button_ST.setPosition(sf::Vector2f(1093, 685));

    SpriteTextBox Quit_Button_ST(MainSc_Button_Texture, MainSc_Button_Text_Font);
    Quit_Button_ST.setString("Quit");
    Quit_Button_ST.setRelativeSizeDifference(sf::Vector2f(-400, -100)); // This is relative size differnece bw text and box sizes
    Quit_Button_ST.setRelativePosDifferenceBwCenters(sf::Vector2f(0, -20));
    Quit_Button_ST.setSize_Minding_Relative_Size(sf::Vector2f(550, 120));
    Quit_Button_ST.setPosition(sf::Vector2f(1093, 821)); // If previous bitton moves up by 10 next moves up by 20 to accomodate that space too

    // int Button_pos_x = Quit_Button_ST.Sprite.getPosition().x;
    // int Button_pos_y = Quit_Button_ST.Sprite.getPosition().y;

    while (window.isOpen()) // had done if instead of while, windows only opened for a brief moment
    {
        while (std::optional event = window.pollEvent()) // This is the sfml 3 syntax, the 2 syntax was make an sf::Event event and do while(window.pollevent(event)), which is no longer usable as eents can no longer be empty (they did it to upgrade from c to c++ usage , it puts safety checks...)
        {                                                // And yes we can and are initializing a variable inside the paranthesis of while, i think if no event is present it returns std::nullopt the std::optional converts to false, (it converts to true if it holds a value), when it becomes false we get out of poll loop...
            if (event->is<sf::Event::Closed>())
            {
                return 0;
            } // Exit is working ALhamdulilah

            // Keyboard events
            if (sf::Event::KeyPressed *Key = event->getIf<sf::Event::KeyPressed>()) // KEypressed is a datatype
            {                                                                       // We use a * because it is able to be converted to bool
                // The getIf returns nullptr if event isnt KeyPressed, hence we wont run this block
                // More importantly getIf always returns a ptr const t*; t is a template placeholder, we made template keypressed
                // If event not of keypressed type it returns nullptr
                if (Key->code == sf::Keyboard::Key::Escape)
                {
                    return 0;
                }

                // FOr fine tuning
                /*
                if (Key->code == sf::Keyboard::Key::D) // This is an enum for code of right arrow
                {
                    Button_pos_x += 7;
                }

                if (Key->code == sf::Keyboard::Key::A) // This is an enum for code of right arrow
                {
                    Button_pos_x -= 7;
                }

                if (Key->code == sf::Keyboard::Key::W) // This is an enum for code of right arrow
                {
                    Button_pos_y -= 7;
                }

                if (Key->code == sf::Keyboard::Key::S) // This is an enum for code of right arrow
                {
                    Button_pos_y += 7;
                }
                */
            }
            else if (sf::Event::MouseButtonPressed *click = event->getIf<sf::Event::MouseButtonPressed>())
            {                                                                              // If mouse button pressed this block runs
                sf::Vector2f cursor_cordinates = window.mapPixelToCoords(click->position); // Because the position is in pixels, but we are using a view port so for us, the world is in coordinates; We need to convert pixels to coordinates

                if (click->button == sf::Mouse::Button::Left)
                {
                    // We do checks for if the cursor was on one of the buttons

                    if (Sprite_has_cursor_on_it(Quit_Button_ST.Sprite, cursor_cordinates))
                    {
                        return 0; // If left button pressed and cursor coordinates are in space of quit button, return 0
                    }
                    else if (Sprite_has_cursor_on_it(Campaign_Button_ST.Sprite, cursor_cordinates))
                    {
                        CampaignMapSc(window, Level_Manager);
                    }
                    else if (Sprite_has_cursor_on_it(Leaderboard_Button_ST.Sprite, cursor_cordinates))
                    {
                        makeld();
                    }
                }
            }
        }
        /*
        // Now for real time keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            Button_pos_x += 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            Button_pos_x -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            Button_pos_y -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            Button_pos_y += 1;
        }

        cout << Button_pos_x << " " << Button_pos_y << endl; // For finding out correct position
        Quit_Button_ST.setPosition(sf::Vector2f(Button_pos_x, Button_pos_y));
        //Adjusting logic commented
        */
        window.draw(MainSc_Bg_Sprite);

        Campaign_Button_ST.draw_on(window); // The buttons must be on top of bg else bg will hide them
        Endless_Button_ST.draw_on(window);
        Sandbox_Button_ST.draw_on(window);
        Leaderboard_Button_ST.draw_on(window);
        Settings_Button_ST.draw_on(window);
        Quit_Button_ST.draw_on(window);

        window.display();
    }

    return 0; // Just a placeholder to remove the warning that comes, curretn logic doenst reach it and pretriggers
}

// Note the std::option contains the sf::Event datatype
// It is like a box, either expty or full
// It takes in the evenet datatype because the window.poll returns event
// If the widnows.poll returns std::nullopt
// The box knows that it has to be empty, although its type is std::optiona<sf::Event>
// the nullopt can be returned even though return type is sf::Event because it fucnitons like a nullptr, which can be returned for int*, float* etc  ptr
// When the std;:optional sees this nullopt,
// Atlthough its type remains std::optional<sf::Event>
// a bool inside optional is made = false that tells it is empty and the event object inside isnt initialized
// We can adccess the is object isnide it using the -> (because it has been overloaded)
// The ->
// As the event itself is the std::optional
// the . operator access its own fucnitons etc
// They overaloaded he -> operator to let us access the fucnitosn of the sf::event isnide it
// Then the is() is a fucnito with a template inside it
// It lets us send the datatypes themseles and uses a clever indexinf mechanism in the events to check if the the event type id is same as the id assigned to the class / type of event we have sent
