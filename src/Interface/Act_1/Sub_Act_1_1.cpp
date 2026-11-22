// Bismillah hirahman nirahim

// This level will have the individual level logic inshallah

// #include "../Act_1.cpp"//must op out otherwise circular dependancy
#include "../UIManager.h"
#include "../../Graphics/LayoutEngine_M.cpp"
#include "../../Game Mechanics/AlarmMeter.cpp"
#include "../../Event Log/EventLog.cpp"
struct BT_Module_1 // cuz the bt isnt a struct so it cant auto delete, we need it to auto delete
{
    TreeNode *root = nullptr;
    int *Tree_In_Array_Form = nullptr;
    int NodeCapacity = 0;
    BT_Module_1(string Tree, int NodeCap)
    {
        this->NodeCapacity = NodeCap;
        root = makeBT(Tree, NodeCap, Tree_In_Array_Form);
    }
    ~BT_Module_1()
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

struct BT_Node_Sprite_Text_Combo_1
{
    sf::Sprite *Sprite_ptr;
    sf::Text *Text_ptr;
    TreeNode *Node_uo_ptr; // unowner
    bool Clicked = false;

    int Click()
    {
        Clicked = true;
        Sprite_ptr->setTextureRect(sf::IntRect(sf::Vector2i(531, 19), sf::Vector2i(485, 477)));
        return 1;
    }
    int Unlick()
    {
        Clicked = false;
        Sprite_ptr->setTextureRect(sf::IntRect(sf::Vector2i(24, 7), sf::Vector2i(485, 477)));
        return 1;
    }

    ~BT_Node_Sprite_Text_Combo_1()
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
struct Sprite_Double_Array_Act_1_1 // remade for this act
{
    // sf::Sprite **Sprite_Double_Ptr; // Tis is intitalized manually in code inshallah, we only need its destructor
    BT_Node_Sprite_Text_Combo_1 *NodeSTC_Array; // we also need to track text and accompanying node for a sprite so changed from sprte ** to sptr of this struct that holds ptr for sprite, text and treenode
    BT_Module_1 *BinTree = nullptr;             // This keeps a ptr to the bt
    TreeNode **BT_In_DoublePtr_Array_Form;
    sf::Texture Node_SpriteSheet_1_1;
    sf::Font Act_1_1_Font; // Issue I thik cuz font got deleted from emmeory cuz temo var hencer sprite printing issue Allah swt knows best ALhamudlilah rab al alameen
    int Clicked_count = 0;

