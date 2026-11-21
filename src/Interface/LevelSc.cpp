// Bismillah hirahman nirahim

// This round will have a geral overview of the level inshallah
#include "UIManager.h"
#include "../Game Mechanics/LevelManager.cpp"

int Wrap_Around(sf::RenderWindow &window, sf::Text &Text)
{
    int Window_View_Size_x = window.getView().getSize().x;   // these are needed to be able to set sizes of our sprites
    Window_View_Size_x -= Text.getGlobalBounds().position.x; // Cuz we also want to account for the left gap
    Window_View_Size_x -= 50;                                // Because we also want to leave a margin or right ()

    int Text_Size_x = Text.getGlobalBounds().size.x;

    // Now to see how how many characters

    int No_of_chars = Text.getString().getSize(); // Gives no of charcters

    int How_Many_Lines_Needed = ceil(Text_Size_x / (float)(Window_View_Size_x)); // need to float and then ceil so that chars that are on last line (give a decimal value if not complete line) are not lefft

    // How many lines needed means we need howmanylinesneed-1 number of \name

    int Number_of_New_Line_Chars = How_Many_Lines_Needed - 1;
    int Period_of_Where_To_Put_Next_Line_Char = No_of_chars / Number_of_New_Line_Chars; // flooring just in case a char goes out of bounds
    // Current escaping the bounds still so decreasing period if it doesnt make it too less

    if (Period_of_Where_To_Put_Next_Line_Char != 2)
    {
        Period_of_Where_To_Put_Next_Line_Char -= 2;
    }

    // May need overwsight later on, but maybe ok inshallah

    if (Number_of_New_Line_Chars == 0) // if no new line needed
    {
        return 0;
    } //
    else
    {

        string Orignal = Text.getString().toAnsiString(); // issue found getStirng retrurns sfmls own data trype STring& we need it bto be trransformed into std::string ALhamdulilah
        string New;

        for (int i = 0; i < Orignal.size(); i++) // issue found, std string doessnt store \0 at end,... it calcualtes size by itself hence this ran for idk amount of time..(actually tob be acturate.. that i forgot to do i++) Akhamdulilah rab al alameen
        {
            if (i % Period_of_Where_To_Put_Next_Line_Char == 0 && i != 0) // if i is a non zero multiple of the period, put the \n
            {
                New += '\n';
            }

            New += Orignal[i];
        }

        Text.setString(New);
        return 1;
    }
    return 1;
}

