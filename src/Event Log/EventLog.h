// Bismillah hirahman nirahim

// #ifndef EvenLog

// #endif

#include <iostream>
using namespace std; // we need this to do string name, elsewiase it wotnt recognize string

struct VISIT_Data
{
};
struct COMPARE_Data
{
};
struct INSERT_Data
{
};

struct UNLINK_Data
{
};
struct SWAP_VALUE_Data
{
};

struct ROTATE_Data
{
};

struct UPDATE_HEIGHT_OR_UPDATE_SIZE_Data // To see if UPDATE_SIZE is the exact same event or two different events with same data and decide if needs change inshallah
{
};

struct BALANCE_ALERT_Data
{
};

struct HIGHLIGHT_SUBTREE_Data
{
};

struct HEAP_BUILD_Data
{
};

struct HEAP_SWAP_Data
{
};

struct HEAPIFY_START_OR_HEAPIFY_DONE_Data // To later decide if needs two separate structures  with same data within inshallah
{
};

struct EXTRACT_MAX_Data
{
};

struct MARK_SORTED_Data
{
};

struct HEAP_SIZE_CHANGE_Data
{
};

struct HEAP_SORT_COMPLETE_Data
{
};

struct DONE_Data
{
};

struct Event
{
    string name;
    void *Data; // The data type of this is recognized using the name of the event
};