    Sprite_Double_Array_Act_1_1(BT_Module_1 *BinT, sf::RenderWindow &window) // sees
    {
        BinTree = BinT; // issue fount BT was macro
        NodeSTC_Array = new BT_Node_Sprite_Text_Combo_1[BinTree->NodeCapacity];
        Tree_In_Array_Double_Ptr_Form(BinTree->root, BinTree->NodeCapacity, BT_In_DoublePtr_Array_Form);

        if (!Node_SpriteSheet_1_1.loadFromFile("../src/Assets/images/Act_1/Node_SpriteSheet.png"))
        {
            cout << "Couldnt load Node_SpriteSheet_1_1 " << endl;
        }

        sf::IntRect White_Node_Coordinates(sf::Vector2i(23, 21), sf::Vector2i(487, 463));

        if (!Act_1_1_Font.openFromFile("../src/Assets/fonts/CampaignMapSc/LuckiestGuy-Regular.ttf"))
        {
            cout << "Couldnt open Act_1_1_Font" << endl;
        }

        for (int i = 0; i < BinTree->NodeCapacity; i++)
        {
            NodeSTC_Array[i].Sprite_ptr = nullptr;
            NodeSTC_Array[i].Text_ptr = nullptr;

            if (BinTree->Tree_In_Array_Form[i] != -1)
            {
                NodeSTC_Array[i].Sprite_ptr = new sf::Sprite(Node_SpriteSheet_1_1, White_Node_Coordinates);
                NodeSTC_Array[i].Text_ptr = new sf::Text(Act_1_1_Font);
                NodeSTC_Array[i].Node_uo_ptr = BT_In_DoublePtr_Array_Form[i];
                NodeSTC_Array[i].Text_ptr->setString(Int_To_String(NodeSTC_Array[i].Node_uo_ptr->value));
                NodeSTC_Array[i].Text_ptr->setFillColor(sf::Color::Black);

                NodeSTC_Array[i].Sprite_ptr->setOrigin(sf::Vector2f(NodeSTC_Array[i].Sprite_ptr->getLocalBounds().size.x / 2, NodeSTC_Array[i].Sprite_ptr->getLocalBounds().size.y / 2));
                NodeSTC_Array[i].Text_ptr->setOrigin(sf::Vector2f(NodeSTC_Array[i].Text_ptr->getLocalBounds().size.x / 2 + NodeSTC_Array[i].Text_ptr->getLocalBounds().position.x, NodeSTC_Array[i].Text_ptr->getLocalBounds().size.y / 2 + NodeSTC_Array[i].Text_ptr->getLocalBounds().position.y));

                sf::Vector2f CurrentLoc;
                sf::Vector2f CurrentSize(0, 0);
                sf::Vector2f ParentLoc(0, 0); // Now we need to ensure that the further the child is from root the loser it is to its parent in y, to make space for toher nodes
                if (i == 0)
                {
                    CurrentLoc.x = 70;
                    CurrentLoc.y = window.getView().getSize().y / 2;

                    Find_Sprite_Loc_And_Size(true, sf::Vector2f(0, 0), window, BinTree->NodeCapacity, CurrentLoc, CurrentSize, false, i);

                } // some paramters become dummy if root
                else
                {

                    ParentLoc = NodeSTC_Array[(i - 1) / 2].Sprite_ptr->getPosition();
                    Find_Sprite_Loc_And_Size(false, ParentLoc, window, BinTree->NodeCapacity, CurrentLoc, CurrentSize, i % 2 == 1, i); // TO be more acurate a left child is always at an odd index // To detect if this node is left child or not, we simply do !ceil((i-1)/2.0), if it was a left child eg 1 => 0/2 =0 , !0 ->1 ; if right child eg 2, 1/2 =?0.5 ->ceil=> 1->!(!) =0
                }

                NodeSTC_Array[i].Sprite_ptr->setPosition(CurrentLoc);

                setSize_Sprite(*NodeSTC_Array[i].Sprite_ptr, CurrentSize);

                if (i == 1)
                {
                    setSize_Sprite(*NodeSTC_Array[i].Sprite_ptr, sf::Vector2f(CurrentSize.x * 7, CurrentSize.y * 7));
                }

                NodeSTC_Array[i].Text_ptr->setPosition(CurrentLoc); // lets orign centre before this inshallah
                setSize_Sprite(*NodeSTC_Array[i].Sprite_ptr, sf::Vector2f(CurrentSize.x / 2, CurrentSize.y / 2));

                if (NodeSTC_Array[i].Sprite_ptr == nullptr)
                {
                    cout << "Couldnt initialize sprite" << endl;
                }
            }
        }
    }
    ~Sprite_Double_Array_Act_1_1() // forgot to but the ~ tilda and it thought we were trying to ovcerload same parameter constructor;
    {
        if (NodeSTC_Array != nullptr) // Also you cant overalaod same calss destructor
        {

            cout << "Deleting the NodeSTC_Array  array" << endl;
            delete[] NodeSTC_Array; // this calls the destuctor fir each nodeSTC in this array
        } // unlike old verison usied in uimanger this one owns reach sprite
        delete[] BT_In_DoublePtr_Array_Form; // this just holds ptr to nodes in indexed form
    }

    void Reset_Clicks()
    {
        Clicked_count = 0;
        for (int i = 0; i < BinTree->NodeCapacity; i++)
        {
            if (NodeSTC_Array[i].Sprite_ptr != nullptr)
            {
                NodeSTC_Array[i].Unlick();
            }
        }
    }

    void Draw_On(sf::RenderWindow &window)
    {
        if (NodeSTC_Array == nullptr)
        {
            return;
        }
        for (int i = 0; i < BinTree->NodeCapacity; i++)
        {
            // cout << "+++++++++++++++++++++ " << i << endl;
            if (NodeSTC_Array[i].Sprite_ptr == nullptr || NodeSTC_Array->Text_ptr == nullptr)
            {
                continue;
            }
            window.draw(*NodeSTC_Array[i].Sprite_ptr);
            window.draw(*NodeSTC_Array[i].Text_ptr);
            // cout << "------------------- " << i << endl;
        }
    }
};

struct Int_Array_2
{

    int size = 0;
    int top = -1;
    int *Array_id;
    int *Array_value;

    Int_Array_2(int size)
    {
        this->size = size; // this was the issue Alhamdulilah
        Array_id = new int[size];
        Array_value = new int[size];
    }

