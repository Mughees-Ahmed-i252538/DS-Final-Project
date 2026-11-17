// Bismillah hirahman nirahim
// bismillah awala hu wa akhira hu
#include "LevelManager.h"

int Inclusive_Difference(int a, int b)
{
    // Issue found we accidnrelty did a-b meanwhile we were sending b as the larger didgit
    // Which made the differnce negative
    // if negative, it becomesp os cuz size_t is unsigned (a very large pos value)
    // And hence makes the ccut apart substring a very alrge substring
    //(there are possbilities of cuting past the actual stigng present (google) but i didnt go into dtia;s (it seemsb there is a differnce if you use cin.getline)) Allah swt knows best, Alhamdulilah rab al alameen
    if (b > a)
        return (b - a + 1); // from a to b, a,b inclusive

    return 0; // THis means there is an issue with inpputs,
}

string trim(string &orignal) // Issue discovered, used char instead of size_t inside trim as well, Fixed Alhamdulilah
{
    size_t starting_Non_Space = orignal.find_first_not_of("\t\b\n ");

    if (starting_Non_Space == std::string::npos) // should have returned location
    {
        cout << "In this string the first non space charcter didnt exsist" << endl;
        orignal = "";   // makes empty
        return orignal; //
    }
    size_t ending_Non_Space = orignal.find_last_not_of("\t\b\n ");

    if (ending_Non_Space == std::string::npos) // should have returned location
    {
        cout << "In this string the last non space charcter didnt exsist" << endl;
        orignal = "";   // makes empty
        return orignal; //
    }

    // cout << "IN trimming" << endl;
    // cout << starting_Non_Space << "  " << ending_Non_Space << endl;
    // cout << Inclusive_Difference(starting_Non_Space, ending_Non_Space) << endl;

    // Fixed ALhamdulilah
    string trimmed = orignal.substr(starting_Non_Space, Inclusive_Difference(starting_Non_Space, ending_Non_Space)); // Issue found, did start - end +1; isntead of end- start +1; cuz start is greater

    orignal = trimmed;
    return orignal;
}

int LevelManager::loadCatalogue() // needs var renaming for ease of understanding inshallah
{
    string filename = LEVEL_CATALOG_FILENAME_AND_PATH; // This should include the extension
    // Decision for later

    ifstream file;
    file.open(filename);

    if (!file.is_open()) // ofstream. open doesnt return anything
    {
        cout << "Level Catalog File didnt open" << endl;
        return -1; // Means error code
    }

    string file_content;
    string One_Line_Buffer; // gets one line at a time
    // To put it into file_content

    // Correction previously isntead of one line buffer we were using file_contnet inside getline
    // Issue was when next line is written to it, previous line is overwritten
    while (getline(file, One_Line_Buffer)) // Auto delimeter \n
    {                                      // Correction: have to do while getline(file,Onel ine buffer), if successfull getting run the storing block
                                           // Presiosuly doing !getlim..... if unsuccessful only then write to file_conetent, which only wrote empty line i belive
                                           // cout << "One line Buffer" << One_Line_Buffer << endl;//Test time test output not debug output of realtime hence commented
                                           // file_content += One_Line_Buffer; // One by one next string is concatenated to file_content                  // Cant do getline withofstream
    } // keep inputing untill getline gives 0,  getline manages using EOF

    // Adding tri function that trims surrounding spaces (may be wont)

    // cout << "File Content converted to a string" << endl; // Note we didnt need any \n so we removed it
    // cout << "===================================================================================" << endl;
    // cout << file_content << endl;
    // cout << "===================================================================================" << endl;
    // For actual debug out during game, will be in campaign map , ie where used
    // This is for testing functionality
    // Alhamdulilah rab al alameen
    int CatalogWrite_Return = Catalog.writeCatalogue(file_content);
    // To do retuurns on basis on its returns eg if error of this type return this, if ended cuz cataloge empty (0 levels return 0, if some levels present return 1)
    if (CatalogWrite_Return == 0)
    {
        return 0; // Means catalog is ok but no levels written
    }
    if (CatalogWrite_Return < 0) // if less than 0 (error codes) | this might change later dependaing on what we want to do for each error code inshallah
    {
        return -2;
    }

    return 1; // Means ok
}

