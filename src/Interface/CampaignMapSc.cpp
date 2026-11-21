// Bismillah hirahman nirahim
#include "UIManager.h"
#include "../Game Mechanics/LevelManager.cpp"
#include "LevelSc.cpp"
struct Orientation
{
        bool Text = false;
        int Level_Buttons = 0;
        int Act = 0;
        int First_Level_Number = -1; // This is refrence to catalog number
        // if it is -1 that means no level and vice versa
};

struct ScreenOrientations
{
        // The screen at one time can have
        // It sees no of levels
        // It also sees no of levels in acts
        // It leaves one screen for the act screen with

        LevelCatalog *Level_Catalog = nullptr; // This gets a ptr to the catalog
        // No of oritetations = 4 (for each act screen) + ceil(No of levels in Act 1/4 )
        int No_of_Orientations = 0;
        int Actwise_Orientations[4] = {0, 0, 0, 0};

        Orientation *Orientations;

        int Initialize_Orietations(LevelCatalog &lvlCat)
        {
                Level_Catalog = &lvlCat;
                if (lvlCat.Catalog_Of_Level_NFA_Maps == nullptr)
                {
                        cout << "Catalog is empty" << endl;
                        return 0;
                }
                // else

                cout << "ceil(lvlCat.Act_1_Levels / 4.0)" << ceil(lvlCat.Act_1_Levels / 4.0) << endl; // Issue found Alhamdulilah, when we do /4 it is int division cuz levlCat.Act_1_Levels is also an int, hence the .5 is removed before we ceil, Solution, do /4.0 instead before ceil; Alhamdulilah rab al alameen
                cout << "ceil(lvlCat.Act_2_Levels / 4.0)" << ceil(lvlCat.Act_2_Levels / 4.0) << endl;
                cout << "ceil(lvlCat.Act_3_Levels / 4.0)" << ceil(lvlCat.Act_3_Levels / 4.0) << endl;
                cout << "ceil(lvlCat.Act_4_Levels / 4.0)" << ceil(lvlCat.Act_4_Levels / 4.0) << endl;
                cout << "4 + ceil(lvlCat.Act_1_Levels / 4.0) + ceil(lvlCat.Act_2_Levels / 4.0) + ceil(lvlCat.Act_3_Levels / 4.0) + ceil(lvlCat.Act_4_Levels / 4.0): " << 4 + ceil(lvlCat.Act_1_Levels / 4.0) + ceil(lvlCat.Act_2_Levels / 4.0) + ceil(lvlCat.Act_3_Levels / 4.0) + ceil(lvlCat.Act_4_Levels / 4.0) << endl;

                No_of_Orientations = 4 + ceil(lvlCat.Act_1_Levels / 4.0) + ceil(lvlCat.Act_2_Levels / 4.0) + ceil(lvlCat.Act_3_Levels / 4.0) + ceil(lvlCat.Act_4_Levels / 4.0);

                Actwise_Orientations[0] = 1 + ceil(lvlCat.Act_1_Levels / 4.0); // The first one is for the text screen
                Actwise_Orientations[1] = 1 + ceil(lvlCat.Act_1_Levels / 4.0);
                Actwise_Orientations[2] = 1 + ceil(lvlCat.Act_1_Levels / 4.0);
                Actwise_Orientations[3] = 1 + ceil(lvlCat.Act_1_Levels / 4.0);

                Orientations = new Orientation[No_of_Orientations];

                int Current_Orientation = 0;
                int Current_Act = 1;
                int Levels_In_Acts[4] = {lvlCat.Act_1_Levels, lvlCat.Act_2_Levels, lvlCat.Act_3_Levels, lvlCat.Act_4_Levels};
                int First_Level_Num_Tracker = 0;

                for (int j = 0; j < 4; j++)
                {

                        Orientations[Current_Orientation].Act = Current_Act;
                        Orientations[Current_Orientation].Text = true;
                        Orientations[Current_Orientation].Level_Buttons = 0;
                        Orientations[Current_Orientation].First_Level_Number = -1;
                        Current_Orientation++;

                        for (int i = 1; i < Actwise_Orientations[j] - 1; i++) // the -1 is cuz the first one is the text orientation
                        {
                                Orientations[Current_Orientation].Act = Current_Act;
                                Orientations[Current_Orientation].Text = false;
                                Orientations[Current_Orientation].Level_Buttons = 4;
                                Orientations[Current_Orientation].First_Level_Number = First_Level_Num_Tracker;
                                First_Level_Num_Tracker += 4; // Cuz this level has 4 level buttons

                                Current_Orientation++;
                        }
                        // Now for the last node of the level

                        if (Levels_In_Acts[j] % 4 == 0) // Divsioble by 4; Means last node will have 4 levels
                        {
                                Orientations[Current_Orientation].Act = Current_Act;
                                Orientations[Current_Orientation].Text = false;
                                Orientations[Current_Orientation].Level_Buttons = 4;
                                Orientations[Current_Orientation].First_Level_Number = First_Level_Num_Tracker;
                                First_Level_Num_Tracker += 4;
                                Current_Orientation++;
                        }
                        else
                        {
                                // if not divisible by 4, the last level will have buttons = remained after div by 3
                                Orientations[Current_Orientation].Act = Current_Act;
                                Orientations[Current_Orientation].Text = false;
                                Orientations[Current_Orientation].Level_Buttons = Levels_In_Acts[j] % 4;
                                Orientations[Current_Orientation].First_Level_Number = First_Level_Num_Tracker;
                                First_Level_Num_Tracker += Levels_In_Acts[j] % 4;
                                Current_Orientation++;
                        }
                        Current_Act++;
                }
                return 1; // was missing returan 1 hence crashed Alhamdulilah fixed
        }