    int Add_Value(int Value, int id)
    {
        if (Array_id != nullptr && Array_value != nullptr)
        {

            if (top != size - 1)
            {
                // cout << "Stroring " << Value << " in index: " << top + 1 << endl;

                Array_value[++top] = Value;
                Array_id[top] = id; // i see they were desynced ALhamdulilah
            }
            else
            {
                cout << "Space was full" << endl;
            }
            return 1;
        } // if eeven  the ret statement then still window doesnt open ... hm Allah swt knows best ALhamdulilah rab al alameen oh allah please guide me ameen
        return 0;
    }

    ~Int_Array_2()
    {
        if (Array_id != nullptr && Array_value != nullptr)
        {
            cout << "Deleteion INt array 2" << endl;
            delete[] Array_id;
            delete[] Array_value; // issue found Alhamdulilah; had used delte isntead of delte[] and forg0t to dlete value, and had odubke delted id
        }
    }
};

int Sub_Act_1_1(sf::RenderWindow &window, LevelManager &Level_Manager, int Current_Level, sf::Sprite &Act_1_Bg_Sprite)
{

    string Tree = Level_Manager.CurrentLevelData.Tree;
    cout << "||||||||||||||||||||||||||||||||||||||" << endl;
    cout << Tree << endl;

    // TreeNode *Root = makeBT(Tree);

    BT_Module_1 Bin_T(Tree, Level_Manager.CurrentLevelData.NodeCapacity); // for some reason BT (macro didnt give issue as name for this ( i think replaces with empty spadce so no issue))
    cout << "Bin_T int array root: ";

    cout << "Node Capacity: " << Bin_T.NodeCapacity << endl;

    for (int i = 0; i << Bin_T.NodeCapacity; i++)
    {
        cout << Bin_T.Tree_In_Array_Form[i] << " ";
    }
    cout << endl;

    Sprite_Double_Array_Act_1_1 NodeSprite_Array(&Bin_T, window);

    cout << "NodeSprite_Array ** root: ";

    for (int i = 0; i << Bin_T.NodeCapacity; i++)
    {
        if (NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr != nullptr)
            cout << NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr->value << " ";
        else
            cout << "# ";
    }
    cout << endl;

    Int_Array_2 User_Traversal(Level_Manager.CurrentLevelData.nodeCount);

    int *Preorder_Traversal_id = nullptr;
    int *Preorder_Traversal_value = nullptr;
    int temp_Current_Index_For_Preorder = 0;
    Give_Preorder_Traversal_Int_Array_id_val(Preorder_Traversal_id, Preorder_Traversal_value, Level_Manager.CurrentLevelData.nodeCount, Bin_T.root, temp_Current_Index_For_Preorder);
    Int_Array_2 Preoder_Traversal(Bin_T.NodeCapacity);
    Preoder_Traversal.Array_id = Preorder_Traversal_id;
    Preoder_Traversal.Array_value = Preorder_Traversal_value;

    int *Inorder_Traversal_id = nullptr;
    int *Inorder_Traversal_value = nullptr;
    int temp_Current_Index_For_Inorder = 0;
    Give_Inorder_Traversal_Int_Array_id_val(Inorder_Traversal_id, Inorder_Traversal_value, Level_Manager.CurrentLevelData.nodeCount, Bin_T.root, temp_Current_Index_For_Inorder);
    Int_Array_2 Inorder_Traversal(Bin_T.NodeCapacity);
    Inorder_Traversal.Array_id = Inorder_Traversal_id;
    Inorder_Traversal.Array_value = Inorder_Traversal_value;

    int *Postorder_Traversal_id = nullptr;
    int *Postorder_Traversal_value = nullptr;
    int temp_Current_Index_For_Postorder = 0;
    Give_Postorder_Traversal_Int_Array_id_val(Postorder_Traversal_id, Postorder_Traversal_value, Level_Manager.CurrentLevelData.nodeCount, Bin_T.root, temp_Current_Index_For_Postorder);
    Int_Array_2 Postorder_Traversal(Bin_T.NodeCapacity);
    Postorder_Traversal.Array_id = Postorder_Traversal_id;
    Postorder_Traversal.Array_value = Postorder_Traversal_value;

    int Which_Traversal_Checking = 1; // Starts with pre order then inorder then pos order

    sf::Font Act_1_1_Font;
    if (!Act_1_1_Font.openFromFile("../src/Assets/fonts/CampaignMapSc/LuckiestGuy-Regular.ttf"))
    {
        cout << "Couldnt open Act_1_1_Font" << endl;
    }
    sf::Text Order_Text(Act_1_1_Font);
    Order_Text.setString("Traverse in PreOrder");
    Order_Text.setFillColor(sf::Color::Black);
    // Order_Text.setOrigin(sf::Vector2f(Order_Text.getLocalBounds().size.x / 2 + Order_Text.getLocalBounds().position.x, Order_Text.getLocalBounds().size.y / 2 + Order_Text.getLocalBounds().position.y));
    Order_Text.scale(sf::Vector2f(2, 2));
    Order_Text.setPosition(sf::Vector2f(100, 100));

    sf::Text Result_Text(Act_1_1_Font);
    Result_Text.setString("Empty");
    Result_Text.setFillColor(sf::Color::Red);
    // Result_Text.setOrigin(sf::Vector2f(Result_Text.getLocalBounds().size.x / 2 + Result_Text.getLocalBounds().position.x, Result_Text.getLocalBounds().size.y / 2 + Result_Text.getLocalBounds().position.y));
    Result_Text.scale(sf::Vector2f(3, 3));
    Result_Text.setPosition(sf::Vector2f(80, 700));

    bool Display_Result = false;

    int optimal_steps = Level_Manager.CurrentLevelData.nodeCount * 3;
    AlarmMeter Alarm(optimal_steps);
    sf::Text Alarm_Text(Act_1_1_Font);
    Alarm_Text.setString("Empty");
    Alarm_Text.setFillColor(sf::Color::Red);
    // Result_Text.setOrigin(sf::Vector2f(Result_Text.getLocalBounds().size.x / 2 + Result_Text.getLocalBounds().position.x, Result_Text.getLocalBounds().size.y / 2 + Result_Text.getLocalBounds().position.y));
    Alarm_Text.scale(sf::Vector2f(2, 2));
    Alarm_Text.setPosition(sf::Vector2f(window.getView().getSize().x - 380, window.getView().getSize().y - 190));

    sf::Text Score_Text(Act_1_1_Font);
    Score_Text.setString("Empty");
    Score_Text.setFillColor(sf::Color::Blue);
    // Result_Text.setOrigin(sf::Vector2f(Result_Text.getLocalBounds().size.x / 2 + Result_Text.getLocalBounds().position.x, Result_Text.getLocalBounds().size.y / 2 + Result_Text.getLocalBounds().position.y));
    Score_Text.scale(sf::Vector2f(2, 2));
    Score_Text.setPosition(sf::Vector2f(window.getView().getSize().x - 380, window.getView().getSize().y - 250));

    EventModel Event_Log;

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

                    for (int i = 0; i < Bin_T.NodeCapacity; i++)
                    {
                        // cout << "t-2" << endl;
                        if (NodeSprite_Array.NodeSTC_Array[i].Sprite_ptr != nullptr)
                        {
                            // cout << "t-1" << endl;
                            if (Sprite_has_cursor_on_it(*NodeSprite_Array.NodeSTC_Array[i].Sprite_ptr, cursor_cordinates))
                            {
                                // cout << "t0" << endl;
                                if (NodeSprite_Array.NodeSTC_Array[i].Clicked == false)
                                {

                                    Alarm.addStep();
                                    Display_Result = false;
                                    NodeSprite_Array.NodeSTC_Array[i].Click();
                                    // cout << "t1" << endl;
                                    NodeSprite_Array.Clicked_count++;
                                    // cout << "t2" << endl;
                                    // cout << "Adding in user Traversal_+)@$I_)I_I: " << NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr->value << " " << NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr->id << endl;
                                    User_Traversal.Add_Value(NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr->value, NodeSprite_Array.NodeSTC_Array[i].Node_uo_ptr->id);
                                    // cout << "Stored: " << User_Traversal.Array_value[User_Traversal.top] << " " << User_Traversal.Array_id[User_Traversal.top] << endl;
                                    //  cout << "t3" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }

        // cout << "t6" << endl;
        if (NodeSprite_Array.Clicked_count == Level_Manager.CurrentLevelData.nodeCount && Which_Traversal_Checking < 4)
        {
            // Get actural traversal and compare
            NodeSprite_Array.Reset_Clicks();

            if (Which_Traversal_Checking == 1)
            {
                bool equal = true;
                for (int i = 0; i < Level_Manager.CurrentLevelData.nodeCount; i++)
                {
                    cout << "User Traversal: " << User_Traversal.Array_value[i] << " Preorder Traversal:" << Preoder_Traversal.Array_value[i] << endl;
                    cout << "User Traversal id: " << User_Traversal.Array_id[i] << " Preorder Traversal id:" << Preoder_Traversal.Array_id[i] << endl;

                    if (User_Traversal.Array_value[i] != Preoder_Traversal.Array_value[i])
                    {
                        equal = false; // oh issue may be
                    }
                    cout << "node count: " << Level_Manager.CurrentLevelData.nodeCount << endl;
                    cout << "Equal Sattsu ::::::::::::::::;;;" << equal << endl;
                }
                if (equal == true)
                {
                    Result_Text.setString("Preorder Success");
                }
                else
                {
                    Result_Text.setString("Preorder Failure");
                }

                Order_Text.setString("Inorder Traversal");
            }
            else if (Which_Traversal_Checking == 2)
            {
                bool equal = true;
                for (int i = 0; i < Level_Manager.CurrentLevelData.nodeCount; i++)
                {
                    if (User_Traversal.Array_value[i] != Inorder_Traversal.Array_value[i])
                    {
                        equal = false;
                    }
                }
                if (equal == true)
                {
                    Result_Text.setString("Inorder Success");
                }
                else
                {
                    Result_Text.setString("Inorder Failure");
                }

                Order_Text.setString("Postorder Traversal");
            }
            else if (Which_Traversal_Checking == 3)
            {
                bool equal = true;
                for (int i = 0; i < Level_Manager.CurrentLevelData.nodeCount; i++)
                {

                    if (User_Traversal.Array_value[i] != Postorder_Traversal.Array_value[i])
                    {
                        equal = false;
                    }
                }
                if (equal == true)
                {
                    Result_Text.setString("Postorder Success");
                }
                else
                {
                    Result_Text.setString("Post Failure");
                }
            }
            User_Traversal.top = -1;
            Display_Result = true;
            Which_Traversal_Checking++;
            if (Which_Traversal_Checking == 4)
            {
                Order_Text.setString("The End");
                Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level].score = Alarm.score();
                Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level].Stars = Alarm.stars();

                if (Current_Level < Level_Manager.Catalog.No_of_Levels && Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level].Stars != 0)
                {

                    Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Current_Level + 1].Unlock();
                }
            }
        }

        // Now for real time keyboard input
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) // This bypasses the poll queue to directly reaad state of keyboard
        {
            NodeSprite_Array.NodeSTC_Array[3].Sprite_ptr->move(sf::Vector2f(1, 0));
        }*/

