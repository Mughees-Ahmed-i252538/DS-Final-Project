// Bismillah hirahman nirahim

#include "EventLog.h"
#define INITIAL_CAPACITY 2
#define CAPACITY_MULTIPLIER 2

void EventModel::AddEvent(string name, void *data)
{
    if (cap == 0)
    {
        this->cap = INITIAL_CAPACITY;
        this->EventLog = new Event[cap];
    }
    else if (top + 1 == cap)
    {
        int new_cap = cap * 2;
        Event *New_EvenLog = new Event[new_cap];

        for (int i = 0; i < cap; i++)
        {
            New_EvenLog[i] = EventLog[i]; // By value copying
            // Deletion of event data is done by  the Event log who knows their data type
            // But if an event itself is deleted before the event model is; its data isnt
        }

        delete[] EventLog; // Doesnt delete the data
        EventLog = New_EvenLog;
        cap = new_cap;
    }

    this->EventLog[++top].name = name;
    this->EventLog[top].Data = data;
}

EventModel::~EventModel()
{
    for (int i = 0; i <= top; i++)
    { // recognizes the type of data stored for each event and calls its destructor by doing delete data; eg delete Compare Data
        if (EventLog[i].name == "VISIT")
        {
            delete (VISIT_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "COMPARE")
        {
            delete (COMPARE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "INSERT")
        {
            delete (INSERT_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "UNLINK")
        {
            delete (UNLINK_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "SWAP_VALUE")
        {
            delete (SWAP_VALUE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "ROTATE")
        {
            delete (ROTATE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "UPDATE_HEIGHT_OR_UPDATE_SIZE")
        {
            delete (UPDATE_HEIGHT_OR_UPDATE_SIZE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "BALANCE_ALERT")
        {
            delete (BALANCE_ALERT_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HIGHLIGHT_SUBTREE")
        {
            delete (HIGHLIGHT_SUBTREE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HEAP_BUILD")
        {
            delete (HEAP_BUILD_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HEAP_SWAP")
        {
            delete (HEAP_SWAP_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HEAPIFY_START_OR_HEAPIFY_DONE")
        {
            delete (HEAPIFY_START_OR_HEAPIFY_DONE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "EXTRACT_MAX")
        {
            delete (EXTRACT_MAX_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "MARK_SORTED")
        {
            delete (MARK_SORTED_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HEAP_SIZE_CHANGE")
        {
            delete (HEAP_SIZE_CHANGE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "HEAP_SORT_COMPLETE")
        {
            delete (HEAP_SORT_COMPLETE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
        else if (EventLog[i].name == "DONE")
        {
            delete (DONE_Data *)EventLog[i].Data; // Turns ptr to what is orignally was and deletes
        }
    }
}

void EventModel::VISIT(int nodeId)
{

    VISIT_Data *data = new VISIT_Data;
    data->nodeId = nodeId;
    string name = "VISIT";
    AddEvent(name, (void *)data);
}

void EventModel::COMPARE(int nodeId, int key, char result)
{
    COMPARE_Data *data = new COMPARE_Data;
    data->nodeId = nodeId;
    data->key = key;
    data->result = result;
    string name = "COMPARE";
    AddEvent(name, (void *)data);
}

void EventModel::INSERT(int nodeId, int key, int side)
{
    INSERT_Data *data = new INSERT_Data;
    data->nodeId = nodeId;
    data->key = key;
    data->side = side;
    string name = "INSERT";
    AddEvent(name, (void *)data);
}

void EventModel::UNLINK(int nodeId, int key, int side)
{
    UNLINK_Data *data = new UNLINK_Data;
    data->nodeId = nodeId;
    data->key = key;
    data->side = side;
    string name = "UNLINK";
    AddEvent(name, (void *)data);
}

void EventModel::SWAP_VALUE()
{
    SWAP_VALUE_Data *data = new SWAP_VALUE_Data;
    // Old and new data nodes names not yet known
    string name = "SWAP_VALUE";
    AddEvent(name, (void *)data);
}

void EventModel::ROTATE(string type, int pivotId)
{
    ROTATE_Data *data = new ROTATE_Data;
    data->type = type;
    data->pivotId = pivotId;
    string name = "ROTATE";
    AddEvent(name, (void *)data);
}

void EventModel::UPDATE_HEIGHT_OR_UPDATE_SIZE(int nodeId, int old_, int new_) // to see if the tasks need to be diviided into update size and opdate height or same is ok as we make act inshallah
{
    UPDATE_HEIGHT_OR_UPDATE_SIZE_Data *data = new UPDATE_HEIGHT_OR_UPDATE_SIZE_Data;
    data->nodeId = nodeId;
    data->old_ = old_;
    data->new_ = new_;
    string name = "UPDATE_HEIGHT_OR_UPDATE_SIZE";
    AddEvent(name, (void *)data);
}
// Not known whether this should be two differnet function
void EventModel::BALANCE_ALERT(int nodeId, int balanceFactor)
{
    BALANCE_ALERT_Data *data = new BALANCE_ALERT_Data;
    data->nodeId = nodeId;
    data->balanceFactor = balanceFactor;
    string name = "BALANCE_ALERT";
    AddEvent(name, (void *)data);
}

void EventModel::HIGHLIGHT_SUBTREE(int nodeId, string mode)
{
    HIGHLIGHT_SUBTREE_Data *data = new HIGHLIGHT_SUBTREE_Data;
    data->nodeId = nodeId;
    data->mode = mode;
    string name = "HIGHLIGHT_SUBTREE";
    AddEvent(name, (void *)data);
}

//! MASSIVE DECISION: Should we make this a deep copy? Inorder to save snapshots instead of address to array itself, I lean towards yes, but not doing for now because much is unclear wrt this module
void EventModel::HEAP_BUILD(int *array, int size, int start_indices)
{
    HEAP_BUILD_Data *data = new HEAP_BUILD_Data;
    data->array = array;
    data->size = size;
    data->start_indices = start_indices;
    string name = "HEAP_BUILD";
    AddEvent(name, (void *)data);
}

void EventModel::HEAP_SWAP(int indexA, int indexB, string reason)
{
    HEAP_SWAP_Data *data = new HEAP_SWAP_Data;
    data->indexA = indexA;
    data->indexB = indexB;
    data->reason = reason;

    string name = "HEAP_SWAP";
    AddEvent(name, (void *)data);
}

void EventModel::HEAPIFY_START_OR_HEAPIFY_DONE(int startIndex, int heapSize) // Perhaps divided into two; one for start and one for done, as see need of, inshallah
{
    HEAPIFY_START_OR_HEAPIFY_DONE_Data *data = new HEAPIFY_START_OR_HEAPIFY_DONE_Data;
    data->startIndex = startIndex;
    data->heapSize = heapSize;
    string name = "HEAPIFY_START_OR_HEAPIFY_DONE";
    AddEvent(name, (void *)data);
}
// Not known whether this should be two differnet function
void EventModel::EXTRACT_MAX(int value, int rootIndex, int heapSize) // self: doing alt plus backspace removes all spaces in vs code to start of line... to be confirmed if always does this inshallah soon
{
    EXTRACT_MAX_Data *data = new EXTRACT_MAX_Data;
    data->value = value;
    data->rootIndex = rootIndex;
    data->heapSize = heapSize;
    string name = "EXTRACT_MAX";
    AddEvent(name, (void *)data);
}
// Rand knowledge, to be overridden fucntion must match the parameters of orignal too

// The regular expression find and replace mode in vs code lets you replace things with next line and so on and also helps seach more than simple chars
// Some chars used in its format like . have to do \. to search literal char dot;....
// Alhamdulilah rab al alameen

void EventModel::MARK_SORTED(int index, int value)
{
    MARK_SORTED_Data *data = new MARK_SORTED_Data;
    data->index = index;
    data->value = value;
    string name = "MARK_SORTED";
    AddEvent(name, (void *)data);
}

void EventModel::HEAP_SIZE_CHANGE(int oldSize, int newSize)
{
    HEAP_SIZE_CHANGE_Data *data = new HEAP_SIZE_CHANGE_Data;
    data->oldSize = oldSize;
    data->newSize = newSize;
    string name = "HEAP_SIZE_CHANGE";
    AddEvent(name, (void *)data);
}

void EventModel::HEAP_SORT_COMPLETE(int *array, int size)
{
    HEAP_SORT_COMPLETE_Data *data = new HEAP_SORT_COMPLETE_Data;
    data->array = array;
    data->size = size;
    string name = "HEAP_SORT_COMPLETE";
    AddEvent(name, (void *)data);
}
// Data types stored still not confimed, may change when we come to using this inshallah
void EventModel::DONE(string summary)
{
    DONE_Data *data = new DONE_Data;
    data->summary = summary;
    string name = "DONE";
    AddEvent(name, (void *)data);
}