        void Delete_Orietations() // so we can call destructor customly
        {
                Level_Catalog = nullptr;
                No_of_Orientations = 0;
                Actwise_Orientations[0] = 0;
                Actwise_Orientations[1] = 0;
                Actwise_Orientations[2] = 0;
                Actwise_Orientations[3] = 0;

                if (Orientations != nullptr)
                {
                        delete Orientations;
                }
        }

        ~ScreenOrientations() // If class name wrong gives wrong
        {
                Delete_Orietations();
        }
};

struct Sprite_Double_Array
{
        sf::Sprite **Sprite_Double_Ptr; // Tis is intitalized manually in code inshallah, we only need its destructor

        Sprite_Double_Array()
        {
                Sprite_Double_Ptr = nullptr;
        }
        ~Sprite_Double_Array() // forgot to but the ~ tilda and it thought we were trying to ovcerload same parameter constructor;
        {
                if (Sprite_Double_Ptr != nullptr) // Also you cant overalaod same calss destructor
                {
                        delete Sprite_Double_Ptr;
                }
        }
};

int CampaignMapSc(sf::RenderWindow &window, LevelManager &Level_Manager) // This interacts with campaign map, level manager
{

        int LoadCatRet = Level_Manager.loadCatalogue();
        Level_Manager.Catalog.Set_Default_CampaignStartCondition(); // This function sets first level to unlocked and sets rest of levels unlocked, it also sets dfault stars to 0 Alhamdulilah rab al alameen
        //*Erros by load Catalog, to be handled later if time inshallah
        ScreenOrientations ScreenOrientations;
        ScreenOrientations.Initialize_Orietations(Level_Manager.Catalog); // Sees no of levels and makes screen nodes according to that
        cout << "No of Levels: " << Level_Manager.Catalog.No_of_Levels << endl;
        cout << "No of Act 1 Levels: " << Level_Manager.Catalog.Act_1_Levels << endl;
        cout << "No of Act 2 Levels: " << Level_Manager.Catalog.Act_2_Levels << endl;
        cout << "No of Act 3 Levels: " << Level_Manager.Catalog.Act_3_Levels << endl;
        cout << "No of Act 4 Levels: " << Level_Manager.Catalog.Act_4_Levels << endl;
        cout << "No of Screen Orientations" << ScreenOrientations.No_of_Orientations << endl;
        cout << "No of Act 1 Screen Orientations" << ScreenOrientations.Actwise_Orientations[0] << endl;
        cout << "No of Act 2 Screen Orientations" << ScreenOrientations.Actwise_Orientations[1] << endl;
        cout << "No of Act 3 Screen Orientations" << ScreenOrientations.Actwise_Orientations[2] << endl;
        cout << "No of Act 4 Screen Orientations" << ScreenOrientations.Actwise_Orientations[3] << endl; // For some reason the last act of each oritation acts sequess.... Meaning to say the last act of 2,3,4 series of acts giving 1 isntead of their series acts; issues was hardcoded 1 in one place (The %4 !=0 place)Alhamdulilah rab al alameen
        cout << "Orientation Acts: ";
        for (int i = 0; i < ScreenOrientations.No_of_Orientations; i++)
        {
                cout << ScreenOrientations.Orientations[i].Act << " " << endl;
        }

        cout << endl;
        // The display sees the screen orietation and selects what to display
        // The level buttons get created, given a level number
        // And help trigger the load current level and call level screen after sending the Level Manager with Current Level loaded
        // which sends it back after unloading

        int Window_View_Size_x = window.getView().getSize().x; // these are needed to be able to set sizes of our sprites
        int Window_View_Size_y = window.getView().getSize().y;

        sf::Vector2f Wanted_View_Size(Window_View_Size_x, Window_View_Size_y);

        sf::Texture CampaignMapSc_Bg_Textures[4];

        if (!CampaignMapSc_Bg_Textures[0].loadFromFile("../src/Assets/images/CampaignMapSc/Act_1Sc.png")) // starts from build folder
        {
                cout << "Failed to Load CampaignMapSc_Bg_Textures For Act 1" << endl;
        } // issue: file suggestion offerned by intellesnece are relative to this file, but actual checks are relative to build folder.. it was mossing the src in file path
        // Unlikd this the #include is reolved at compile time so it uses location of including file as starter
        if (!CampaignMapSc_Bg_Textures[1].loadFromFile("../src/Assets/images/CampaignMapSc/Act_2Sc.jpg")) // starts from build folder
        {
                cout << "Failed to Load CampaignMapSc_Bg_Textures For Act 2" << endl;
        }
        if (!CampaignMapSc_Bg_Textures[2].loadFromFile("../src/Assets/images/CampaignMapSc/Act_3Sc.jpg")) // starts from build folder
        {
                cout << "Failed to Load CampaignMapSc_Bg_Textures For Act 3" << endl;
        }
        if (!CampaignMapSc_Bg_Textures[3].loadFromFile("../src/Assets/images/CampaignMapSc/Act_4Sc.jpg")) // starts from build folder
        {
                cout << "Failed to Load CampaignMapSc_Bg_Textures For Act 4" << endl;
        }
        // Planning to make a sprite array to not have to set tecxture in middle (gpu heavy if too much ), Issue is cant have default constructed sprite unless special measure like std::optional
        // We will do it using a sprite** inshallah
        sf::Sprite CampaignMapSc_Bg_Sprite_Act_1(CampaignMapSc_Bg_Textures[0]); // No default cosntructor exsist hence must give texture at start
        sf::Sprite CampaignMapSc_Bg_Sprite_Act_2(CampaignMapSc_Bg_Textures[1]);
        sf::Sprite CampaignMapSc_Bg_Sprite_Act_3(CampaignMapSc_Bg_Textures[2]); // No default cosntructor exsist hence must give texture at start
        sf::Sprite CampaignMapSc_Bg_Sprite_Act_4(CampaignMapSc_Bg_Textures[3]);

        Sprite_Double_Array CampaignMapSc_Bg_Sprites;
        CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr = new sf::Sprite *[4]; // issue is we use return 0 everytwhere, so doing so at funcition end isnt safe, solution, convert it to  a struct
        CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr[0] = &CampaignMapSc_Bg_Sprite_Act_1;
        CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr[1] = &CampaignMapSc_Bg_Sprite_Act_2; // only point as doesnt own, (although it is needed to delete the array of ptrs to sprites at end inshallah)
        CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr[2] = &CampaignMapSc_Bg_Sprite_Act_3;
        CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr[3] = &CampaignMapSc_Bg_Sprite_Act_4;

        // now i think seting texture everytime is more time taking than simply changing the index no
        int Current_Screen_Orientation = 0; // This is used to track what to display on screen
        // Same sprite we will simply change textures for screen change inshallah

        // MainSc_Bg_Sprite we cant directly set size, in sfml , we can set scale
        // This set scale is wrt its actual global size
        // So we make a set size helper function

        // setSize(MainSc_Bg_Sprite, Wanted_View_Size); // to serve as the bg we need it to take whole screen
        setBgSize(window, CampaignMapSc_Bg_Sprite_Act_1); // Sees window view to set size directly ( helpef function);
        setBgSize(window, CampaignMapSc_Bg_Sprite_Act_2); // Sees window view to set size directly ( helpef function);
        setBgSize(window, CampaignMapSc_Bg_Sprite_Act_3); // Sees window view to set size directly ( helpef function);
        setBgSize(window, CampaignMapSc_Bg_Sprite_Act_4); // Sees window view to set size directly ( helpef function);
        // We set them into bg size individually and use the CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr to dispaly them cuz it hlds their ptrs, Alhamdulilah rab al alameen

        // I think we can make afucniton
        // Set bg using view if need be

        // sf::Texture CMSc_Right_Arrow_Icon;

        sf::Font CMSc_Act_Label_Font;

        if (!CMSc_Act_Label_Font.openFromFile("../src/Assets/fonts/CampaignMapSc/LuckiestGuy-Regular.ttf")) // fonts use open from file insteado f load from file from sfml 3 because it streams on demand not store in memory
        {
                cout << "Failed to Open CMSc_Act_Label_Font" << endl;
        }

        sf::Text CMSc_Act_Label_Text(CMSc_Act_Label_Font); // now we cant make a text without a font i think Allah swt knows best Alhamdulilah rab al alameen
        CMSc_Act_Label_Text.setFillColor(sf::Color::Black);
        CMSc_Act_Label_Text.setString("Set"); // This is needed to be able to do set things  and everything

        CMSc_Act_Label_Text.setOrigin(sf::Vector2f(CMSc_Act_Label_Text.getGlobalBounds().size.x / 2, CMSc_Act_Label_Text.getGlobalBounds().size.y / 2)); // we need the global bounds which are the unmodified size so the orign math isnt messed up, origin is a point inside the sprite itself
        CMSc_Act_Label_Text.setPosition(sf::Vector2f((Wanted_View_Size.x / 2) - 40, (Wanted_View_Size.y / 2) - 40));                                     // Centre of screen, slightly higher

        CMSc_Act_Label_Text.setScale(sf::Vector2f(4, 4)); // Makes this much larger in x and y

        sf::Texture Blue_Right_Arrow;

        if (!Blue_Right_Arrow.loadFromFile("../src/Assets/images/CampaignMapSc/BlueRightArrow.png")) // fonts use open from file insteado f load from file from sfml 3 because it streams on demand not store in memory
        {
                cout << "Failed to Open CMSc_Act_Label_Font" << endl;
        }

        sf::Sprite Right_Arrow(Blue_Right_Arrow);
        Right_Arrow.setOrigin(sf::Vector2f(Right_Arrow.getGlobalBounds().size.x / 2, Right_Arrow.getGlobalBounds().size.y / 2));
        Right_Arrow.setPosition(sf::Vector2f(Wanted_View_Size.x - 50, Wanted_View_Size.y / 2)); // in the verticale middle, right end - a little
        setSize_Sprite(Right_Arrow, sf::Vector2f(120, 200));

        sf::Sprite Left_Arrow(Blue_Right_Arrow);
        Left_Arrow.setOrigin(sf::Vector2f(Left_Arrow.getGlobalBounds().size.x / 2, Left_Arrow.getGlobalBounds().size.y / 2));
        Left_Arrow.setPosition(sf::Vector2f(0 + 50, Wanted_View_Size.y / 2)); // left verticele-centre, slight more than screen end
        setSize_Sprite(Left_Arrow, sf::Vector2f(-120, 200));                  // if we set the size to -50 then it should flip in x direction inshallah

        // Yes Alhamdulilah flipping

        // If the oritation say text, this is displayed affter seting its string after seeing the oritation's Act no

        // ous bitton moves up by 10 next moves up by 20 to accomodate that space too

        // int Button_pos_x = Quit_Button_ST.Sprite.getPosition().x;
        // int Button_pos_y = Quit_Button_ST.Sprite.getPosition().y;

        // Now we need Sprite Text Boxes
        // We will have 4 or less on each oritation

        // Sprite sheet logic is:
        // Make a texture treat it as spreadsheet
        // Give internal coordinates of the internal sprite
        // While giving texture to sprite also include the subpart coordiantes (rectangle for internal cut coordiantes of sprite in spritesheet)//Allah swt knows best, Alhamdulilah rab al alameen

        sf::Texture Level_Icons_Spreadsheet;

        if (!Level_Icons_Spreadsheet.loadFromFile("../src/Assets/images/CampaignMapSc/Level_Icon_SpriteSheet.png"))
        {
                cout << "Couldnt load Level Icon Spreadsheet failed to load" << endl;
        }

        sf::IntRect LI_Locked_Level_Coordinates(sf::Vector2i(347, 192), sf::Vector2i(150, 147)); // start pos , size
        sf::IntRect LI_0_Star_Level_Coordinates(sf::Vector2i(184, 193), sf::Vector2i(150, 151));
        sf::IntRect LI_1_Star_Level_Coordinates(sf::Vector2i(507, 22), sf::Vector2i(150, 151));
        sf::IntRect LI_2_Star_Level_Coordinates(sf::Vector2i(347, 23), sf::Vector2i(150, 151));
        sf::IntRect LI_3_Star_Level_Coordinates(sf::Vector2i(184, 27), sf::Vector2i(150, 151));

        sf::Sprite Level_Icon_1(Level_Icons_Spreadsheet, LI_Locked_Level_Coordinates);
        sf::Sprite Level_Icon_2(Level_Icons_Spreadsheet, LI_Locked_Level_Coordinates);
        sf::Sprite Level_Icon_3(Level_Icons_Spreadsheet, LI_Locked_Level_Coordinates);
        sf::Sprite Level_Icon_4(Level_Icons_Spreadsheet, LI_Locked_Level_Coordinates); // Now must set size and position, but must set origin to centre first

        Level_Icon_1.setOrigin(sf::Vector2f(Level_Icon_1.getLocalBounds().size.x / 2, Level_Icon_1.getLocalBounds().size.y / 2)); // Must set orign to centre
        Level_Icon_2.setOrigin(sf::Vector2f(Level_Icon_2.getLocalBounds().size.x / 2, Level_Icon_2.getLocalBounds().size.y / 2));
        Level_Icon_3.setOrigin(sf::Vector2f(Level_Icon_3.getLocalBounds().size.x / 2, Level_Icon_3.getLocalBounds().size.y / 2));
        Level_Icon_4.setOrigin(sf::Vector2f(Level_Icon_4.getLocalBounds().size.x / 2, Level_Icon_4.getLocalBounds().size.y / 2));

        setSize_Sprite(Level_Icon_1, sf::Vector2f(300, 300));
        setSize_Sprite(Level_Icon_2, sf::Vector2f(300, 300));
        setSize_Sprite(Level_Icon_3, sf::Vector2f(300, 300));
        setSize_Sprite(Level_Icon_4, sf::Vector2f(300, 300));

        Level_Icon_1.setPosition(sf::Vector2f(1 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2)); // screen center, 1/4 from left, 4.0 so that float calculaation and acurate postition inshallah elsewise will give int div rersult
        Level_Icon_2.setPosition(sf::Vector2f(2 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2)); // 1/4 makes the last node at right corner
        Level_Icon_3.setPosition(sf::Vector2f(3 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2)); // trying 1/5 instead
        Level_Icon_4.setPosition(sf::Vector2f(4 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2)); // 1/5 *1, 2,3,4 is the distance we need, it puts 1 unit gap from each side as well, ALhamdulilah rab al alameen

        sf::Text Level_Label_1(CMSc_Act_Label_Font); // may use another font if like more inshallah, not decided yet if to display level label for a locked level as well, will look at design then discide inshallah
        sf::Text Level_Label_2(CMSc_Act_Label_Font);
        sf::Text Level_Label_3(CMSc_Act_Label_Font);
        sf::Text Level_Label_4(CMSc_Act_Label_Font);

        // Allah swt knows best, Alhamdulilah rab al alameen
        Level_Label_1.setString("1"); // This is needed to be able to set size I think so, Allah swt knows best,//Note set position and setScale works withempty screen but i think so, getlocal boudnds or getglobal bounds doesnt work(google search says so too), note: the setsize wfucnion we made uses global bounds. Allah swt knows best. .Alhamulilah rab al alameen
        Level_Label_2.setString("2"); // the . symbol appears quite below so no need for panic
        Level_Label_3.setString("3"); // Issue: because 1 and 10 are sclared to same level 1 is strencthed and appears bigger than 1 in 10 cuz we did set size
        Level_Label_4.setString("4");

        cout << "Local left of text" << Level_Label_1.getLocalBounds().position.x << " Local top of text: " << Level_Label_1.getLocalBounds().position.x << endl;
        cout << "local left of sprite" << Level_Icon_1.getLocalBounds().position.x << " local top of sprite: " << Level_Icon_1.getLocalBounds().position.x << endl;
        Level_Label_1.setOrigin(sf::Vector2f(Level_Label_1.getLocalBounds().size.x / 2.0 + Level_Label_1.getLocalBounds().position.x, Level_Label_1.getLocalBounds().size.y / 2 + Level_Label_1.getLocalBounds().position.y));
        Level_Label_2.setOrigin(sf::Vector2f(Level_Label_2.getLocalBounds().size.x / 2 + Level_Label_2.getLocalBounds().position.x, Level_Label_2.getLocalBounds().size.y / 2 + Level_Label_2.getLocalBounds().position.y)); // Issue found Alhamdulilah, unlike sprites, for text, the defualt orign isnt at the top left for text
        Level_Label_3.setOrigin(sf::Vector2f(Level_Label_3.getLocalBounds().size.x / 2 + Level_Label_3.getLocalBounds().position.x, Level_Label_3.getLocalBounds().size.y / 2 + Level_Label_3.getLocalBounds().position.y)); // For text even in the local bounds (its actual coordiantes), the top isnt =0. meaning to say without us traslating it around the top and left for a text exsists at -1 each. Hence although by defaykt we are us9ng 0,0 for its positionsing the actual visual space it has has an extra buffer to the top and left whic must be accounted for in calcualtion
        Level_Label_4.setOrigin(sf::Vector2f(Level_Label_4.getLocalBounds().size.x / 2 + Level_Label_4.getLocalBounds().position.x, Level_Label_4.getLocalBounds().size.y / 2 + Level_Label_4.getLocalBounds().position.y)); // Self correcction , get locla bounds get the raw coordinates, not get global bounds
        // becuase the top is -1 even in texts  local bounds, size isnt =bottom -0; middpoint which is bottom+top/2 cant be written as (size-0 + 0)/2, the two orignally 0 factors appear as -1 each each is a half ,tigether theybgive 1
        // because size is from top to bottom
        // Top is -1
        // bottom is 9
        // size is 10
        // the middle point of -1 and 9  is -1+9 /2 (by average and not by distance formula, rather than this we can also do system tralstion ,tralste x +=1, then reult are tralted +=1)
        //  again we got the middle point using the mid point forma which is start+end/2 (came from the x2(k1) + x1(k2)/k1+k2)= -1+9 /2 =4 , but 10/2 =5 , cuz it didnt account for top, (size = buttom -top), buttom = top +size, middlepoint = buttom +top /2 = bottom/2 + top/2= (top+size)/2 + top/2 =2 * top/2 + size/2=top+(size/2) formula derived Alhamdulilah rab al alameen
        // but doing size

        // setSize_Text(Level_Label_1, sf::Vector2f(200, 100)); // Made 100 less in x and 200 less in y, from icon itself, Alhamdulilah rab al alameen
        // setSize_Text(Level_Label_2, sf::Vector2f(200, 100));
        // setSize_Text(Level_Label_3, sf::Vector2f(200, 100));
        // setSize_Text(Level_Label_4, sf::Vector2f(200, 100));

        Level_Label_1.setPosition(sf::Vector2f(1 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2.0)); // screen center, 1/4 from left, 4.0 so that float calculaation and acurate postition inshallah elsewise will give int div rersult
        Level_Label_2.setPosition(sf::Vector2f(2 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2.0)); // 1/4 makes the last node at right corner
        Level_Label_3.setPosition(sf::Vector2f(3 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2.0)); // trying 1/5 instead
        Level_Label_4.setPosition(sf::Vector2f(4 * Wanted_View_Size.x / 5.0, Wanted_View_Size.y / 2.0)); // had accidenly done call for same label again anda gain

        // For some reasons levels higher than 9 go towards righter side cuz their string were set in the loop, Allah swt knows best perhaps we have to re centre them by puting set position in this? May Allah swt help us Ameen
        // Will fix if time inshallah
        Level_Label_1.setScale(sf::Vector2f(3.0, 3.0));
        Level_Label_2.setScale(sf::Vector2f(3.0, 3.0));
        Level_Label_3.setScale(sf::Vector2f(3.0, 3.0)); // issues solved chaned all 1's to 1,2,3,4 Alhamdulilah
        Level_Label_4.setScale(sf::Vector2f(3.0, 3.0)); // because setsize causes 1 to be bigger than 1 in 10, as we are doing relative scaling, to solve issue we do absolute scaling, so instead of 1 appearing bigger than 1 in 10, 1 in 1 and 1 in 10 are scaled similarly inshallah

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

                                if (Key->code == sf::Keyboard::Key::Right)
                                {
                                        if (Current_Screen_Orientation != ScreenOrientations.No_of_Orientations - 1) // if it gets to last orientation dont go to next
                                        {
                                                Current_Screen_Orientation++;
                                        }
                                }
                                if (Key->code == sf::Keyboard::Key::Left)
                                {
                                        if (Current_Screen_Orientation != 0)
                                        {
                                                Current_Screen_Orientation--;
                                        }
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
                        {                                                                                  // If mouse button pressed this block runs
                                sf::Vector2f cursor_cordinates = window.mapPixelToCoords(click->position); // Because the position is in pixels, but we are using a view port so for us, the world is in coordinates; We need to convert pixels to coordinates

                                if (click->button == sf::Mouse::Button::Left)
                                {
                                        // We do checks for if the cursor was on one of the buttons

                                        /*
                                        if (Sprite_has_cursor_on_it(Quit_Button_ST.Sprite, cursor_cordinates))
                                        {
                                                return 0; // If left button pressed and cursor coordinates are in space of quit button, return 0
                                        }
                                        else if (Sprite_has_cursor_on_it(Campaign_Button_ST.Sprite, cursor_cordinates))
                                        {
                                        }
                                        */

                                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 1) // Firstly we ensure the node is visual so we dont interact with a phanton node
                                        {
                                                int Icon_1_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 0; // We get its level just in case (it is very useful if we are to perform actins using Catalog, Alhamdulilah rab al alameen)
                                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked)
                                                { // The we confirm it isnt locked, only then you can interact with it, Alhamdulilah rab al alameen
                                                        if (Sprite_has_cursor_on_it(Level_Icon_1, cursor_cordinates))
                                                        {
                                                                Level_Manager.loadLevel(Icon_1_lvl_No); // Load the current level
                                                                // And send it to the level Screen
                                                                //..Alhamdulilah rab al alameen
                                                                LevelSc(window, Level_Manager, Icon_1_lvl_No);
                                                                Level_Manager.CurrentLevelData.deleteData();
                                                        }
                                                }
                                        }
                                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 2)
                                        {
                                                int Icon_2_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 1; // We get its level just in case (it is very useful if we are to perform actins using Catalog, Alhamdulilah rab al alameen)
                                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Locked)
                                                { // The we confirm it isnt locked, only then you can interact with it, Alhamdulilah rab al alameen
                                                        if (Sprite_has_cursor_on_it(Level_Icon_2, cursor_cordinates))
                                                        {
                                                                Level_Manager.loadLevel(Icon_2_lvl_No); // Load the current level
                                                                // And send it to the level Screen
                                                                //..Alhamdulilah rab al alameen
                                                                // Load the current level
                                                                // And send it to the level Screen
                                                                //..Alhamdulilah rab al alameen
                                                                LevelSc(window, Level_Manager, Icon_2_lvl_No);
                                                                Level_Manager.CurrentLevelData.deleteData();
                                                        }
                                                }
                                        }
                                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 3)
                                        {
                                                int Icon_3_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 2; // We get its level just in case (it is very useful if we are to perform actins using Catalog, Alhamdulilah rab al alameen)
                                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Locked)
                                                { // The we confirm it isnt locked, only then you can interact with it, Alhamdulilah rab al alameen
                                                        if (Sprite_has_cursor_on_it(Level_Icon_3, cursor_cordinates))
                                                        {
                                                                Level_Manager.loadLevel(Icon_3_lvl_No); // Load the current level
                                                                // And send it to the level Screen
                                                                //..Alhamdulilah rab al alameen
                                                                LevelSc(window, Level_Manager, Icon_3_lvl_No);
                                                                Level_Manager.CurrentLevelData.deleteData();
                                                        }
                                                }
                                        }
                                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 4)
                                        {
                                                int Icon_4_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 3; // We get its level just in case (it is very useful if we are to perform actins using Catalog, Alhamdulilah rab al alameen)
                                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Locked)
                                                { // The we confirm it isnt locked, only then you can interact with it, Alhamdulilah rab al alameen
                                                        if (Sprite_has_cursor_on_it(Level_Icon_4, cursor_cordinates))
                                                        {
                                                                Level_Manager.loadLevel(Icon_4_lvl_No); // Load the current level
                                                                // And send it to the level Screen
                                                                //..Alhamdulilah rab al alameen
                                                                LevelSc(window, Level_Manager, Icon_4_lvl_No);
                                                                Level_Manager.CurrentLevelData.deleteData();
                                                        }
                                                }
                                        } // Final road map, see if left claick->see if button is visual->see if it is unclocked->see if cursor on it interact, Alhamulilah rab al alameen
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

                // window.draw(CampaignMapSc_Bg_Sprite);

                // For the Act message for starting screens
                if (ScreenOrientations.Orientations != nullptr) // to ensure it doesnt access undelcatred space
                {
                        // For choosing which background gets drawn

                        window.draw(*CampaignMapSc_Bg_Sprites.Sprite_Double_Ptr[ScreenOrientations.Orientations[Current_Screen_Orientation].Act - 1]);
                        // Although this is an overlly long string of a command
                        // This simply sees the current oritation, sees what act it has
                        // It uses that act -1 (such that 0 is for act 1) to give index to the array that stores the ptrs to the sprites of bg screens
                        // We simply derefrence that selected ptr using the act - 1 as an index to the ptr array
                        // we draw that
                        // Alhamdulilah rab al alameen

                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Text == true) // if we are to display the text
                        {
                                if (ScreenOrientations.Orientations[Current_Screen_Orientation].Act == 1)
                                {
                                        CMSc_Act_Label_Text.setString("Act 1...");
                                }
                                else if (ScreenOrientations.Orientations[Current_Screen_Orientation].Act == 2)
                                {
                                        CMSc_Act_Label_Text.setString("Act 2...");
                                }
                                else if (ScreenOrientations.Orientations[Current_Screen_Orientation].Act == 3)
                                {
                                        CMSc_Act_Label_Text.setString("Act 3...");
                                }
                                else if (ScreenOrientations.Orientations[Current_Screen_Orientation].Act == 4)
                                {
                                        CMSc_Act_Label_Text.setString("Act 4...");
                                }

                                window.draw(CMSc_Act_Label_Text);
                        }
                        if (Current_Screen_Orientation != 0) // if it gets to last orientation dont go to next
                        {
                                window.draw(Left_Arrow); // If going left is possible draw the arrow
                        }
                        if (Current_Screen_Orientation != ScreenOrientations.No_of_Orientations - 1) // if it gets to last orientation dont go to next
                        {
                                window.draw(Right_Arrow);
                        } // to do left arrow

                        // Now for the buttons

                        // Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[0].Locked = false;
                        // Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[0].Stars = 0; // even setting 0 unlocked here keeps it locked image, meaing it mjust be being set locked image someonwhere inside that prints over the level 1 0 starimage, Allah swt knows best, ALhamdulilah rab al alameen

                        // Issue found ALhamdulilah rab al alameen
                        // printing windo before set texture soewhere ebhind in the loop somethiign else was probably setting or perhaps something else? Allah swt knws best Alhamdulilah rab al alameen

                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 1)
                        {

                                int Icon_1_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 0; // considering it is the first icon (so no of first +0) (and that it is visual in this irietatin)
                                // cout << "Icon_1_lvl_No" << Icon_1_lvl_No << endl;
                                // cout << "Locked?: " << Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked << endl;
                                //  Also the number to be displayed is given by the number of level, so
                                //  Something is making the texture = lock texture and it might be from prev iteration so lie after this Allah swt knows bet Alhamdulilah rab al alameen
                                // Issue, had reversed condition mistakely, if locked display locked , Alhamdulilah rab al alameen
                                if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked)
                                {
                                        // Level_Icon_1.setTexture(Level_Icons_Spreadsheet);

                                        Level_Icon_1.setTextureRect(LI_Locked_Level_Coordinates); // It appears that we can do both texture and cooridtes in it in constructor, but to change we need to change individualy, texture or ini rect
                                }
                                else
                                {
                                        if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Stars == 0)
                                        {

                                                Level_Icon_1.setTextureRect(LI_0_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Stars == 1)
                                        {
                                                Level_Icon_1.setTextureRect(LI_1_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Stars == 2)
                                        {
                                                Level_Icon_1.setTextureRect(LI_2_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Stars == 3)
                                        {
                                                Level_Icon_1.setTextureRect(LI_3_Star_Level_Coordinates);
                                        }
                                }
                                window.draw(Level_Icon_1);
                                // Text must appear on top of icon Alhamdulilah rab al alameen
                                // Conxiderinf not t o draw level number if level isl locked
                                // First we must know level number using the screen orietnation
                                // cout << "Icon_1_lvl_No" << Icon_1_lvl_No << endl;
                                // cout << "Locked?: " << Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked << endl;
                                Level_Label_1.setString(Int_To_String(Icon_1_lvl_No)); // issue is most likely that when input is already 0 string returned is empty, ALhamdulilah rab al alameen found

                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked) // is beinf printed by this
                                {
                                        // cout << "Level 1: locked status: " << Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_1_lvl_No].Locked << endl;
                                        window.draw(Level_Label_1);
                                }
                        }
                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 2)
                        {

                                int Icon_2_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 1; // considering it is the second icon (so no of first +1) (and that it is visual in this irietatin)

                                if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Locked)
                                {
                                        // Level_Icon_1.setTexture(Level_Icons_Spreadsheet);
                                        Level_Icon_2.setTextureRect(LI_Locked_Level_Coordinates); // It appears that we can do both texture and cooridtes in it in constructor, but to change we need to change individualy, texture or ini rect
                                }
                                else
                                {
                                        if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Stars == 0)
                                        {
                                                Level_Icon_2.setTextureRect(LI_0_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Stars == 1)
                                        {
                                                Level_Icon_2.setTextureRect(LI_1_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Stars == 2)
                                        {
                                                Level_Icon_2.setTextureRect(LI_2_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Stars == 3)
                                        {
                                                Level_Icon_2.setTextureRect(LI_3_Star_Level_Coordinates);
                                        }
                                }
                                window.draw(Level_Icon_2);
                                Level_Label_2.setString(Int_To_String(Icon_2_lvl_No));

                                // cout << "Level 2: locked status: " << Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Locked << endl;
                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_2_lvl_No].Locked)
                                {
                                        window.draw(Level_Label_2);
                                }
                        }
                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 3)
                        {

                                int Icon_3_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 2; // considering it is the third icon (so no of first +2) (and that it is visual in this irietatin)

                                if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Locked)
                                {
                                        // Level_Icon_1.setTexture(Level_Icons_Spreadsheet);
                                        Level_Icon_3.setTextureRect(LI_Locked_Level_Coordinates); // It appears that we can do both texture and cooridtes in it in constructor, but to change we need to change individualy, texture or ini rect
                                }
                                else
                                {
                                        if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Stars == 0)
                                        {
                                                Level_Icon_3.setTextureRect(LI_0_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Stars == 1)
                                        {
                                                Level_Icon_3.setTextureRect(LI_1_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Stars == 2)
                                        {
                                                Level_Icon_3.setTextureRect(LI_2_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Stars == 3)
                                        {
                                                Level_Icon_3.setTextureRect(LI_3_Star_Level_Coordinates);
                                        }
                                }
                                window.draw(Level_Icon_3);

                                Level_Label_3.setString(Int_To_String(Icon_3_lvl_No));

                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_3_lvl_No].Locked)
                                {
                                        window.draw(Level_Label_3);
                                }
                        }
                        if (ScreenOrientations.Orientations[Current_Screen_Orientation].Level_Buttons >= 4)
                        {

                                int Icon_4_lvl_No = ScreenOrientations.Orientations[Current_Screen_Orientation].First_Level_Number + 3; // considering it is the 4 icon (so no of first +3) (and that it is visual in this irietatin)

                                if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Locked)
                                {
                                        // Level_Icon_1.setTexture(Level_Icons_Spreadsheet);
                                        Level_Icon_4.setTextureRect(LI_Locked_Level_Coordinates); // It appears that we can do both texture and cooridtes in it in constructor, but to change we need to change individualy, texture or ini rect
                                        // issue was here, had done icon 1 instead of 4 Alhamdulilah rab al alameen resolved
                                }
                                else
                                {
                                        if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Stars == 0)
                                        {
                                                Level_Icon_4.setTextureRect(LI_0_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Stars == 1)
                                        {
                                                Level_Icon_4.setTextureRect(LI_1_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Stars == 2)
                                        {
                                                Level_Icon_4.setTextureRect(LI_2_Star_Level_Coordinates);
                                        }
                                        else if (Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Stars == 3)
                                        {
                                                Level_Icon_4.setTextureRect(LI_3_Star_Level_Coordinates);
                                        }
                                }
                                window.draw(Level_Icon_4);

                                Level_Label_4.setString(Int_To_String(Icon_4_lvl_No)); // had done + 4 instead of + 3 resolved Alhamdulilah rab al alameen

                                if (!Level_Manager.Catalog.Catalog_Of_Level_NFA_Maps[Icon_4_lvl_No].Locked)
                                {
                                        window.draw(Level_Label_4);
                                }
                        } // similarly for click detection we use same logic: if the button should be visible (ie same level buttons>=n check) then detect click on it else not ALhamdulilah rab al alameen
                }

                window.display();
        }

        return 0;
}