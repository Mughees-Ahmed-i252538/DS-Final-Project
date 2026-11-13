// Bismillah hirahman nirahim

// #ifndef EvenLog

// #endif

#include <iostream>
using namespace std; // we need this to do string name, elsewiase it wotnt recognize string

struct VISIT_Data // What each event data contains is still subject to change as the acts as made
{                 // For now based on datatype inference based on details given
    int nodeId = 0;
};
struct COMPARE_Data
{
    int nodeId = 0;
    int key = 0;
    char result = 0; // This one has a high chance of changing,Allah swt knows best
};
struct INSERT_Data
{
    int nodeId = 0;
    int key = 0;
    int side = 0; // This one has a high chance of changing,Allah swt knows best
};

struct UNLINK_Data
{
    int nodeId = 0;
    int key = 0;
    int side = 0; // This one has a high chance of changing,Allah swt knows best
};
struct SWAP_VALUE_Data
{
    // Node* nodeA;
    // Node* nodeB;//Data type name yet uncertain
};

struct ROTATE_Data
{
    string type = "  "; // type uncertain but LL,LR,RR,RL are possible values
    int pivotId;
};

struct UPDATE_HEIGHT_OR_UPDATE_SIZE_Data // To see if UPDATE_SIZE is the exact same event or two different events with same data and decide if needs change inshallah
{
    int nodeId = 0;
    int old_ = 0; // Guesses, => these likely mean heights
    int new_ = 0; // have to name this cuz new is a keyword
};

struct BALANCE_ALERT_Data
{
    int nodeId = 0;
    int balanceFactor = 0;
};

struct HIGHLIGHT_SUBTREE_Data
{
    int nodeId = 0;
    string mode = "       "; // I think max not \0 chars are 7
    // Stores mode (visited,skipped, result)
    // Data type guesses
}; // May chaninge to int if possible for conveniece

struct HEAP_BUILD_Data
{ // This specific block is highly suceptable to change inshallah, will make appropriate datatypes when confimed function
    int *array;
    int size = 0;
    int start_indices = 0;
}; // To explore meannig of start_indices what does it store

struct HEAP_SWAP_Data
{
    int indexA = 0;
    int indexB = 0;
    string reason; // Not known size of
    // Data type yet uncormed, but likely percualte up or percualte down inshallah
};

struct HEAPIFY_START_OR_HEAPIFY_DONE_Data // To later decide if needs two separate structures  with same data within inshallah
{
    int startIndex = 0;
    int heapSize = 0;
};

struct EXTRACT_MAX_Data
{
    int value = 0;
    int rootIndex = 0;
    int heapSize = 0;
};

struct MARK_SORTED_Data
{
    int index = 0;
    int value = 0;
};

struct HEAP_SIZE_CHANGE_Data
{
    int oldSize = 0;
    int newSize = 0;
};

struct HEAP_SORT_COMPLETE_Data
{
    int *array;   // Data types stored still not confimed, may change when we come to using this inshallah
    int size = 0; // final array
};

struct DONE_Data
{
    string summary; // may change if needed inshallah will situatin, still nnot confimed use
};

// May also add data in things eg rotate to be able to undo and rotate
// Can also do snapshots, aka serialization (then shift to inverse events if time allows inshallah)//i think lets op for snapshots
struct Event
{
    string name;
    void *Data; // The data type of this is recognized using the name of the event
    // I am planning a different function for each event registration
};
// I believe we might need different data for visit to a bst and a bt,
// So cant finalize without seeing the acts themselves

struct EventModel
{
    int cap = 0;
    int top = -1;
    Event *EventLog = nullptr; // A ty

    void AddEvent(string name, void *data);
    // Not known whether repeats of same event for different strutts like both bst and bt may visit
    // If so i think i will make a differnet copy for them and make unique namess to ease undo inshallah
    void VISIT();
    void COMPARE();
    void INSERT();
    void UNLINK();
    void SWAP_VALUE();
    void ROTATE();
    void UPDATE_HEIGHT_OR_UPDATE_SIZE(); // Not known whether this should be two differnet function
    void BALANCE_ALERT();
    void HIGHLIGHT_SUBTREE();
    void HEAP_BUILD();
    void HEAP_SWAP();
    void HEAPIFY_START_OR_HEAPIFY_DONE(); // Not known whether this should be two differnet function
    void EXTRACT_MAX();
};