// bismillah hirahman nirahim

// This is a different layout engine

#include "../Interface/UIManager.h"

int Find_Sprite_Loc_And_Size(bool is_root, sf::Vector2f Parent_Loc, sf::RenderWindow &window, int NodeCapacity, sf::Vector2f &Current_Loc, sf::Vector2f &Current_Siz, bool Is_Left_Child, int Current_index)
{

    // First we have to see what is max level of node

    // We have to ensure that we choose such a distance that the node stays inside the screen
    // And a suitable position
    int Max_Level_Including_Node_As_1 = 0;           // cosnidering if root only then level is 1
    for (int i = 0; i < NodeCapacity; i = i * 2 + 1) // going to left child
    {
        Max_Level_Including_Node_As_1++;
    }

    float node_size_x;
    float node_size_y;

    float distance_bw_nodes_x;
    float distance_bw_nodes_y;

    // so Max level (based on nodes not paths)
    //  6*window.size.x/8 should be equal to node size*Max level + pathsize*MaxLevel-1
    //  Size of a node

    // Lets sa=tart with size  + oath
    int Window_view_Size_x = window.getView().getSize().x;
    int Window_view_Size_y = window.getView().getSize().y;

    float SP_x = (6 * Window_view_Size_x / 8) / Max_Level_Including_Node_As_1; // This is the distance we can divide screen into levels

    float SP_y = (6 * Window_view_Size_y / 8) / Max_Level_Including_Node_As_1;

    node_size_x = 5 * SP_x / 11;
    node_size_y = 5 * SP_x / 11;

    distance_bw_nodes_x = 6 * SP_x / 11;

    distance_bw_nodes_y = 5 * SP_x / 11;

    // We need to find which level if the current node on

    int Level_of_Current = 1;

    int temp = Current_index;

    while (temp != 0) // if root then level 1
    {
        temp = (temp - 1) / 2;
        Level_of_Current++;
    }

    cout << "|||||Level of Current||||||: " << Level_of_Current << endl;
    cout << " Y ofset based on level: " << ((Level_of_Current * (30.0 / (Max_Level_Including_Node_As_1)))) << endl;

    // now we say that a node is 5/11 of sp and a path is 6/11 (such that 2 nodes dont intersect)

    // Now considering that these levels should fit in 6/8 of the screen
    Current_Siz.x = node_size_x;
    Current_Siz.y = node_size_y;
    if (is_root)
    {

        return 0; // we dont decide node pistion
    }
    else
    {

        if (Is_Left_Child)
        {
            Current_Loc.x = distance_bw_nodes_x + Parent_Loc.x; // Considering this would fit non origin genometric centered ?
            // Allah swt knows best
            Current_Loc.y = +distance_bw_nodes_y + Parent_Loc.y - (distance_bw_nodes_y * (0.99) * ((float)Level_of_Current / Max_Level_Including_Node_As_1)); // if left then is above
        }
        else
        {
            Current_Loc.x = distance_bw_nodes_x + Parent_Loc.x; // Considering this would fit non origin genometric centered ?
            // Allah swt knows best
            Current_Loc.y = -distance_bw_nodes_y + Parent_Loc.y + (distance_bw_nodes_y * (0.99) * ((float)Level_of_Current / Max_Level_Including_Node_As_1)); // if right then below
        } // if this 0.8 goes above 1 it flips side of node
    } // making right child top

    return 1;
}