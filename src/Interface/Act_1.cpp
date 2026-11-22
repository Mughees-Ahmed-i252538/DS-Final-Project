// Bismillah hirahman nirahim

// This folder will have act 1 logic inshallah
// If circular inclusion is present, the file included first in main musth have inclusoin guards
// else cirfualr inclusionl.... issue

#include "UIManager.h"
#include "../Game Mechanics/LevelManager.cpp"
#include "../Data Structures/functions.cpp"
#include "Act_1/Sub_Act_1_1.cpp"
#include "Act_1/Sub_Act_1_2.cpp"
#include "Act_1/Sub_Act_1_3.cpp"
#include "Act_1/Sub_Act_1_4.cpp"
#include "Act_1/Sub_Act_1_5.cpp"

int Act_1(sf::RenderWindow &window, LevelManager &Level_Manager, int Current_Level)
{
    int Window_View_Size_x = window.getView().getSize().x; // these are needed to be able to set sizes of our sprites
    int Window_View_Size_y = window.getView().getSize().y;

    sf::Vector2f Wanted_View_Size(Window_View_Size_x, Window_View_Size_y);

    sf::Texture Act_1_Bg_Texture;

    if (!Act_1_Bg_Texture.loadFromFile("../src/Assets/images/Act_1/Act_1_Bg.png")) // starts from build folder
    {
        cout << "Failed to Load Act_1_Bg_Texture" << endl;
    } // issue: file suggestion offerned by intellesnece are relative to this file, but actual checks are relative to build folder.. it was mossing the src in file path
    // Unlikd this the #include is reolved at compile time so it uses location of including file as starter

    sf::Sprite Act_1_Bg_Sprite(Act_1_Bg_Texture); // No default cosntructor exsist hence must give texture at start

    /*
        string Tree = Level_Manager.CurrentLevelData.Tree;

        // TreeNode *Root = makeBT(Tree);

        BT_Module_2 Bin_T(Tree, Level_Manager.CurrentLevelData.NodeCapacity); // for some reason BT (macro didnt give issue as name for this ( i think replaces with empty spadce so no issue))

        Sprite_Double_Array_Act_1 NodeSprite_Array(&Bin_T); // to auto call destructor
    */
    // NodeSprite_Array.Sprite_Double_Ptr = new sf::Sprite *[Level_Manager.CurrentLevelData.NodeCapacity]; // This may change in endlessmode inshallah, note issue found, the sprite* array logi is in constructor and repeated here, so memeory leak, ALhamdulilah rab al alameen

    // Act_1_Bg_Sprite we cant directly set size, in sfml , we can set scale
    // This set scale is wrt its actual global size
    // So we make a set size helper function

    // setSize(Act_1_Bg_Sprite, Wanted_View_Size); // to serve as the bg we need it to take whole screen
    setBgSize(window, Act_1_Bg_Sprite); // Sees window view to set size directly ( helpef function)
                                        // I think we can make afucniton
                                        // Set bg using view if need be

    if (Level_Manager.CurrentLevelData.Sub_Act == 1)
    {
        Sub_Act_1_1(window, Level_Manager, Current_Level, Act_1_Bg_Sprite);
    }
    else if (Level_Manager.CurrentLevelData.Sub_Act == 2)
    {
        Sub_Act_1_2(window, Level_Manager, Current_Level, Act_1_Bg_Sprite);
    }
    else if (Level_Manager.CurrentLevelData.Sub_Act == 3)
    {
        Sub_Act_1_3(window, Level_Manager, Current_Level, Act_1_Bg_Sprite);
    }
    else if (Level_Manager.CurrentLevelData.Sub_Act == 4)
    {
        Sub_Act_1_4(window, Level_Manager, Current_Level, Act_1_Bg_Sprite);
    }
    else if (Level_Manager.CurrentLevelData.Sub_Act == 5)
    {
        Sub_Act_1_5(window, Level_Manager, Current_Level, Act_1_Bg_Sprite);
    }

    // while (window.isOpen()) // had done if instead of while, windows only opened for a brief moment
    // {
    //     while (std::optional event = window.pollEvent()) // This is the sfml 3 syntax, the 2 syntax was make an sf::Event event and do while(window.pollevent(event)), which is no longer usable as eents can no longer be empty (they did it to upgrade from c to c++ usage , it puts safety checks...)
    //     {                                                // And yes we can and are initializing a variable inside the paranthesis of while, i think if no event is present it returns std::nullopt the std::optional converts to false, (it converts to true if it holds a value), when it becomes false we get out of poll loop...
    //         if (event->is<sf::Event::Closed>())
    //         {
    //             return 0;
    //         } // Exit is working ALhamdulilah

    //         // Keyboard events
    //         if (sf::Event::KeyPressed *Key = event->getIf<sf::Event::KeyPressed>()) // KEypressed is a datatype
    //         {                                                                       // We use a * because it is able to be converted to bool
    //             // The getIf returns nullptr if event isnt KeyPressed, hence we wont run this block
    //             // More importantly getIf always returns a ptr const t*; t is a template placeholder, we made template keypressed
    //             // If event not of keypressed type it returns nullptr
    //             if (Key->code == sf::Keyboard::Key::Escape)
    //             {
    //                 return 0;
    //             }
    //         }
    //         else if (sf::Event::MouseButtonPressed *click = event->getIf<sf::Event::MouseButtonPressed>())
    //         {                                                                              // If mouse button pressed this block runs
    //             sf::Vector2f cursor_cordinates = window.mapPixelToCoords(click->position); // Because the position is in pixels, but we are using a view port so for us, the world is in coordinates; We need to convert pixels to coordinates

    //             if (click->button == sf::Mouse::Button::Left)
    //             {
    //                 // We do checks for if the cursor was on one of the buttons

    //                 /*
    //                 if (Sprite_has_cursor_on_it(Campaign_Button_ST.Sprite, cursor_cordinates))
    //                 {
    //                     CampaignMapSc(window, Level_Manager);
    //                 }

    //                 */
    //             }
    //         }
    //     }
    //     /*
    //     // Now for real time keyboard input
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) // This bypasses the poll queue to directly reaad state of keyboard
    //     {
    //         Button_pos_x += 1;
    //     }
    //     */
    //     //cout << "Crash test 1" << endl;
    //     window.draw(Act_1_Bg_Sprite);

    //     window.display();
    // }

    return 0; // Just a placeholder to remove the warning that comes, curretn logic doenst reach it and pretriggers
}