int LevelSc(sf::RenderWindow &window, LevelManager &Level_Manager, int Current_Level_No) // Also gives current level number to track its name in catalog
{                                                                                        // Considering a levl has been loaded inshallah, ALhamdulilah rab al alameen
    // we consider that level has been loaded, and the unloading happens in the outer screen as well, howver if next level exsists this cpp serves to unock that if this level meets the passing criteria inshallah

    int Window_View_Size_x = window.getView().getSize().x; // these are needed to be able to set sizes of our sprites
    int Window_View_Size_y = window.getView().getSize().y;

    sf::Vector2f Wanted_View_Size(Window_View_Size_x, Window_View_Size_y);

    sf::Texture LevelSc_Bg_Texture;

    if (!LevelSc_Bg_Texture.loadFromFile("../src/Assets/images/LevelSc/LevelSc_Bg.png")) // starts from build folder
    {
        cout << "Failed to Load LevelSc_Bg_Texture" << endl;
    } // issue: file suggestion offerned by intellesnece are relative to this file, but actual checks are relative to build folder.. it was mossing the src in file path
    // Unlikd this the #include is reolved at compile time so it uses location of including file as starter

    sf::Sprite LevelSc_Bg_Sprite(LevelSc_Bg_Texture); // No default cosntructor exsist hence must give texture at start

    // LevelSc_Bg_Sprite we cant directly set size, in sfml , we can set scale
    // This set scale is wrt its actual global size
    // So we make a set size helper function

    // setSize(LevelSc_Bg_Sprite, Wanted_View_Size); // to serve as the bg we need it to take whole screen
    setBgSize(window, LevelSc_Bg_Sprite); // Sees window view to set size directly ( helpef function)
                                          // I think we can make afucniton
                                          // Set bg using view if need be

    sf::Font LevelSc_Button_Text_Font;

    if (!LevelSc_Button_Text_Font.openFromFile("../src/Assets/fonts/LevelSc/Orbitron-Bold.ttf.woff")) // fonts use open from file insteado f load from file from sfml 3 because it streams on demand not store in memory
    {
        cout << "Failed to Open LevelSc_Button_Text_Font" << endl;
    }

    sf::Font LevelSc_Text_Font; // For non buttons

    if (!LevelSc_Text_Font.openFromFile("../src/Assets/fonts/LevelSc/Orbitron-Bold.ttf.woff")) // fonts use open from file insteado f load from file from sfml 3 because it streams on demand not store in memory
    {
        cout << "Failed to Open LevelSc_Text_Font" << endl;
    }

    string Level_Act = "Act: ";
    Level_Act += Int_To_String(Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level_No].Act_no);
    string Level_No = "Level Number: ";
    Level_No += Int_To_String(Current_Level_No);
    cout << "===================================+++++++++++++++++++ Level Number: >>>>" << Level_No << "|" << endl;
    string Level_Name = "Name: ";
    Level_Name += Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level_No].name;
    string Level_Description = "Description: ";
    Level_Description += Level_Manager.CurrentLevelData.Description;

    sf::Text Level_Act_Text(LevelSc_Text_Font);
    Level_Act_Text.setString(Level_Act);
    Level_Act_Text.setFillColor(sf::Color::Black);
    Level_Act_Text.setScale(sf::Vector2f(3, 3));                                   // keeping some pixels of space for the stars, keeping its start on the 3/7 on the screen from top
    Level_Act_Text.setPosition(sf::Vector2f(0 + 50, 6 * Wanted_View_Size.y / 14)); // keeping the origin at left top because more suitable here ALhamdulilah rab al alameen
    sf::Text Level_No_Text(LevelSc_Text_Font);
    Level_No_Text.setString(Level_No);
    Level_No_Text.setFillColor(sf::Color::Black);
    Level_No_Text.setScale(sf::Vector2f(3, 3)); // had mistakely set scale to 200 Alhamdulilah found
    Level_No_Text.setPosition(sf::Vector2f(0 + 50, 7 * Wanted_View_Size.y / 14));
    sf::Text Level_Name_Text(LevelSc_Text_Font);
    Level_Name_Text.setString(Level_Name);
    Level_Name_Text.setFillColor(sf::Color::Black);
    Level_Name_Text.setScale(sf::Vector2f(3, 3));
    Level_Name_Text.setPosition(sf::Vector2f(0 + 50, 8 * Wanted_View_Size.y / 14));
    sf::Text Level_Description_Text(LevelSc_Text_Font);
    Level_Description_Text.setString(Level_Description);
    Level_Description_Text.setFillColor(sf::Color::Red);
    Level_Description_Text.setScale(sf::Vector2f(2, 2));
    Level_Description_Text.setPosition(sf::Vector2f(0 + 50, 9 * Wanted_View_Size.y / 14));
    // Issue: the description gets out of the screen we need to implement wrap around, we also need its size after say: Method insert \n into text string and provide it again

    Wrap_Around(window, Level_Description_Text);

    sf::Texture LevelSc_Button_Texture;

    if (!LevelSc_Button_Texture.loadFromFile("../src/Assets/images/LevelSc/LevelSc_Button.png"))
    {
        cout << "Failed to Load LevelSc_Button_Texture" << endl;
    }

    sf::Sprite Start_Button_Sprite(LevelSc_Button_Texture);
    Start_Button_Sprite.setOrigin(sf::Vector2f(Start_Button_Sprite.getLocalBounds().size.x / 2, Start_Button_Sprite.getLocalBounds().size.y / 2));
    Start_Button_Sprite.setPosition(sf::Vector2f(Wanted_View_Size.x / 2.0, 450));
    setSize_Sprite(Start_Button_Sprite, sf::Vector2f(400, 250));

    sf::Text Start_Button_Text(LevelSc_Button_Text_Font);
    Start_Button_Text.setString("Start"); // Had forgotten to do so
    Start_Button_Text.setFillColor(sf::Color::Black);
    Start_Button_Text.setOutlineColor(sf::Color::White);

    Start_Button_Text.setOrigin(sf::Vector2f(Start_Button_Text.getLocalBounds().size.x / 2.0 + Start_Button_Text.getLocalBounds().position.x, Start_Button_Text.getLocalBounds().size.y / 2 + Start_Button_Text.getLocalBounds().position.y));
    Start_Button_Text.setPosition(sf::Vector2f(Wanted_View_Size.x / 2.0, 450)); //
    Start_Button_Text.setScale(sf::Vector2f(2, 2));

    // int Button_pos_x = Quit_Button_ST.Sprite.getPosition().x;
    // int Button_pos_y = Quit_Button_ST.Sprite.getPosition().y;

    sf::Texture Star_SpriteSheet;
    if (!Star_SpriteSheet.loadFromFile("../src/Assets/images/LevelSc/Star_Spreadsheet.png"))
    {
        cout << "Couldnt load Star_SpriteSheet" << endl;
    }

    sf::IntRect Earned_Stars_Coordiantes(sf::Vector2i(54, 109), sf::Vector2i(1224, 917));
    sf::IntRect Unearned_Stars_Coordiantes(sf::Vector2i(1269, 80), sf::Vector2i(1224, 917));

    sf::Sprite First_Star(Star_SpriteSheet, Unearned_Stars_Coordiantes);
    sf::Sprite Second_Star(Star_SpriteSheet, Unearned_Stars_Coordiantes);
    sf::Sprite Third_Star(Star_SpriteSheet, Unearned_Stars_Coordiantes);

    setSize_Sprite(First_Star, sf::Vector2f(300, 300));
    setSize_Sprite(Second_Star, sf::Vector2f(300, 300));
    setSize_Sprite(Third_Star, sf::Vector2f(300, 300));

    First_Star.setOrigin(sf::Vector2f(First_Star.getLocalBounds().size.x / 2.0, First_Star.getLocalBounds().size.y / 2.0));
    Second_Star.setOrigin(sf::Vector2f(Second_Star.getLocalBounds().size.x / 2.0, Second_Star.getLocalBounds().size.y / 2.0));
    Third_Star.setOrigin(sf::Vector2f(Third_Star.getLocalBounds().size.x / 2.0, Third_Star.getLocalBounds().size.y / 2.0));

    First_Star.setPosition(sf::Vector2f(Wanted_View_Size.x / 2.0 - 300, 1 * Wanted_View_Size.y / 8.0 + 30)); // Correction,
    First_Star.rotate(sf::Angle(sf::degrees(-10)));                                                          // cosndiering 30 deg anticlockwise ; correction in sfml angles rotates clockwise
    Second_Star.setPosition(sf::Vector2f(Wanted_View_Size.x / 2.0, 1 * Wanted_View_Size.y / 8.0));
    Third_Star.setPosition(sf::Vector2f(Wanted_View_Size.x / 2.0 + 300, 1 * Wanted_View_Size.y / 8.0 + 30)); // a ,-, type shape
    Third_Star.rotate(sf::Angle(sf::degrees(+10)));

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

                    if (Sprite_has_cursor_on_it(Start_Button_Sprite, cursor_cordinates))
                    {

                        if (Level_Manager.CurrentLevelData.Act == 1)
                        {
                        }
                        else if (Level_Manager.CurrentLevelData.Act == 2)
                        {
                        }
                        else if (Level_Manager.CurrentLevelData.Act == 3)
                        {
                        }
                        else if (Level_Manager.CurrentLevelData.Act == 4)
                        {
                        }

                        // If left button pressed and cursor coordinates are in space of quit button, return 0
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

        // Now to see which stars will be on and which will be of
        int Stars_Earned = Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps->Stars;
        if (Stars_Earned == 0)
        {
            First_Star.setTextureRect(Unearned_Stars_Coordiantes);
            Second_Star.setTextureRect(Unearned_Stars_Coordiantes);
            Third_Star.setTextureRect(Unearned_Stars_Coordiantes);
        }
        else if (Stars_Earned == 1)
        {
            First_Star.setTextureRect(Earned_Stars_Coordiantes);
            Second_Star.setTextureRect(Unearned_Stars_Coordiantes);
            Third_Star.setTextureRect(Unearned_Stars_Coordiantes);
        }
        else if (Stars_Earned == 2)
        {
            First_Star.setTextureRect(Earned_Stars_Coordiantes);
            Second_Star.setTextureRect(Earned_Stars_Coordiantes);
            Third_Star.setTextureRect(Unearned_Stars_Coordiantes);
        }
        else if (Stars_Earned == 3)
        {
            First_Star.setTextureRect(Earned_Stars_Coordiantes);
            Second_Star.setTextureRect(Earned_Stars_Coordiantes);
            Third_Star.setTextureRect(Earned_Stars_Coordiantes);
        }

        window.draw(LevelSc_Bg_Sprite);

        window.draw(First_Star);
        window.draw(Second_Star);
        window.draw(Third_Star);

        window.draw(Start_Button_Sprite); // The buttons must be on top of bg else bg will hide them
        window.draw(Start_Button_Text);
        window.draw(Level_Act_Text);
        window.draw(Level_No_Text);
        window.draw(Level_Name_Text);
        window.draw(Level_Description_Text);

        window.display();
    }

    return 0;
}