// Bismillah hirahman nirahim
// bismillah awala hu wa akhira hu
#include "LevelManager.h"

string trim(string &orignal)
{
    char starting_Non_Space = orignal.find_first_not_of("\t\b\n ");

    if (starting_Non_Space == std::string::npos) // should have returned location
    {
        orignal = "";   // makes empty
        return orignal; //
    }
    char ending_Non_Space = orignal.find_last_not_of("\t\b\n ");

    if (ending_Non_Space == std::string::npos) // should have returned location
    {
        orignal = "";   // makes empty
        return orignal; //
    }

    string trimmed = orignal.substr(starting_Non_Space, starting_Non_Space - ending_Non_Space + 1);

    orignal = trimmed;
    return orignal;
}

int LevelManager::Read_Level_Catalog_File() // needs var renaming for ease of understanding inshallah
{
    string filename = LEVEL_CATALOG_FILENAME; // This should include the extension
    // Decision for later

    ifstream file;
    file.open(filename);

    if (!file.is_open()) // ofstream. open doesnt return anything
    {
        cout << "Level Catalog File didnt open" << endl;
        return -1; // Means error code
    }

    string file_content;

    while (!getline(file, file_content)) // Auto delimeter \n
    {                                    // Cant do getline withofstream
    } // keep inputing untill getline gives 0,  getline manages using EOF

    // Adding tri function that trims surrounding spaces (may be wont)
    Catalog.loadCatalogue(file_content);

    return 0; // Means ok
}

int String_To_Int(string String)
{
    int Number = 0; // Represented num
    int i = 0;
    while (String[i] != '\0') // I remeber that if both scopes have declared same var, while statemnnt cheks the outer
    {
        if (String[i] == '0' || String[i] == '1' || String[i] == '2' || String[i] == '3' || String[i] == '4' || String[i] == '5' || String[i] == '6' || String[i] == '7' || String[i] == '8' || String[i] == '9')
        {
            Number *= 10;
            Number += String[i];
        }
    }
    return Number;
}

int Inclusive_Difference(int a, int b)
{
    return (a - b + 1); // from a to b, a,b inclusive
}

int Count_Char_In_String(string String, char Char)
{
    int i = 0;
    int count = 0;
    while (String[i] != '\0')
    {
        if (String[i] == Char)
        {
            count++;
        }
    }
    return count;
}

