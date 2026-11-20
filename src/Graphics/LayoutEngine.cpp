#include<iostream>
#include<string>
#include "src\Data Structures\BT.cpp"
#include "src\Data Structures\MaxHeap.cpp"
using namespace std;

struct Coordinates{
    int id;
    float x;
    float y;
    Coordinates(int i){
        id=i;
        x=0;
        y=0;
    }
    Coordinates(){
        id=-1;
        x=0;
        y=0;
    }
};

class Layout{
    public:
    Coordinates nodes[200];
    int count;
    int col;
    Layout(){
        count=col=0;
    }

    void assignID(int i){
        nodes[count].id=i;
    }

    void TreeL(TreeNode* root, int num){ //num here is the depth of the tree
        if (root==NULL){
            return;
        }

        TreeL(root->left, num+1);

        nodes[count].id=root->id;
        nodes[count].x=40+col*40;
        nodes[count].y=60+num*40;
        count++;
        col++;

        TreeL(root->right, num+1);
    }

    void calltree(TreeNode* root){
        count=0;
        col=0;
        TreeL(root, 0);
    }

    void HeapL(MaxHeap* h){
        count=0;
        for (int i=0;i<h->filled;i++){
            int level=0;
            int firstIndex=0;
            int slots=1;
             while(i >= firstIndex + slots){
            firstIndex = firstIndex + slots;
            slots = slots * 2;
            level++;
            }
            int pos = i - firstIndex;
            nodes[count].id = i;
            nodes[count].x = (pos + 0.5) * 1200 / slots;
            nodes[count].y = 40 + level * 60;
            count++;
        }
    }

    bool position(int id, float& hor, float &ver){
        for(int i = 0; i < count; i++){
        if(nodes[i].id == id){
            hor = nodes[i].x;
            ver = nodes[i].y;
            return true;
        }
    }
    return false;
    }
};