        // cout << "Crash test 1" << endl;

        window.draw(Act_1_Bg_Sprite);
        if (Display_Result == true)
        {
            window.draw(Result_Text);
        }

        string Alarm_String = "Alarm: ";

        Alarm_String += Int_To_String(Alarm.steps);
        Alarm_String += '/';
        Alarm_String += Int_To_String(Alarm.capacity);

        Alarm_Text.setString(Alarm_String);

        string Score_String = "Score: ";
        Score_String += Int_To_String(Alarm.score());
        // NodeSprite_Array.Draw_On(window);
        // window.draw(*NodeSprite_Array.NodeSTC_Array[0].Sprite_ptr);
        Score_Text.setString(Score_String);
        /*
        if (NodeSprite_Array.NodeSTC_Array[0].Sprite_ptr == nullptr)
        {
            cout << "initialization issue:" << endl;
        }
        else
        {
            cout << "Size" << NodeSprite_Array.NodeSTC_Array[0].Sprite_ptr->getGlobalBounds().size.x << endl;
            cout << "pos" << NodeSprite_Array.NodeSTC_Array[0].Sprite_ptr->getGlobalBounds().position.x << endl;
        }
        window.draw(*NodeSprite_Array.NodeSTC_Array[0].Sprite_ptr);*/

        NodeSprite_Array.Draw_On(window);
        window.draw(Order_Text);
        window.draw(Alarm_Text); // window.draw(*NodeSprite_Array.NodeSTC_Array[1].Sprite_ptr);
        window.draw(Score_Text);
        // window.draw(*NodeSprite_Array.NodeSTC_Array[2].Sprite_ptr);

        // for (int i = 0; i < 5; i++)
        //     cout << "pos " << i << NodeSprite_Array.NodeSTC_Array[i].Sprite_ptr->getPosition().x << " " << NodeSprite_Array.NodeSTC_Array[i].Sprite_ptr->getPosition().y << endl;

        window.display();
    }
    return 1;
}