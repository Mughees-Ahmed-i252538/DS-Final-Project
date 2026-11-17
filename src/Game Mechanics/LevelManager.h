// Bismillah hirahman nirahim
// THis file has level manager
// Including level parcer

#define LEVEL_CATALOG_FILENAME "LevelCatalogue"

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

    int loadCatalogue(string Json_Levels_Catalog_File); // for returning error occured
};

struct LevelManager
{
    LevelCatalog Catalog;

    int Read_Level_Catalog_File(); // This reads the file if level catalog and turns it into a string without any \n
    // This also sends that file to LavaelCatalog's Parce Data
    // Which gives makes the catalogue hold the no of levels present, and their name:filename maps
};