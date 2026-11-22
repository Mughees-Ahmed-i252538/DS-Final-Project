// Bismillah hirahman nirahim
// THis file has level manager
// Level catalog parcer (named catalog write)
// Including level parcer
// Correction: to be tested in Game.cpp because it is in same folder
// Easier to include: shorter path

#define LEVEL_CATALOG_FILENAME "LevelCatalogue.json" // ISSue FOUND, this filename should also include path from build
#define LEVEL_AND_CATALOG_FILE_PATH "../src/Levels/"

#include <iostream>
#include <fstream>
using namespace std;
struct Level_NFA_Map // Level Name, File name map
{
    string name; // although map there isnt any restructions on repeats
    string file;
    int Act_no = 0; // Structure update now structure uses

    bool Locked = false; // a fucntion locks this depending on catalog previous level
    int Stars = 0;       // Used for seeing score

    int Lock(); // Done be a camign and saves as we load the catalog, unless save loaded it unlocks first level and locks the rest
    int Unlock();
    int setStars(int Stars); // Depending on saves else all are 0 at start
};

struct LevelCatalog
{
    int No_of_Levels = 0;
    int Act_1_Levels = 0;
    int Act_2_Levels = 0;
    int Act_3_Levels = 0;
    int Act_4_Levels = 0;

    Level_NFA_Map *Catalog_Of_Level_NFA_Maps = nullptr;

    // for returning error occured/ successful close states
    int writeCatalogue(string Json_Levels_Catalog_File);

    int deleteCatalog();

    // Locks and starts at start are determined by the two funcs cabout start condition and not by the writeCatalog Alhamdulilah rab al alameen

    int Set_Default_CampaignStartCondition(); // set all stars 0, only first level state unlcoked rest locked

    int SetCustom_Campaign_StartCondition(bool *Level_Lock_States, string *Level_Filenames, int Level_Starts, int size); // This also

    ~LevelCatalog();
};

struct Act_1_Data
{
    // int *Preorder = nullptr;
    // int *Inorder = nullptr;
};

struct Act_2_Data
{
    // int *InsertOrder = nullptr;
    bool Forced_Skewness = false;
};
struct Act_3_Data
{
    // int *InsertOrder = nullptr;
};

struct Act_4_Data
{
    // currently thought data types, Alhamdulilah rab al alameen
    // int *Heap = nullptr;
};

struct LevelData
{
    int Act = 0; // can be 1 , 2, 3 ,4
    int Sub_Act = 0;

    // They have different datas
    string Description;
    int nodeCount = 0;
    string mode;
    int NodeCapacity = 0;
    string Tree; // kept as eg 19 29 291 # # #
    // Had accidently did tree=0; // Which throws logic error, we cant do that
    //  This data (above line) will be present in both seeded and stored file inshallah

    int seed = 0; // if no
    int Max = 0;
    int Min = 0; // These are for random genration
    // I think all acts would use this type inshallah
    // Allah swt knows best Alhamdulilah rab al alameen

    Act_1_Data *act_1_data = nullptr;
    Act_2_Data *act_2_data = nullptr;
    Act_3_Data *act_3_data = nullptr;
    Act_4_Data *act_4_data = nullptr; // Only dma storage are the act datas

    //=======================
    // For displaying in capaign

    //======================

    int writeData(string file_content, int Act_No);
    int deleteData();
};

struct LevelManager // An object of level manager is to be added in campaign map, it loads the catalog when you open the camaign screen and deletes catalog when you log out
{
    LevelCatalog Catalog;
    LevelData CurrentLevelData;

    // Fetch from file and write it into its memeber
    int loadCatalogue();   // This reads the file if level catalog and turns it into a string without any \n
    int loadLevel(int id); // Where id is the levels number in Catalogue

    // This also sends that file to LavaelCatalog's Parce Data
    // Which gives makes the catalogue hold the no of levels present, and their name:filename maps
};

// Levels are loaded on click on thier button and click load
// So separate fucniton for them
// If file not exsists says not found
// Now to test if catalog made properly in main inshallah