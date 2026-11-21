#include <iostream>
#include <string>
#include "BT.cpp"
#include "src\Data Structures\BST.cpp"

struct AVLNode : public BSTNode
{
    int height;
    int size;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
    AVLNode(int v)
    {
        height = 1;
        size = 1;
        value = v;
        left = nullptr;
        left = static_cast<AVLNode *>(TreeNode::left);
        right = static_cast<AVLNode *>(TreeNode::right);
        parent = static_cast<AVLNode *>(TreeNode::parent);
    }
};

int getBalanceFactor(AVLNode *root)
{
    return (root->left->height - root->right->height);
}

int getHeight(AVLNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    return node->height;
}

<<<<<<< HEAD
int getSize(AVLNode* root){
    if (root==NULL){
        return 0;
    }
    return root->size;
}

AVLNode* insert(AVLNode* root, int key){//consider: user tree
    if (root==NULL){
        AVLNode* temp=new AVLNode(key);
        return temp;;
=======
AVLNode *insert(AVLNode *root, int key)
{ // consider: user tree
    if (root == NULL)
    {
        AVLNode *temp = new AVLNode(key);
        return;
>>>>>>> c03f47a9eaa56d570f16b7f56c4d1741de7c7496
    }
    if (key < root->value)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        cout << "Duplicate!!" << endl;
    }

<<<<<<< HEAD
    root->height=(getHeight(root->left)>getHeight(root->right)?getHeight(root->left):getHeight(root->right))+1;
    root->size=1+getSize(root->left)+getSize(root->right);
    if (getBalanceFactor(root)>1 && key<root->left->value){
        root=rightRotate(root);
=======
    root->height = (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right)) + 1;
    if (getBalanceFactor(root) > 1 && key < root->left->value)
    {
        root = rightRotate(root);
>>>>>>> c03f47a9eaa56d570f16b7f56c4d1741de7c7496
    }
    if (getBalanceFactor(root) < -1 && key > root->right->value)
    {
        root = leftRotate(root);
    }
    if (getBalanceFactor(root) > 1 && key > root->left->value)
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    if (getBalanceFactor(root) < -1 && key < root->right->value)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *a = y->left;
    AVLNode *b = a->right;
    a->right = y;
    y->left = b;
<<<<<<< HEAD
    a->height = (getHeight(a->left)>getHeight(a->right)?getHeight(a->left):getHeight(a->right))+1;
    y->height = (getHeight(y->left)>getHeight(y->right)?getHeight(y->left):getHeight(y->right))+1;
    y->size=1+getSize(y->left)+getSize(y->right);
    a->size=1+getSize(a->left)+getSize(a->right);
=======
    a->height = (getHeight(a->left) > getHeight(a->right) ? getHeight(a->left) : getHeight(a->right)) + 1;
    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;
>>>>>>> c03f47a9eaa56d570f16b7f56c4d1741de7c7496
    return a;
}

AVLNode *leftRotate(AVLNode *x)
{
    if (x == NULL)
    {
        return NULL;
    }
    AVLNode *a = x->right;
<<<<<<< HEAD
    AVLNode *b= a->left;
    a->left = x;
    x->right = b;
    x->height = (getHeight(x->left)>getHeight(x->right)?getHeight(x->left):getHeight(x->right))+1;
    a->height = (getHeight(a->left)>getHeight(a->right)?getHeight(a->left):getHeight(a->right))+1;
    x->size=1+getSize(x->left)+getSize(x->right);
    a->size=1+getSize(a->left)+getSize(a->right);
    return a;
}

AVLNode* rebalance(AVLNode* root){
	if (root==NULL){
		return NULL;
	}
	root->left=rebalance(root->left);
	root->right=rebalance(root->right);
	root->height=(getHeight(root->left)>getHeight(root->right)?getHeight(root->left):getHeight(root->right))+1;
    root->size=1+getSize(root->left)+getSize(root->right);
	
	while(getBalanceFactor(root)>1||getBalanceFactor(root)<-1){
		if(getBalanceFactor(root)>1){
			if(getBalanceFactor(root->left)<0){
			root->left=leftRotate(root->left);
			}
        root=rightRotate(root);
    	}
    if (getBalanceFactor(root)<-1){
    	if(getBalanceFactor(root->right)>0){
        root->right=rightRotate(root->right);
    	}
        root=leftRotate(root);
    	}
	}
=======
    AVLNode *b = x->left;
    a->left = x;
    x->right = b;
    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;
    a->height = (getHeight(a->left) > getHeight(a->right) ? getHeight(a->left) : getHeight(a->right)) + 1;
    return a;
}

AVLNode *rebalance(AVLNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = rebalance(root->left);
    root->right = rebalance(root->right);
    root->height = (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right)) + 1;

    while (getBalanceFactor(root) > 1 || getBalanceFactor(root) < -1)
    {
        if (getBalanceFactor(root) > 1)
        {
            if (getBalanceFactor(root->left) < 0)
            {
                root->left = leftRotate(root->left);
            }
            root = rightRotate(root);
        }
        if (getBalanceFactor(root) < -1)
        {
            if (getBalanceFactor(root->right) > 0)
            {
                root->right = rightRotate(root->right);
            }
            root = leftRotate(root);
        }
    }
>>>>>>> c03f47a9eaa56d570f16b7f56c4d1741de7c7496

    return root;
}

<<<<<<< HEAD
int kthAVL(AVLNode* root, int k){ // changed: added k as a parameter
    AVLNode* temp=root;
    while (temp!=NULL){
        if (k<=getSize(temp->left)){
            temp=temp->left;
        }
        else if (k==getSize(temp->left)+1){
            return temp->value;
        }
        else{
            k-=getSize(temp->left)-1;
            temp=temp->right;
        }
    }
    return -1; //the kth node just doesn't exist
}

int rankAVL(AVLNode* root, int key){
    int count=0;
    AVLNode* temp=root;
    while (temp!=NULL){
        if (temp->value <= key){
            count+=1+getSize(temp->left); // size fix: this node + everything in its left subtree
            temp=temp->right;
        } 
        else {
            temp=temp->left;
=======
int kthAVL(AVLNode *root)
{
}

int rankAVL(AVLNode *root, int key)
{
    int count = 0;
    AVLNode *temp = root;
    while (temp != NULL)
    {
        if (temp->value <= key)
        {
            int left;
            if (temp->left != NULL)
            {
                left = temp->left->size;
            }
            count += 1 + left;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
>>>>>>> c03f47a9eaa56d570f16b7f56c4d1741de7c7496
        }
    }
    return count;
}

int countInRange(AVLNode *root, int lo, int hi)
{
    return (rankAVL(root, hi) - rankAVL(root, lo - 1));
}

bool isBalanced(AVLNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int balanced = getBalanceFactor(root);
    if (balanced != -1 && balanced != 1 && balanced != 0)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}
