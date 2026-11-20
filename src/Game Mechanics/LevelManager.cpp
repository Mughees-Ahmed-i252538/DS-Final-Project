// Bismillah hirahman nirahim
// bismillah awala hu wa akhira hu
#include "LevelManager.h"

// I put the levels in folders but their act is still determined by the number written inside them

int Inclusive_Difference(int a, int b)
{
    // Issue found we accidnrelty did a-b meanwhile we were sending b as the larger didgit
    // Which made the differnce negative
    // if negative, it becomesp os cuz size_t is unsigned (a very large pos value)
    // And hence makes the ccut apart substring a very alrge substring
    //(there are possbilities of cuting past the actual stigng present (google) but i didnt go into dtia;s (it seemsb there is a differnce if you use cin.getline)) Allah swt knows best, Alhamdulilah rab al alameen
    if (b >= a)             // Issue found if the two locations were equal it returned 0, although 1-1 + 1 =1
        return (b - a + 1); // from a to b, a,b inclusive

    return 0; // THis means there is an issue with inpputs,
}

int Seeded_Generation(string &To_Be_Made_Tree, int Node_Cap, int Node_Count, int Max, int Min, bool Sorted, bool Duplicates) // This function is still inclomete
{

    if (Node_Cap <= 0)
    {
        cout << "Invlaid size" << endl;
        return -1;
    }

    if (Node_Count < 0) // Nodes can be 0 assuming for now
    {
        cout << "Invlaid no of nodes present" << endl;
        return -2;
    }

    int PossibleVals = Inclusive_Difference(Min, Max); // Range is from Min to Min, so 1,2,3 3-1+1 =3 total nos
    if (!Duplicates)
    {
        if (Node_Count > PossibleVals) // To decide if to use node count here , or node cap( i think node count but depedns on Act (if tell thiat these are the only nodes that can be inserted )Allah swt knows best)
        {
            cout << "Size> possible vals and !Duplicated" << endl;
            return -2;
        }
    }

    for (int i = 0; i < Node_Cap; i++) // To set node count no of places = some node, space is gap and # is empty space
    {

        if (!Duplicates)
        {
        }
    }

    return 1; // Sucess
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

string Cut_Of_String(string &Main, string &output, char Start, char End, bool Exclusive_Start, bool Exclusive_End, bool Remove_from_file, bool Remove_Till_Orignal_End = 0) // cant do default cuz &
{
    size_t Start_loc = Main.find_first_of(Start);

    size_t End_loc = Main.find_first_of(End);

    if (Start_loc == std::string::npos)
    {
        cout << "Start not found, start was: " << Start << "|" << endl;

        return "";
    }
    if (End_loc == std::string::npos)
    {
        cout << "End not found" << endl;
        return "";
    }
    if (Exclusive_Start)
    {
        Start_loc += 1;
    }
    if (Exclusive_End)
    {
        End_loc -= 1; // To add more checks like out of range check on start and end later inshallah
    }
    // cout << "Start loc" << Start_loc << endl;
    // cout << "End loc" << End_loc << endl;
    // cout << "Inclusive difference" << Inclusive_Difference(Start_loc, End_loc) << endl;

    if (Start_loc > End_loc)
    {
        cout << "Start loc greater than end" << endl;
        return "";
    }

    output = Main.substr(Start_loc, Inclusive_Difference(Start_loc, End_loc));
    // cout << "output: " << output << endl;
    if (Remove_from_file)
    {
        if (Exclusive_End && Remove_Till_Orignal_End) // if exclusice end and ! remove till orignal end, then leaves the orignal end in the file
        {
            End_loc += 1; // Remove tilkl orignal end if remove till orignal end is one
        }
        End_loc += 1;                // This is to remove the end of the copied range from new file_content
        Main = Main.substr(End_loc); // The +1 is
        // THis makes file remmove orignal string from Main
        // If xclusive_End&&Remove_Till_Orignal_End this also removes orignal ending char from the string
    }
    // cout << "output: " << output << endl;

    return output;
}

string De_Edge(string &String, char Start, char End, bool To_Also_Remove_Start_And_End_Chars = 0)
{ // the removes everything other than string between start char (found from start forwards) and end char (found from end side inwards)
    size_t Start_loc = String.find_first_of(Start);

    size_t End_loc = String.find_last_of(End);

    if (Start_loc == std::string::npos)
    {
        cout << "Start not found" << endl;
        return String; // dont de edge
    }
    if (End_loc == std::string::npos)
    {
        cout << "End not found" << endl;
        return String;
    }

    if (Start_loc == End_loc)
    {
        cout << "While trying to de edge, Start and end gave same character, pnly one such found (start and end location are same): For now this is considered an error" << endl;
    } // this must be checked before doing Startloc+1 adn ened loc- 1 (that would make the range end before the start in this case, would also flip this ways if start == end-1 (in which case the watnted string is empty))
    // But this single char one is in issue always
    // THe start==end-1 is issue only if we want to remove thiose cahrs as well and are doing +1 in start lco and -1 in end loc (this found make range be flipped... liike (from 2 to 1(2,1) although in math range shorter val first))Allah swt knows best ALhamdulilah rab al alameen(inverse range may cause issues if used in differnece and then for cropping strings)

    if (To_Also_Remove_Start_And_End_Chars)
    {

        if (Start_loc == End_loc - 1) // means eg "" is string, data is empty (then simply ret empty string)
        {
            String = "";
            return String;
        }

        Start_loc += 1;
        End_loc -= 1;
    }

    if (Start_loc > End_loc)
    {
        cout << "Start loc greater than end" << endl;
        return String; // dont de edge
    }

    String = String.substr(Start_loc, Inclusive_Difference(Start_loc, End_loc));
    return String;
}

int Take_One_Int_Cut(string &Main, int &int_output, char Start, char End, bool Exclusive_Start, bool Exclusive_End, bool Remove_from_file, bool Remove_Till_Orignal_End = 0)
{ // Added int& output parameter  for similarty to similar functions
    // Expecting we get : and '
    string String_Of_Num;

    // cout << "Main: " << Main << endl;
    //  The string sent in place of output string is string made in this funciton (cuz that isnt needed in output of this function), Alhamdulilah
    // cout << "Start :" << Start << " End: " << End << endl;
    Cut_Of_String(Main, String_Of_Num, Start, End, Exclusive_Start, Exclusive_End, Remove_from_file, Remove_Till_Orignal_End);
    // cout << "Take one int cut: " << endl;
    // cout << "string: " << String_Of_Num << endl;
    int Int_of_Num = String_To_Int(String_Of_Num);
    // cout << Int_of_Num << endl;
    int_output = Int_of_Num;
    return Int_of_Num;
}

string Take_One_String_Cut(string &Main, string &output, char Start, char End, bool Exclusive_Start, bool Exclusive_End, bool Remove_from_file, bool Remove_Till_Orignal_End = 0, bool DeEdgeSoroundingQurations = 1) // issue 1 found the [] doesnt have qutatons
{
    // Assuming we get : and ,
    // cout << "Test 2" << endl;
    Cut_Of_String(Main, output, Start, End, Exclusive_Start, Exclusive_End, Remove_from_file, Remove_Till_Orignal_End);
    // cout << "Test 3" << endl;
    //  This cut we have gotten may be ("   " ) hhave spaces and not removed " 's
    //  We cant simply do cut of string because this fucniton does two find first of, while we need to do one find last of for the ending edge, we have to de_edge
    if (DeEdgeSoroundingQurations)
    {
        // cout << "Test 4" << endl; // The issue is happeneing inside De edge
        // cout << "The output taken from the file which became: " << Main << " is: " << output << " and the starting and ending chars were |" << Start << "| and |" << End << "| respectively" << endl;
        De_Edge(output, '\"', '\"', true); // true makes it also remove start and end
        // cout << "Test 5" << endl;
    }
    return output;
}
// Remember here; unlike other fucntions of take cut, this returns error code not output redundantly; Returned is error code. Alhamdulilah rab al alameen
int Take_Int_Array_Cut(string &Main, int *&int_output_DMAd_Array_Or_Nullptr, int size, bool Remove_from_file, bool Remove_Following_Comma_After_Array_Ends)
{ // Types are read from right to left in cpp, *& is refrence to a ptr
    // Considering size is given before the array always (because are writinf levels like so ALhamdulilah)

    if (size <= 0)
    {
        cout << "Size: " << size << " is 0 or neg" << endl;
        return -1;
    }

    // If nullptr then then dmas it, else treats as already dmaed

    if (int_output_DMAd_Array_Or_Nullptr == nullptr)
    {
        int_output_DMAd_Array_Or_Nullptr = new int[size];
    }

    // error check may like no of commas check may be included later inshallah
    // First we must separate the array from the file_content

    string Array;                                                                 // Issue coming here
    Take_One_String_Cut(Main, Array, '[', ']', false, false, true, false, false); // We are not excluding the surrounding brackets [] from the string we take in, but we are removing the string from Main
    // Issue found we were deedging to remove " " but this [] didnt have any
    // Second issue, for some reason cuz we were doing string Array = the n usign array in parameters, it was causinga starge string in array changed that, Alhamdulilah rab al alameen
    // cout << "String for getting array: " << Array << endl;
    // cout << "File: " << Main << endl; // File and string getting for array are correct but decided is wrong
    // Now to also remove the comma after the array if it exsists
    if (Remove_Following_Comma_After_Array_Ends)
    {
        size_t Comman_loc = Main.find_first_of(',');

        // To add checks later if needed inshallah

        Comman_loc += 1;

        Main = Main.substr(Comman_loc); // this removes the string with first , and the things before it Alhamdulilah
    }
    // cout << "File: " << Main << endl;
    //  if only one element [etc]
    int Buffer_int = 0; // A reusable buffer int fpr getting indiviaual vals befiore putting into array
    // So we can safely apply checks if we want to add into code later inshallah
    if (size == 1)
    {
        Buffer_int = Take_One_Int_Cut(Main, Buffer_int, '[', ']', true, true, true, true); // Now i think the exxlcusive start and end bools for take one int were unecessary other than for if we dont want to remove, Allah swt knwos best
        // If needed apply checks
        int_output_DMAd_Array_Or_Nullptr[0] = Buffer_int;
        return 1; // Successful run
    }
    // if 2 or more

    else
    {
        // first int
        Take_One_Int_Cut(Array, Buffer_int, '[', ',', true, true, true, true); // removed the buffer= at start
        int_output_DMAd_Array_Or_Nullptr[0] = Buffer_int;
        // cout << int_output_DMAd_Array_Or_Nullptr[0] << endl;
        // cout << "file: " << Array << endl; // issue found: using main to search for the charcter, although we took apart the needed characters in an Array string, Alhamdulilah rab al alameen
        // middle ints
        for (int i = 1; i < size - 1; i++) // rus after first (0th) runs till one berfore end
        {
            Take_One_Int_Cut(Array, Buffer_int, Array[0], ',', false, true, true, true); // As previous , has been removed, the first char in the file_content should be the first char of int strin either space or part of umber , we cnant exlcude this from the int striing therefore. Hence this ararangement\
            //Second issue for first charcter we sent from main instead of from array too Alhamdulilah rab al alameen
            int_output_DMAd_Array_Or_Nullptr[i] = Buffer_int;
            // cout << int_output_DMAd_Array_Or_Nullptr[i] << endl;
            // cout << "file: " << Array << endl;
        }

        // last int
        Take_One_Int_Cut(Array, Buffer_int, Array[0], ']', false, true, true, true); // As previous , has been removed, the first char in the file_content should be the first char of int strin either space or part of umber , we cnant exlcude this from the int striing therefore. Hence this ararangement
        // same issue here
        int_output_DMAd_Array_Or_Nullptr[size - 1] = Buffer_int;

        // cout << int_output_DMAd_Array_Or_Nullptr[size - 1] << endl;
        // cout << "file: " << Array << endl;
        return 1; // Success
    }

    return 0; // Placeholder output, current logic shouldnt trigger it Alhamdulilah rab al alameen

    // if only 2 element [1,2]
}

int LevelManager::loadCatalogue() // needs var renaming for ease of understanding inshallah
{
    string filenameAndPath = LEVEL_AND_CATALOG_FILE_PATH; // This should include the extension
    filenameAndPath += LEVEL_CATALOG_FILENAME;            // Apparnetly cant do Name + path at intitalization of string or giving some red squiggle error Allah swt knwos best Alhamdulilah rab al alameen
    // issue : put path after file name, Fixed Alhamdulilah rab al alameen, All praise belongs to Allah swt
    //  Decision for later
    cout << "File name and path: " << filenameAndPath << endl;
    ifstream file;
    file.open(filenameAndPath);

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
        file_content += One_Line_Buffer; // One by one next string is concatenated to file_content                  // Cant do getline withofstream
                                         // Had accidently commented this line that concatenates buffer with content whicle commented test outputs, Fixed Alhamdulilah rab al alameen
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

int LevelCatalog::writeCatalogue(string file_content) // This data is the file ocnverted to a string
{

    if (this->Catalog_Of_Level_NFA_Maps != nullptr)
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

    // file_content = file_content.substr(starting_char_loc, Inclusive_Difference(starting_char_loc, ending_char_loc));// Self later: -> this line isnt doing anything...cuz we expect {} to be on the bourdaryies except spadces and \n\b\t... in the first place (so commented)
    //   This removes the outermost btackets so the current brackets left are the brakets for the Levels

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
    /*

    Because logic was changed to now have a separate object for each Act this cant be used freely, might be put inside the act inside inshallah
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
    */
    // cout << "test 4.8" << endl;
    Level_NFA_Map *Buffer_For_Catalog_Of_Level_NFA_Maps = nullptr; // is so we dont diretly store in important location
    Buffer_For_Catalog_Of_Level_NFA_Maps = new Level_NFA_Map[num];
    // cout << "test 5" << endl;
    int Levels_Read_Already_From_0 = 0; // For our ease
    int Current_Act = 1;
    // I belive we can also do this by iteration
    // Inshallah if time to refactor
    //+++++++++++++++++++++++++++++++++

    int Buffer_Act_1_Levels;
    Take_One_Int_Cut(file_content, Buffer_Act_1_Levels, ':', ',', true, true, true, true); // gets the no of acts_1 Levels

    string Act_1_Levels_String;
    Take_One_String_Cut(file_content, Act_1_Levels_String, '{', '}', true, true, true, true, false);

    string Buffer_Level_Name;
    string Buffer_File_Name_And_Path;
    for (int i = 0; i < Buffer_Act_1_Levels - 1; i++)
    {
        // We have to take the character from start to ,; and we have to go till last -1 level cuz the last level doesnt have any ending ,
        // Note we removed the {} in our funciton call

        Take_One_String_Cut(Act_1_Levels_String, Buffer_Level_Name, Act_1_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        Take_One_String_Cut(Act_1_Levels_String, Buffer_File_Name_And_Path, Act_1_Levels_String[0], ',', false, true, true, true, true);

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
    }

    if (Buffer_Act_1_Levels != 0)                                                                                                // if no level in act 1
    {                                                                                                                            // Issue found, these ending levels arent loading, and perhaps they are the ones to give starting char not found
        Take_One_String_Cut(Act_1_Levels_String, Buffer_Level_Name, Act_1_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // But the na,es reflect well the filenames dont appear
        //  Inshallah this will work
        // cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        // cout << "String Act 1 level string,: " << Act_1_Levels_String << endl;
        // cout << "The character: " << Act_1_Levels_String[0] << "|" << endl;

        // Issue discovered: both start and end of this string are coincidently spaces
        // The cut out string uses find first of
        // So it gets the same space in both start and end
        // The output string becomes | | (a space), which on trying to de-egde gives starting char not found
        // To solve we have to take a differnt approach, like sending the "" as to be excluded start and end and turning of remove quotation
        //  cout << "The character: " << Act_1_Levels_String[1] << endl;
        //  cout << "The character: " << Act_1_Levels_String[2] << endl;
        //  cout << "The character: " << Act_1_Levels_String[3] << endl;
        //  cout << "The character: " << Act_1_Levels_String[4] << endl;

        // Take_One_String_Cut(Act_1_Levels_String, Buffer_File_Name_And_Path, '\"', '\"', true, true, true, true, false); // puting from first character to last character into the string (as this is last) in this string, remove from orignal and deedge
        // This was failing due to many reasons, so sought a simpler approach Alhamdulilah rab al alameen

        De_Edge(Act_1_Levels_String, '\"', '\"', true);
        // Because DeEdge seaches start from start but end from end
        // If we call it directly, i wont cause issue when the chars are same inshallah
        // Now we also removed the bounfdary " chars, we simply need to store the string which remaind the last file name into the file name buffer
        // Alhamdulilah rab al alameen
        Buffer_File_Name_And_Path = Act_1_Levels_String;
        // Another issue
        // The take out string uses find from first for both first and last character
        // it wont work for having same start and end

        // Simpler approach cosnidered
        // Since the act string only has the string of needed filename right now
        // We de egde it directly and store the result in out needed buffer instead

        // So we considered the qutaotoion marks as the boundaries and turned the separately present degeing qutation marks off
        //..Alhamdamdulilah rab al alameen

        // cout << "Test 1" << endl;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
        // We must remove the starting , in the file for the first 3 acts
    }
    size_t Comma_loc = file_content.find_first_of(','); // must do for acts before act 4';
    Comma_loc += 1;                                     // to remove the , as well
    file_content = file_content.substr(Comma_loc);

    // file_content

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Current act changes to 2

    //=====================================

    Current_Act = 2;
    int Buffer_Act_2_Levels;
    Take_One_Int_Cut(file_content, Buffer_Act_2_Levels, ':', ',', true, true, true, true); // gets the no of acts_1 Levels

    string Act_2_Levels_String;
    Take_One_String_Cut(file_content, Act_2_Levels_String, '{', '}', true, true, true, true, false);

    for (int i = 0; i < Buffer_Act_2_Levels - 1; i++)
    {
        // We have to take the character from start to ,; and we have to go till last -1 level cuz the last level doesnt have any ending ,
        // Note we removed the {} in our funciton call

        Take_One_String_Cut(Act_2_Levels_String, Buffer_Level_Name, Act_2_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        Take_One_String_Cut(Act_2_Levels_String, Buffer_File_Name_And_Path, Act_2_Levels_String[0], ',', false, true, true, true, true);

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
    }

    if (Buffer_Act_2_Levels != 0)
    {
        Take_One_String_Cut(Act_2_Levels_String, Buffer_Level_Name, Act_2_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        // Take_One_String_Cut(Act_2_Levels_String, Buffer_File_Name_And_Path, '\"', '\"', true, true, true, true, false); // puting from first character to last character into the string (as this is last) in this string, remove from orignal and deedge
        De_Edge(Act_2_Levels_String, '\"', '\"', true);
        // Because DeEdge seaches start from start but end from end
        // If we call it directly, i wont cause issue when the chars are same inshallah
        // Now we also removed the bounfdary " chars, we simply need to store the string which remaind the last file name into the file name buffer
        // Alhamdulilah rab al alameen
        Buffer_File_Name_And_Path = Act_2_Levels_String;

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
        // We must remove the starting , in the file for the first 3 acts
    }
    Comma_loc = file_content.find_first_of(','); // must do for acts before act 4';
    Comma_loc += 1;                              // to remove the , as well
    file_content = file_content.substr(Comma_loc);

    //=====================================
    Current_Act = 3;
    int Buffer_Act_3_Levels;
    Take_One_Int_Cut(file_content, Buffer_Act_3_Levels, ':', ',', true, true, true, true); // gets the no of acts_1 Levels

    string Act_3_Levels_String;
    Take_One_String_Cut(file_content, Act_3_Levels_String, '{', '}', true, true, true, true, false);

    for (int i = 0; i < Buffer_Act_3_Levels - 1; i++)
    {
        // We have to take the character from start to ,; and we have to go till last -1 level cuz the last level doesnt have any ending ,
        // Note we removed the {} in our funciton call

        Take_One_String_Cut(Act_3_Levels_String, Buffer_Level_Name, Act_3_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        Take_One_String_Cut(Act_3_Levels_String, Buffer_File_Name_And_Path, Act_3_Levels_String[0], ',', false, true, true, true, true);

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
    }

    if (Buffer_Act_3_Levels != 0)
    {
        Take_One_String_Cut(Act_3_Levels_String, Buffer_Level_Name, Act_3_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        // Take_One_String_Cut(Act_3_Levels_String, Buffer_File_Name_And_Path, '\"', '\"', true, true, true, true, false); // puting from first character to last character into the string (as this is last) in this string, remove from orignal and deedge
        De_Edge(Act_3_Levels_String, '\"', '\"', true);
        // Because DeEdge seaches start from start but end from end
        // If we call it directly, i wont cause issue when the chars are same inshallah
        // Now we also removed the bounfdary " chars, we simply need to store the string which remaind the last file name into the file name buffer
        // Alhamdulilah rab al alameen
        Buffer_File_Name_And_Path = Act_3_Levels_String;

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
        // We must remove the starting , in the file for the first 3 acts
    }
    Comma_loc = file_content.find_first_of(','); // must do for acts before act 4';
    Comma_loc += 1;                              // to remove the , as well
    file_content = file_content.substr(Comma_loc);

    //=====================================
    Current_Act = 4;
    int Buffer_Act_4_Levels;
    Take_One_Int_Cut(file_content, Buffer_Act_4_Levels, ':', ',', true, true, true, true); // gets the no of acts_1 Levels

    string Act_4_Levels_String;
    Take_One_String_Cut(file_content, Act_4_Levels_String, '{', '}', true, true, true, true, false);

    for (int i = 0; i < Buffer_Act_4_Levels - 1; i++)
    {
        // We have to take the character from start to ,; and we have to go till last -1 level cuz the last level doesnt have any ending ,
        // Note we removed the {} in our funciton call

        Take_One_String_Cut(Act_4_Levels_String, Buffer_Level_Name, Act_4_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        Take_One_String_Cut(Act_4_Levels_String, Buffer_File_Name_And_Path, Act_4_Levels_String[0], ',', false, true, true, true, true);

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
    }

    if (Buffer_Act_4_Levels != 0)
    {

        Take_One_String_Cut(Act_4_Levels_String, Buffer_Level_Name, Act_4_Levels_String[0], ':', false, true, true, true, true); // first this gets a string till , then it removes the qotations marks, the first location may have the sttarting " so cant remove it in first step or the deedge might throw the start and end are same, on finding the same "
        // Inshallah this will work

        // Take_One_String_Cut(Act_4_Levels_String, Buffer_File_Name_And_Path, '\"', '\"', true, true, true, true, false); // puting from first character to last character into the string (as this is last) in this string, remove from orignal and deedge
        De_Edge(Act_4_Levels_String, '\"', '\"', true);
        // Because DeEdge seaches start from start but end from end
        // If we call it directly, i wont cause issue when the chars are same inshallah
        // Now we also removed the bounfdary " chars, we simply need to store the string which remaind the last file name into the file name buffer
        // Alhamdulilah rab al alameen
        Buffer_File_Name_And_Path = Act_4_Levels_String;

        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].name = Buffer_Level_Name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].file = Buffer_File_Name_And_Path;
        Buffer_For_Catalog_Of_Level_NFA_Maps[Levels_Read_Already_From_0].Act_no = Current_Act;

        Levels_Read_Already_From_0++;
    }
    // We must remove the starting , in the file for the first 3 acts

    // This takes out the level

    /*
    //Because the level was divided into four acts now this logic will be sub applied inshallah
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

        Buffer_For_Catalog_Of_Level_NFA_Maps[i].name = name;
        Buffer_For_Catalog_Of_Level_NFA_Maps[i].file = filename;

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

    Buffer_For_Catalog_Of_Level_NFA_Maps[num - 1].name = name;
    Buffer_For_Catalog_Of_Level_NFA_Maps[num - 1].file = filename; // last location is n-1
    */
    // cout << "test 7" << endl;
    // Alhamdulilah rab al alameen test 7 ran now to check if final catalog has the data copied properly inshallah
    //  this is final filename

    // Now the difference from other location is that we can simply use first " and last " to find the filename as no leading , should exsist

    //====================================================================

    // Num stored is updated at the end cuz valudation isnt completed yet

    //==================================================================
    // Considering we put other validation checks and no issues arrived we can safely trasnfer buffer to data of this and in the main catalog
    this->No_of_Levels = num; // Cant be neg, if written neg the function, string to number will end up removing it cuz it doesnt cosndierer sign other than numerics
    this->Act_1_Levels = Buffer_Act_1_Levels;
    this->Act_2_Levels = Buffer_Act_2_Levels;
    this->Act_3_Levels = Buffer_Act_3_Levels;
    this->Act_4_Levels = Buffer_Act_4_Levels;

    this->Catalog_Of_Level_NFA_Maps = Buffer_For_Catalog_Of_Level_NFA_Maps;
    cout << "Catalog Write To Store Object Success: " << endl; // Persistent debug output
    // cout << No_of_Levels << endl;
    /* This was for testing Alhamdulilah
    //**if we change the logic that if 0 memebrs then still can be initialized, we have to remove this pirce of the debug output, ...Actuakklluy we can make it confitonal
    if (Catalog_Of_Level_NFA_Maps != nullptr)
    {
        cout << Catalog_Of_Level_NFA_Maps[0].name << endl; // Atleast first entry must exsists elsewise returns with code 0(empty so not initialized)
        cout << Catalog_Of_Level_NFA_Maps[0].file << endl; // hence we can safely output [0]'s data for now Alhamudlilah rab al alameen
    }
    else
    {
        cout << "Catalog_Of_Level_NFA_Maps was nullptr" << endl;
    }*/
    // If change we have to rem0ve this inshallah
    return 1; // successful write
    // Now we have to locate and cut out the string that contains the levels
} // To test this before proceding inshallah

int LevelCatalog::deleteCatalog()
{
    // See if no catalog exsists , returns 0
    // If exsists deletes it, returns 1

    if (this->Catalog_Of_Level_NFA_Maps == nullptr)
    {
        this->No_of_Levels = 0; // Just confirming if issues with numbers we set it to 0
        return 0;
    }

    // else

    delete[] this->Catalog_Of_Level_NFA_Maps;
    this->Catalog_Of_Level_NFA_Maps = nullptr; // Cuz nullptr is checked later on (alhamdulialah rab al alameen) (This may be reused)
    this->No_of_Levels = 0;
    return 1; // Deleted current stored map
}

LevelCatalog::~LevelCatalog()
{
    this->deleteCatalog(); // Simply delete using already made function
    // deletes the made array if exsists in heap
    // Alhamdulilah rab al alameen
}

int LevelManager::loadLevel(int id) // I think we also need to make detection system to tell if the level descriiton has a comma (because that causes current parcer logic to err..., May Allah help us Ameen)
{
    //
    if (this->Catalog.Catalog_Of_Level_NFA_Maps == nullptr)
    {
        cout << "Catalog is empty" << endl;
        return -1;
    }

    if (id < 0 || id >= this->Catalog.No_of_Levels) // out of range
    {
        cout << "id is out of range" << endl;
        return -2;
    }

    ifstream file;
    string filenameAndPath = LEVEL_AND_CATALOG_FILE_PATH;                // Issue was that we put path after name, fixed ALhamdulilah
    filenameAndPath += this->Catalog.Catalog_Of_Level_NFA_Maps[id].file; // Changed simple use of only name to also including path
    cout << "Level file name with path: " << filenameAndPath << endl;

    file.open(filenameAndPath); // This correction was added because couldnt load as missing file path

    if (!file.is_open()) // Issue found, Alhamdulilah, the string inside catalog, for filename of level 2 was missing the _ hence it was getting a not found issue, alhamdulilah rab al alameen
    {
        cout << "couldnt open file having path (relative to inside build folder): " << filenameAndPath << endl;
        return 0; // Error state but depicts a specific type of output hence got error code 0
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
        file_content += One_Line_Buffer; // One by one next string is concatenated to file_content                  // Cant do getline withofstream
                                         // Had accidently commented this line that concatenates buffer with content whicle commented test outputs, Fixed Alhamdulilah rab al alameen
    }

    int WriteLevelsReturn = this->CurrentLevelData.writeData(file_content, this->Catalog.Catalog_Of_Level_NFA_Maps[id].Act_no);

    return 1; // Success
}

// Note protoype has deafult paramters
int LevelData::writeData(string file_content, int Act_No_From_Catalog) // To change parameters and add Int act no ,instead of reading act from file see atalogue registry inshallah soon
{
    if (this->act_1_data != nullptr || this->act_2_data != nullptr || this->act_3_data != nullptr || this->act_4_data != nullptr)
    {
        cout << "Level Data Already exsists" << endl;
        return 0;
    }

    trim(file_content);
    if (file_content.empty())
    {
        cout << "File Content is empty" << endl;
        return -1;
    }
    // cout << "Test -1" << endl;
    size_t starting_char_loc = file_content.find_first_not_of("\t\b\n ");

    if (file_content[starting_char_loc] != '{') // should have returned location
    {
        cout << "Starting { in json not found/first char isnt {| logic: outermost non space characters should be {} " << endl;
        return -2; // Starting { is missing
    }
    size_t ending_char_loc = file_content.find_last_not_of("\t\b\n "); // Correction, had searched for first not of, while intending to search for last not of, bezuse we assume json is valid if} at end
    // corrected, Alhamdulilah rab al alameen

    // Issue found why not displaying the ending char loc, it was made char, i remade it into size t (after intiitaly doing int)
    // Range of char is -128 to 127 so it couldnt contain a value like { and probaly wrapped around several times, hence giving issues
    // But we  couldnt even view the value of ending char loc cuz it was char and likely printing invisible character cuz made ascii of invisible character
    // Allah swt knows best
    // Alhamdulilah rab al alameen

    if (file_content[ending_char_loc] != '}') // should have returned location, fixed alhamdulilah by fixing trim in both places, changinf start-end+1 to end - start +1, andchnaging char to size_t, Alhamdulilah rab al alameen
    {
        // cout << "Loc given by ending char loc: " << ending_char_loc << endl; // debugging tests

        // cout << "Size of file_Content: " << file_content.size() << endl;
        cout << "Ending } in json not found/last char isnt }| logic: outermost non space characters should be {}" << endl;
        return -3; // ending } is missing
    }
    // cout << "Test 0" << endl;
    //  Have to read the act
    int Buffer_Act_No;

    cout << "Act Number Gotten From Catalog" << endl; // If this is off
    Buffer_Act_No = Act_No_From_Catalog;              // removed featiure of reading act no from file if not sent from catalog

    // cout << "Test 0.2" << endl;

    // Description also same in each act

    string Buffer_Description;
    Cut_Of_String(file_content, Buffer_Description, ':', ',', true, true, true, true);
    // cout << "Description found is: " << Buffer_Description << endl; // Issue discovered, there is a comma in the description
    // cout << file_content << endl;
    // cout << "Test 0.3" << endl;
    De_Edge(Buffer_Description, '\"', '\"', true); // This should remove things other than the string isnide the ""
    // cout << "Description found is after deedging: " << Buffer_Description << endl;
    // Issue found, if the description has a comma (,) in it the parcer detects that, rule is description cant have a comma or a colon, it may use semicols and period. Alhamdulilah rab al alameen
    //  now in the description we have extra space along with " "'s included which we need to remove

    // I think we should build off separate function for this (to use find last char instead of fiind first, also using same think refrence for file.conetent and the outept may be harmul, consideirng we remove the string from the orignal file.... if the bool for reomoeve is true, meaning it might be dangerous if we make a mistake or logic is edited,Allah swt knows best, Alhamdulilah rab al alameen)

    int Buffer_Nodecount = Take_One_Int_Cut(file_content, Buffer_Nodecount, ':', ',', true, true, true, true);

    int Buffer_NodeCap = Take_One_Int_Cut(file_content, Buffer_NodeCap, ':', ',', true, true, true, true);
    // cout << "Found node count is: " << Buffer_Nodecount << endl; // Alhamdulilah rab al alameen, acurate

    if (Buffer_Nodecount < 0)
    {
        cout << "Nodecount calculated is neg: current count logic gets absilute, hence either too big no or logic changed after writing this" << endl;
        return -5;
    }
    if (Buffer_Nodecount == 0)
    {
        cout << "No of nodes= 0" << endl;
        return 2; // I am think an empty structure is fine and valid but shows somehting else on screen hence alloted 2, also we cant really take node insuts after this
    }

    // cout << "Test 1" << endl;
    string Buffer_Mode;

    Take_One_String_Cut(file_content, Buffer_Mode, ':', ',', true, true, true, true); // For getting string (this function also rmoves the " and the  spaces around the string (not the ones inside "" but the ones outside "")")Alhamdulilah rab al alameen

    // cout << "Mode: " << Buffer_Mode << endl;
    if (Buffer_Mode == "Stored") // Alhamdulilah working
    {
        // Logic 1
        // cout << "stored mode" << endl; // persistent output ,for debugging

        if (Buffer_Act_No == 1) // Node removed the inorder insertorde rstoring logic now storing the tree in preorder # form
        {
            // int *Buffer_Inorder = nullptr;
            //  cout << "File: " << file_content << endl;
            // Take_Int_Array_Cut(file_content, Buffer_Inorder, Buffer_Nodecount, true, true); // later to confirm and puti nsdie act if success in this if block inshallah
            /*
            cout << "Inorder:  ";
            for (int i = 0; i < Buffer_Nodecount; i++)
            {
                cout << Buffer_Inorder[i];
            }
            cout << endl;*/
            // cout << "File: " << file_content << endl;
            // int *Buffer_Preorder = nullptr;                                                   // This nullptr is critical else array desnt get initailized
            // Take_Int_Array_Cut(file_content, Buffer_Preorder, Buffer_Nodecount, true, false); // later to confirm and puti nsdie act if success in this if block inshallah
            Act_1_Data *Buffer_Act_1_Data = new Act_1_Data;
            // Buffer_Act_1_Data->Inorder = Buffer_Inorder;
            // Buffer_Act_1_Data->Preorder = Buffer_Preorder;

            /*cout << "Preorder: ";
            for (int i = 0; i < Buffer_Nodecount; i++)
            {

                cout << Buffer_Preorder[i];
            }
            cout << endl;*/
            // Considering everuthing is validated atp

            this->act_1_data = Buffer_Act_1_Data;
        }
        else if (Buffer_Act_No == 2)
        {
            // cout << "Test 3" << endl;
            // int *Buffer_Insertorder;
            // Take_Int_Array_Cut(file_content, Buffer_Insertorder, Buffer_Nodecount, true, false); // later to confirm and puti nsdie act if success in this if block inshallah
            Act_2_Data *Buffer_Act_2_Data = new Act_2_Data;
            // Buffer_Act_2_Data->InsertOrder = Buffer_Insertorder;
            this->act_2_data = Buffer_Act_2_Data; // puting in real level data
            // cout << "Test 4" << endl;
        }
        else if (Buffer_Act_No == 3)
        {
            // int *Buffer_Insertorder;
            // Take_Int_Array_Cut(file_content, Buffer_Insertorder, Buffer_Nodecount, true, false); // later to confirm and puti nsdie act if success in this if block inshallah
            Act_3_Data *Buffer_Act_3_Data = new Act_3_Data;
            // Buffer_Act_3_Data->InsertOrder = Buffer_Insertorder;
            this->act_3_data = Buffer_Act_3_Data;
        }
        else if (Buffer_Act_No == 4)
        {
            // int *Buffer_Heap;
            // Take_Int_Array_Cut(file_content, Buffer_Heap, Buffer_Nodecount, true, false); // later to confirm and puti nsdie act if success in this if block inshallah
            Act_4_Data *Buffer_Act_4_Data = new Act_4_Data;
            // Buffer_Act_4_Data->Heap = Buffer_Heap;
            this->act_4_data = Buffer_Act_4_Data; // These data types serve to tell if an act exsists (if level laoded so keeping them) May Allah swt guide us ameen
        }
        // Decided that in stored mode the tree will be at end, so inserted act datas will be behind it
        // Considering only the Tree remains in the string of file content as it is at end

        // De_Edge(file_content, '\"', '\"', true);
        string Buffer_Tree_String = file_content;
        cout << "++++++++++++++++++++++++++++" << endl; // Issue found: Tree: there was a colon in string, we also need to forbid that
        cout << file_content << endl;
        Take_One_String_Cut(file_content, Buffer_Tree_String, ':', '}', true, true, true, true, true); //
        this->Tree = Buffer_Tree_String;
    }
    else if (Buffer_Mode == "Seeded") // it appears we have used Seeded  instead of seed, which sounds more proper so going with thism Alhamdulilah rab al alameen
    {
        // Logic 2
        // cout << "seeded mode" << endl; // Found issue, forgot to get seed before  max, so max got seed val, and min got both max and min, (cuz the get cut of string ran till })                                                               // persistent output ,for debugging
        int Buffer_Seed = Take_One_Int_Cut(file_content, Buffer_Seed, ':', ',', true, true, true, true);
        int Buffer_Max = Take_One_Int_Cut(file_content, Buffer_Max, ':', ',', true, true, true, true); // I am thinking of add a bool for dont remove orignal start and beforewards(maynot not inshallah, Allahh swt knows best)
        int Buffer_Min = Take_One_Int_Cut(file_content, Buffer_Min, ':', ',', true, true, true, true); // I am thinking of add a bool for dont remove orignal start and beforewards(maynot not inshallah, Allahh swt knows best)
        // NOte we didnt remove ending } in this function
        cout << "Seed: " << Buffer_Seed << " Max:" << Buffer_Max << " min: " << Buffer_Min << endl;

        if (Buffer_Act_No == 1)
        {
            // Generation logic for a tree using rand, the gettign its inorder and preorder
            Act_1_Data *Buffer_Act_1_Data = new Act_1_Data; // making a buffer
            // Making buffer have data
            this->act_1_data = Buffer_Act_1_Data; // Puting buffer in main
        }
        else if (Buffer_Act_No == 2)
        {
            int Buffer_Forced_Skewness = Take_One_Int_Cut(file_content, Buffer_Forced_Skewness, ':', '}', true, true, true, true);
            Act_2_Data *Buffer_Act_2_Data = new Act_2_Data;              // Make buffer the acts specific data
            Buffer_Act_2_Data->Forced_Skewness = Buffer_Forced_Skewness; // put data in that buffer
            this->act_2_data = Buffer_Act_2_Data;                        // Put buffer into the levels act specifc storage
        }
        else if (Buffer_Act_No == 3)
        {
            Act_3_Data *Buffer_Act_3_Data = new Act_3_Data; // making a buffer
            // Making buffer have data
            this->act_3_data = Buffer_Act_3_Data; // Puting buffer in main
        }
        else if (Buffer_Act_No == 4)
        {
            Act_4_Data *Buffer_Act_4_Data = new Act_4_Data; // making a buffer
            // Making buffer have data
            this->act_4_data = Buffer_Act_4_Data; // Puting buffer in main
        }

        this->seed = Buffer_Seed; // in seeded mode, irrespective of act these hold, Alhamdulilah
        this->Max = Buffer_Max;
        this->Min = Buffer_Min;
    }
    else
    {
        cout << "Invlaid Mode" << endl;
        return -6;
    }

    this->NodeCapacity = Buffer_NodeCap;
    this->Act = Buffer_Act_No; // Irrespective of mode or act this holds, Alhamdulilah
    this->Description = Buffer_Description;
    this->nodeCount = Buffer_Nodecount;
    this->mode = Buffer_Mode;

    return 1; // Standard success
}
int LevelData::deleteData()
{

    if (this->act_1_data == nullptr && this->act_2_data == nullptr && this->act_3_data == nullptr && this->act_4_data == nullptr)
    {
        cout << "No act data exists" << endl; // The act datas still serve to tell if level has data; and better than seeing if act =0
        return 0;
    }
    else if (this->act_1_data != nullptr)
    {
        delete this->act_1_data;
        this->act_1_data = nullptr;
        this->Act = 0;
    }
    else if (this->act_2_data != nullptr)
    {
        delete this->act_2_data;
        this->act_2_data = nullptr;
        this->Act = 0;
    }
    else if (this->act_3_data != nullptr)
    {
        delete this->act_3_data;
        this->act_3_data = nullptr;
        this->Act = 0;
    }
    else if (this->act_4_data != nullptr)
    {
        delete this->act_4_data;
        this->act_4_data = nullptr;
        this->Act = 0;
    }
    cout << "Deleteion success" << endl;
    return 1; // Standard success
    // Btw i notices if do build play button and then change file
    // Perhaps ignores changes and runs successguly (i returned the return 1's , 1 to see, and ran Alhamdulilah rab al alameen)
}
