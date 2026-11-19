// Bismillah hirahman nirahim

// This file will contain the main game mechanics
// It views the overall scene like declaring the main varibales, calling the uis
// Also does the job of actually opening and closing the window, the other (screen) funcitons exit without closing
// So on inshallah

#include <iostream>
// #include <SFML/Graphics.hpp>//included via main sc file
#include "../Interface/MainSc.cpp"
#include "LevelManager.cpp" //only included here to testm this is instead included inside campaign map ui
// Actually Object is possessed by Game()
// Which sends it to mainSc which forwards it to CampaignSc
// But Camapign is the one to interact with it (it doesnt own it, simply interacts with it)

#define WANTED_VIEW_X 1920
#define WANTED_VIEW_Y 1080

using namespace std;

void Game()
{
    cout << "Bismillah hirahman nirahim Game Started" << endl;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fill The Vault", sf::Style::Default, sf::State::Windowed); // This opens in style of default with title bar and the size is of desktop, fullscreened (sfml 3 split fullscreen from style to a 4th paramter state)
    // gets size of window

    cout << "Bismillah hirahman nirahim Window Made" << endl;

    sf::View Computer_View = window.getDefaultView(); // default view is exqual to initial window size, (whole screen)
    sf::View Wanted_View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(WANTED_VIEW_X, WANTED_VIEW_Y)));

    sf::FloatRect letterBox_Viewport = letterBox_Viewport_Calculator(Computer_View, Wanted_View);

    // Now view is the camera pointed in the game world
    // View port is what part of screen it appears on
    // We want to have our on view instead of deafualgt, so that computer doesnt look into the world broader than we wanted, else our calculations will be difficult we will have to do relative clacualtions
    // But if we simply give our own view, then on screen it doesnt exactly fit it will stretch on either x or y
    // So we make our wanted view sit on a specific part of the screen

    Wanted_View.setViewport(letterBox_Viewport);

    // Now we make the window have this view

    window.setView(Wanted_View);

    // MainSc(window); // Window given to main sc
    //   The first screen toa actually display

    // Temporary commenting the display of the screen to run tests on the level manager

    window.close();

    LevelManager L;

    cout << L.loadCatalogue(); // Loading successul? also putting print the string sent to write Catalog using cout before sending to see what is sent is it correct
    // tests
    // cout << L.Catalog.No_of_Levels << endl;
    // cout << L.Catalog.Act_1_Levels << endl;
    // cout << L.Catalog.Act_2_Levels << endl;
    // cout << L.Catalog.Act_3_Levels << endl;
    // cout << L.Catalog.Act_4_Levels << endl;

    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[0].name << endl;
    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[0].file << endl;
    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[0].Act_no << endl;
    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[1].name << endl;
    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[9].file << endl;
    // Alhamdulilah rab al alameen fix success
    // cout << L.Catalog.Catalog_Of_Level_NFA_Maps[3].Act_no << endl;

    cout << L.loadLevel(0) << endl; // Load first level if exsists
    // cout << L.CurrentLevelData.Act << endl;
    // cout << L.CurrentLevelData.Description << endl;
    // cout << L.CurrentLevelData.mode << endl;
    // cout << L.CurrentLevelData.nodeCount << endl;
    // cout << L.CurrentLevelData.seed << endl;
    // cout << L.CurrentLevelData.Max << endl;
    // cout << L.CurrentLevelData.Min << endl;
    // cout << L.CurrentLevelData.act_1_data->Inorder[0] << endl;
    // cout << L.CurrentLevelData.act_1_data->Preorder[0] << endl;

    cout << "Alhamdulilah rab al alameen game ended" << endl;
}