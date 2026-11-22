// Bismillah hirahman nirahim

// This level will have the individual level logic inshallah

// #include "../Act_2.cpp"
#include "../UIManager.h"

struct BT_Module_5 // cuz the bt isnt a struct so it cant auto delete, we need it to auto delete
{
    TreeNode *root = nullptr;
    int *Tree_In_Array_Form = nullptr;
    int NodeCapacity = 0;
    BT_Module_5(string Tree, int NodeCap)
    {
        this->NodeCapacity = NodeCap;
        root = makeBT(Tree, NodeCap, Tree_In_Array_Form);
    }
    ~BT_Module_5()
    {
        cout << "Deleting the Bt module" << endl;
        DeleteTree(root);
        this->NodeCapacity = 0;
        if (Tree_In_Array_Form != nullptr)
        {
            delete Tree_In_Array_Form;
        }
    }
};

struct BT_Node_Sprite_Text_Combo_5
{
    sf::Sprite *Sprite_ptr;
    sf::Text *Text_ptr;
    TreeNode *Node_uo_ptr; // unowner

    ~BT_Node_Sprite_Text_Combo_5()
    {
        if (Sprite_ptr != nullptr)
        {
            delete Sprite_ptr;
        }
        if (Text_ptr != nullptr)
        {
            delete Text_ptr;
        } // the treenode is unowned
    }
};
struct Sprite_Double_Array_Act_1_5 // remade for this act
{
    // sf::Sprite **Sprite_Double_Ptr; // Tis is intitalized manually in code inshallah, we only need its destructor
    BT_Node_Sprite_Text_Combo_5 *NodeSTC_Array; // we also need to track text and accompanying node for a sprite so changed from sprte ** to sptr of this struct that holds ptr for sprite, text and treenode
    BT_Module_5 *BinTree = nullptr;             // This keeps a ptr to the bt

    Sprite_Double_Array_Act_1_5(BT_Module_5 *BinT) // sees
    {
        BinTree = BinT; // issue fount BT was macro
        NodeSTC_Array = new BT_Node_Sprite_Text_Combo_5[BinTree->NodeCapacity];
        for (int i = 0; i < BinTree->NodeCapacity; i++)
        {
            NodeSTC_Array[i].Sprite_ptr = nullptr;
            NodeSTC_Array[i].Text_ptr = nullptr;
        }
    }
    ~Sprite_Double_Array_Act_1_5() // forgot to but the ~ tilda and it thought we were trying to ovcerload same parameter constructor;
    {
        if (NodeSTC_Array != nullptr) // Also you cant overalaod same calss destructor
        {

            cout << "Deleting the NodeSTC_Array  array" << endl;
            delete[] NodeSTC_Array;
        } // unlike old verison usied in uimanger this one owns reach sprite
    }
};

int Sub_Act_1_5(sf::RenderWindow &window, LevelManager &Level_Manager, int Current_Level, sf::Sprite &Act_1_Bg_Sprite)
{
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
            }
            else if (sf::Event::MouseButtonPressed *click = event->getIf<sf::Event::MouseButtonPressed>())
            {                                                                              // If mouse button pressed this block runs
                sf::Vector2f cursor_cordinates = window.mapPixelToCoords(click->position); // Because the position is in pixels, but we are using a view port so for us, the world is in coordinates; We need to convert pixels to coordinates

                if (click->button == sf::Mouse::Button::Left)
                {
                    // We do checks for if the cursor was on one of the buttons

                    /*
                    if (Sprite_has_cursor_on_it(Campaign_Button_ST.Sprite, cursor_cordinates))
                    {
                        CampaignMapSc(window, Level_Manager);
                    }

                    */
                }
            }
        }
        /*
        // Now for real time keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            Button_pos_x += 1;
        }
        */
        // cout << "Crash test 1" << endl;
        window.draw(Act_1_Bg_Sprite);

        window.display();
    }
    return 1;
}