int String_To_Int(string String)
{
    int Number = 0; // Represented num
    int i = 0;
    while (String[i] != '\0') // I remeber that if both scopes have declared same var, while statemnnt cheks the outer
    {
        // cout << String[i] << endl;
        if (String[i] == '0' || String[i] == '1' || String[i] == '2' || String[i] == '3' || String[i] == '4' || String[i] == '5' || String[i] == '6' || String[i] == '7' || String[i] == '8' || String[i] == '9')
        {
            Number *= 10;
            Number += String[i] - '0'; // Correction (self viewed)/ We need the string char converted to itses number counterpart (added - '0')
        }
        i++; // Issue found, we had forgotten to do i++

        // Fixed Alhamdulilah rab al alameen
    }
    return Number;
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
        i++; // Same issue discovered had forgotteon to do i++; Fixed Alhamdulilah rab al alameen;
    }
    return count;
}

int LevelCatalog::writeCatalogue(string file_content) // This data is the file ocnverted to a string
{

    if (this->Catalog_Of_Level_NF_Maps != nullptr)
    {
        cout << "Catalog already exsists in memeory " << endl; // Should delte it fitst then load another
        return -1;                                             // A catalo is already preent delete this one first
    }

    trim(file_content); // remove extra spaces from sides and \b\t\n

    // cout << "===================================================================================" << endl;//FIxed Alhamdulilah
    // cout << "After First trim, string: " << file_content << endl;
    // cout << "===================================================================================" << endl;
    // Was previously succeeding cuz trim was wrong in 2 places...
    // ten failed cuz fixed one place,
    // Then succeeded at final cuz both fixed
    // Now inshallah no issue

    if (file_content.empty()) // checks if is empty
    {
        cout << "Catalog file string gotten is empty " << endl;
        return -2; // Error coe file is empty
    }
    // Here logic is used that outer most chanracters should be {}

    size_t starting_char_loc = file_content.find_first_not_of("\t\b\n ");

    if (file_content[starting_char_loc] != '{') // should have returned location
    {
        cout << "Starting { in json not found/first char isnt {| logic: outermost non space characters should be {} " << endl;
        return -3; // Starting { is missing
    }
    size_t ending_char_loc = file_content.find_last_not_of("\t\b\n "); // Correction, had searched for first not of, while intending to search for last not of, bezuse we assume json is valid if} at end
    // corrected, Alhamdulilah rab al alameen

    // Issue found why not displaying the ending char loc, it was made char, i remade it into size t (after intiitaly doing int)
    // Range of char is -128 to 127 so it couldnt contain a value like { and probaly wrapped around several times, hence giving issues
    // But we  couldnt even view the value of ending char loc cuz it was char and likely printing invisible character cuz made ascii of invisible character
    // Allah swt knows best
    // Alhamdulilah rab al alameen
    /*
    Debug test
    if (ending_char_loc == std::string::npos)
    {
        cout << "The file_content find_last_not_of gave npos" << endl; // Self notices the inline error shower didnt resolve before ran code, so sometimes simply need to do that ALhamdulilah , MAy Allah swt help us Ameen
    }
    */
    // cout << "test 1" << endl;
    if (file_content[ending_char_loc] != '}') // should have returned location, fixed alhamdulilah by fixing trim in both places, changinf start-end+1 to end - start +1, andchnaging char to size_t, Alhamdulilah rab al alameen
    {
        // cout << "Loc given by ending char loc: " << ending_char_loc << endl; // debugging tests

        // cout << "Size of file_Content: " << file_content.size() << endl;
        cout << "Ending } in json not found/last char isnt }| logic: outermost non space characters should be {}" << endl;
        return -4; // ending } is missing
    }

    file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));
    // This removes the outermost btackets so the current brackets left are the brakets for the Levels

    // Now we know the first entry should be number of levels (else not follwing our format)
    // So it should be between first : and first ,'

    // Self, to add the check for pressence of key , No of leevls here if time ins hallah

    starting_char_loc = file_content.find_first_of(':');
    ending_char_loc = file_content.find_first_of(','); // Reusing vars

    // cout << "test 2" << endl;
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

    // cout << "test 3" << endl;
    starting_char_loc = starting_char_loc + 1; // considering the : and , not in the string
    ending_char_loc = ending_char_loc - 1;
    // cout << "For num str, starting loc: " << starting_char_loc << endl;
    // cout << "For num str, ending loc: " << ending_char_loc << endl;
    // cout << "Inclusive difference: " << Inclusive_Difference(starting_char_loc, ending_char_loc) << endl;
    string No_of_Levels_String = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    // cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // cout << "Before trimming The string telling number of levels is: " << No_of_Levels_String << endl; // Issue is likely here (Allah swt knows best), string is 2 (should be 20)
    // cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Alhamdulilah rab al alameen fixed
    //  Before trimming its value is correct

    // 2 big issues discovered
    // Before trimming the nymber is from 20 to end
    // After trimming it is 2
    trim(No_of_Levels_String); // Removing surrounding space if any
    // Now trim making the string become empty

    // cout << "After trimming The string telling number of levels is: " << No_of_Levels_String << endl;
    //   This should have a number
    //   cout << "test 3.1" << endl; // test 4 not appearing, likely cuaisng program to run forever
    if (No_of_Levels_String.empty())
    {
        cout << "The entry for number of levels (an integer) was| evaluated to be missing" << endl;
        return -7;
    }
    // cout << "test 3.2" << endl; // test 3.3 didnt run
    // cout << "The string telling number of levels is: " << No_of_Levels_String << endl; // Issue is likely here (Allah swt knows best), string is 2 (should be 20)

    int num = String_To_Int(No_of_Levels_String);
    // cout << "The number decoded from it is: " << num << endl;
    //  cout << "test 3.2.1" << endl; // 3.2.1 didnt run, issue is with string to int
    if (num == 0) // We get magnitude of neg value
    {
        // cout << "test 3.2.2" << endl;
        cout << "The number of levels written are 0" << endl;
        return 0; // This is a valid case that no level exsists
    }
    // cout << "test 3.3" << endl;
    starting_char_loc = file_content.find_first_of('{');
    ending_char_loc = file_content.find_last_of('}'); // ctrl + shift + esc is shortcut for task manager=> to close program.exe if not closed (perhaps due to infinte loop): i think one indication is fan speeding up? Allah swt knows best Alhadmulilah rab al alameen
    // cout << "test 3.4" << endl;
    // cout << "test 4" << endl; // Stopped after test 4, program.exe didnt close
    if (starting_char_loc == std::string::npos)
    {
        // cout << "test 4.1" << endl;
        cout << "The starting { for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -8;
    }
    // cout << "test 4.2" << endl;
    if (ending_char_loc == std::string::npos)
    {
        // cout << "test 4.3" << endl;
        cout << "The ending } for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -9;
    }
    // cout << "test 4.4" << endl;
    starting_char_loc += 1;
    ending_char_loc -= 1; // This is done to be able to cut of the {} tthemselves

    // cout << "test 4.5" << endl; // stopped after test 4.5
    file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    //========================NOte issue found Alhamdulilah=============================
    // We didnt remove orignal 2 brackets orignally so this only removed orignal 2 brackets

    // We have to repeat to also remove all content and inside two {} as well to keep only the ':'s inside Levels: data Alhamdulilah rab al alameen
    starting_char_loc = file_content.find_first_of('{');
    ending_char_loc = file_content.find_last_of('}'); // ctrl + shift + esc is shortcut for task manager=> to close program.exe if not closed (perhaps due to infinte loop): i think one indication is fan speeding up? Allah swt knows best Alhadmulilah rab al alameen
    // cout << "test 3.4" << endl;
    // cout << "test 4" << endl; // Stopped after test 4, program.exe didnt close
    if (starting_char_loc == std::string::npos)
    {
        // cout << "test 4.1" << endl;
        cout << "The starting { for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -8;
    }
    // cout << "test 4.2" << endl;
    if (ending_char_loc == std::string::npos)
    {
        // cout << "test 4.3" << endl;
        cout << "The ending } for wrapper of Levels that holds all Level Map entries not found" << endl;
        return -9;
    }
    // cout << "test 4.4" << endl;
    starting_char_loc += 1;
    ending_char_loc -= 1; // This is done to be able to cut of the {} tthemselves

    // cout << "test 4.5" << endl; // stopped after test 4.5
    file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));
    //=====================================================================================
    //  cout << "test 4.5.1" << endl;
    int no_of_Cols = Count_Char_In_String(file_content, ':');
    if (no_of_Cols != num) // The number of entries != no mentioned in capacity (no of levels != mentioned no of levels)
    {
        cout << "Number of ':' = " << no_of_Cols << endl;
        cout << "Num = " << num << endl; // issue displaying num as 4; made it 400 and it was told to be missing
        // So 2 issues discovered
        // 1) The file_content is still giving 42 : evene though we are supposed to check only those inside the levels : {here}, it is giving total
        // 2) the number string is evaluating wrongly
        // cout << "test 4.6" << endl;
        cout << "The Number of entries doesnt equal as no of : not = num" << endl;
        return -10;
    }
    //|||||||||||||||||||||||||||||||||||Tests Silenced Temporarlity to fix found issues inshallah|||||||||||||||||||||||||||||||||||||
    // cout << "test 4.7" << endl;
    if (Count_Char_In_String(file_content, ',') != num - 1) // The number of entries != no mentioned in capacity (no of levels != mentioned no of levels)
    {
        cout << "The Number of entries doesnt equal as no of , not = num - 1" << endl;
        return -11;
    }
    // cout << "test 4.8" << endl;
    Level_NF_Map *Buffer_For_Catalog_Of_Level_NF_Maps = nullptr; // is so we dont diretly store in important location
    Buffer_For_Catalog_Of_Level_NF_Maps = new Level_NF_Map[num];
    // cout << "test 5" << endl;
    for (int i = 0; i < num - 1; i++) // for values that end in the ,
    {
        // cout << "test 6" << endl;                             // May put errors check here later if time inshallah
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
    // cout << "test 7" << endl;
    //  The one ends in nothing because we removed the {'s
    //  So end is " or space
    //  We can safely use " as ending location

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
    ending_char_loc -= 1; // had to forecegully close program.exr in tasks manager, giving ld error

    string filename = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));

    Buffer_For_Catalog_Of_Level_NF_Maps[num - 1].name = name;
    Buffer_For_Catalog_Of_Level_NF_Maps[num - 1].file = filename; // last location is n-1

    // cout << "test 7" << endl;
    // Alhamdulilah rab al alameen test 7 ran now to check if final catalog has the data copied properly inshallah
    //  this is final filename

    // Now the difference from other location is that we can simply use first " and last " to find the filename as no leading , should exsist

    //====================================================================

    // Num stored is updated at the end cuz valudation isnt completed yet

    //==================================================================
    // Considering we put other validation checks and no issues arrived we can safely trasnfer buffer to data of this and in the main catalog
    this->No_of_Levels = num; // Cant be neg, if written neg the function, string to number will end up removing it cuz it doesnt cosndierer sign other than numerics
    this->Catalog_Of_Level_NF_Maps = Buffer_For_Catalog_Of_Level_NF_Maps;
    cout << "Catalog Write To Store Object Success: " << endl;
    cout << No_of_Levels << endl;
    //**if we change the logic that if 0 memebrs then still can be initialized, we have to remove this pirce of the debug output, ...Actuakklluy we can make it confitonal
    if (Catalog_Of_Level_NF_Maps != nullptr)
    {
        cout << Catalog_Of_Level_NF_Maps[0].name << endl; // Atleast first entry must exsists elsewise returns with code 0(empty so not initialized)
        cout << Catalog_Of_Level_NF_Maps[0].file << endl; // hence we can safely output [0]'s data for now Alhamudlilah rab al alameen
    }
    else
    {
        cout << "Catalog_Of_Level_NF_Maps was nullptr" << endl;
    }
    // If change we have to rem0ve this inshallah
    return 1; // successful write
    // Now we have to locate and cut out the string that contains the levels
} // To test this before proceding inshallah

int LevelCatalog::deleteCatalog()
{
    // See if no catalog exsists , returns 0
    // If exsists deletes it, returns 1

    if (this->Catalog_Of_Level_NF_Maps == nullptr)
    {
        this->No_of_Levels = 0; // Just confirming if issues with numbers we set it to 0
        return 0;
    }

    // else

    delete[] this->Catalog_Of_Level_NF_Maps;
    this->No_of_Levels = 0;
    return 1; // Deleted current stored map
}

LevelCatalog::~LevelCatalog()
{
    this->deleteCatalog(); // Simply delete using already made function
    // deletes the made array if exsists in heap
    // Alhamdulilah rab al alameen
}