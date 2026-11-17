// Bismillah hirahman nirahim
// THis file has level manager
// Level catalog parcer (named catalog write)
// Including level parcer
// Correction: to be tested in Game.cpp because it is in same folder
// Easier to include: shorter path

#define LEVEL_CATALOG_FILENAME_AND_PATH "../src/Levels/LevelCatalogue.json" // ISSue FOUND, this filename should also include path from build

#include <iostream>
#include <fstream>
using namespace std;
struct Level_NF_Map // Level Name, File name map
{
    string name; // although map there isnt any restructions on repeats
    string file;
};

struct LevelCatalog
{
    int No_of_Levels = 0;
    Level_NF_Map *Catalog_Of_Level_NF_Maps = nullptr;

    // for returning error occured/ successful close states
    int writeCatalogue(string Json_Levels_Catalog_File);

    int deleteCatalog();

    ~LevelCatalog();
};

struct LevelManager // An object of level manager is to be added in campaign map, it loads the catalog when you open the camaign screen and deletes catalog when you log out
{
    LevelCatalog Catalog;

    // Fetch from file and write it into its memeber
    int loadCatalogue(); // This reads the file if level catalog and turns it into a string without any \n
    // This also sends that file to LavaelCatalog's Parce Data
    // Which gives makes the catalogue hold the no of levels present, and their name:filename maps
};

// Levels are loaded on click on thier button and click load
// So separate fucniton for them
// If file not exsists says not found
// Now to test if catalog made properly in main inshallah