int LevelCatalog::loadCatalogue(string file_content) // This data is the file ocnverted to a string
{

    if (this->Catalog_Of_Level_NF_Maps != nullptr)
    {
        cout << "Catalog already exsists in memeory " << endl; // Should delte it fitst then load another
        return -1;                                             // A catalo is already preent delete this one first
    }

    trim(file_content); // remove extra spaces from sides and \b\t\n

    if (file_content.empty()) // checks if is empty
    {
        cout << "Catalog file string gotten is empty " << endl;
        return -2; // Error coe file is empty
    }

    char starting_char_loc = file_content.find_first_not_of("\t\b\n ");

    if (file_content[starting_char_loc] != '{') // should have returned location
    {
        cout << "Starting { in json not found " << endl;
        return -3; // Starting { is missing
    }
    char ending_char_loc = file_content.find_first_not_of("\t\b\n ");

    if (file_content[ending_char_loc] != '}') // should have returned location
    {
        cout << "Ending } in json not found" << endl;
        return -4; // ending } is missing
    }

    file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));
    // This removes the outermost btackets so the current brackets left are the brakets for the Levels

    // Now we know the first entry should be number of levels (else not follwing our format)
    // So it should be between first : and first ,'

    // Self, to add the check for pressence of key , No of leevls here if time ins hallah

    starting_char_loc = file_content.find_first_of(':');
    ending_char_loc = file_content.find_first_of(','); // Reusing vars

    if (starting_char_loc == std::string::npos)
    {
        cout << "The ':' for the No of Levels not found" << endl;
        return -5;
    }
    if (ending_char_loc == std::string::npos)
    {
        cout << "The ',' for the No of Levels not found" << endl;
        return -6;
    }

    starting_char_loc = starting_char_loc + 1; // considering the : and , not in the string
    ending_char_loc = ending_char_loc - 1;
    string No_of_Levels_String = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));
    trim(No_of_Levels_String); // Removing surrounding space if any
    // This should have a number

    if (No_of_Levels_String.empty())
    {
        cout << "The entry for number of levels was evaluated to be missing" << endl;
        return -7;
    }

    int num = String_To_Int(No_of_Levels_String);

    if (num == 0) // We get magnitude of neg value
    {
        cout << "The number of levels written are 0" << endl;
        return 0; // This is a valid case that no level exsists
    }

    starting_char_loc = file_content.find_first_of('{');
    ending_char_loc = file_content.find_last_of('}');

    if (starting_char_loc == std::string::npos)
    {
        cout << "The starting { for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -8;
    }
    if (ending_char_loc == std::string::npos)
    {
        cout << "The ending } for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -9;
    }

    starting_char_loc += 1;
    ending_char_loc -= 1; // This is done to be able to cut of the {} tthemselves

    file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    if (Count_Char_In_String(file_content, ':') != num) // The number of entries != no mentioned in capacity (no of levels != mentioned no of levels)
    {
        cout << "The Number of entries doesnt equal as no of : not = num" << endl;
        return -10;
    }

    if (Count_Char_In_String(file_content, ',') != num - 1) // The number of entries != no mentioned in capacity (no of levels != mentioned no of levels)
    {
        cout << "The Number of entries doesnt equal as no of , not = num - 1" << endl;
        return -11;
    }

    Level_NF_Map *Buffer_For_Catalog_Of_Level_NF_Maps = nullptr; // is so we dont diretly store in important location
    Buffer_For_Catalog_Of_Level_NF_Maps = new Level_NF_Map[num];

    for (int i = 0; i < num - 1; i++)                         // for values that end in the ,
    {                                                         // May put errors check here later if time inshallah
        starting_char_loc = file_content.find_first_of('\"'); // We need to see the name string
        ending_char_loc = file_content.find_first_of(':');

        starting_char_loc += 1; // to remove the starting "
        string name = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

        ending_char_loc = name.find_last_of('\"'); // Finding ending "
        ending_char_loc -= 1;
        // We can make cut range fuction but have to do range is in string

        name = name.substr(0, Inclusive_Difference(0, ending_char_loc)); // removing space at end to "

        // Now for filename
        // We must remove the name from the file content string
        starting_char_loc = file_content.find_first_of(':'); // have to keep from after :
        starting_char_loc += 1;                              // The ending location is last offset

        file_content = file_content.substr(starting_char_loc); // I think this should cut from the point after : till end
        // WE have removed name and : from file content
        //=====================
        starting_char_loc = file_content.find_first_of('\"');
        ending_char_loc = file_content.find_first_of(","); // file name is from " to ,
        starting_char_loc += 1;

        string filename = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

        ending_char_loc = filename.find_last_of('\"');
        ending_char_loc -= 1;

        filename = filename.substr(0, Inclusive_Difference(0, ending_char_loc));

        // Now we must also remove the filename from file content including the ,

        starting_char_loc = file_content.find_first_of(',');
        starting_char_loc += 1; // The  location with is last offset to be removed

        file_content = file_content.substr(starting_char_loc);

        // We can store this name and filename in the ith NF map of Catalog

        Buffer_For_Catalog_Of_Level_NF_Maps[i].name = name;
        Buffer_For_Catalog_Of_Level_NF_Maps[i].file = filename;

        // Now we must one by one fetch leavel map of level name to file name one by one
        // FIle name should also have extension in it
    }

    // The one ends in nothing because we removed the {'s
    // So end is " or space
    // We can safely use " as ending location

    starting_char_loc = file_content.find_first_of('\"'); // We need to see the name string
    ending_char_loc = file_content.find_first_of(':');

    starting_char_loc += 1; // to remove the starting "
    string name = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    ending_char_loc = name.find_last_of('\"'); // Finding ending "
    ending_char_loc -= 1;
    // We can make cut range fuction but have to do range is in string

    name = name.substr(0, Inclusive_Difference(0, ending_char_loc));

    // Now for filename
    // We must remove the name from the file content string
    starting_char_loc = file_content.find_first_of(':'); // have to keep from after :
    starting_char_loc += 1;                              // The ending location is last offset

    file_content = file_content.substr(starting_char_loc); // I think this should cut from the point after : till end
    // WE have removed name and : from file content
    //==========================================

    starting_char_loc = file_content.find_first_of('\"');
    ending_char_loc = file_content.find_last_of("\""); // file name is from " to ,
    starting_char_loc += 1;
    ending_char_loc -= 1;

    string filename = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    Buffer_For_Catalog_Of_Level_NF_Maps[num - 1].name = name;
    Buffer_For_Catalog_Of_Level_NF_Maps[num - 1].file = filename; // last location is n-1

    // this is final filename

    // Now the difference from other location is that we can simply use first " and last " to find the filename as no leading , should exsist

    //====================================================================

    // Num stored is updated at the end cuz valudation isnt completed yet

    //==================================================================
    // Considering we put other validation checks and no issues arrived we can safely trasnfer buffer to data of this and in the main catalog
    this->No_of_Levels = num; // Cant be neg, if written neg the function, string to number will end up removing it cuz it doesnt cosndierer sign other than numerics
    this->Catalog_Of_Level_NF_Maps = Buffer_For_Catalog_Of_Level_NF_Maps;

    // Now we have to locate and cut out the string that contains the levels
} // To test this before proceding inshallah