#include <iostream>
#include <string>
#include"BT.cpp"
using namespace std;

struct BSTNode: public TreeNode{
	int key;
	int tpayload;
	int height;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	BSTNode(){
		key=tpayload=0;
		height=1;
	}
	BSTNode(int v): TreeNode(v){
		key=v;
		tpayload=v;
		height=1;
		left=nullptr;
		left=static_cast <BSTNode*>(TreeNode::left);
		right=static_cast <BSTNode*>(TreeNode::right);
		parent=static_cast <BSTNode*>(TreeNode::parent);
	}
};

BSTNode* insertNode(BSTNode* root, int val){
	BSTNode* temp = new BSTNode(val);
	if (root == NULL){
		root = temp;
		return root;
	}
	else{

		if (val < root->tpayload){
			root->left = insertNode(root->left, val);
		}

		if (val > root->tpayload){
			root->right = insertNode(root->right, val);
		}
		if (val == root->tpayload){
			cout << "Duplicate!!" << endl;
			return root;
		}
	}
	return root;
}

bool searchNode(BSTNode* root, int val){
	if (root == NULL){
		return false;
	}
	if (val == root->tpayload){
		return true;
	}
	if (val < root->tpayload){
		return searchNode(root->left, val);
	}
	if (val > root->tpayload){
		return searchNode(root->right, val);
	}
	return false;
}

BSTNode* deleteNode(BSTNode* root, int value) {
	if (root == NULL){
		return NULL;

	}
	else if(value < root->tpayload){
		root->left = deleteNode(root->left, value);
	}
	else if(value > root->tpayload){
		root->right = deleteNode(root->right, value);
	}
	else{
		if (root->left == NULL && root->right == NULL){
			BSTNode* temp = root;
			delete temp;
			temp = NULL;
			return NULL;
		}
		if (root->left == NULL && root->right != NULL){
			int d = root->tpayload;
			root->tpayload = root->right->tpayload;
			root->right->tpayload = d;
			return deleteNode(root, value);
		}
		if (root->left != NULL && root->right == NULL){
			int d = root->tpayload;
			root->tpayload = root->left->tpayload;
			root->left->tpayload = d;
			deleteNode(root, value);
		}
		if (root->left != NULL && root->right != NULL){
			BSTNode* temp = root->right;
			while(temp->left != NULL){

				temp = temp->left;
			}
			root->tpayload = temp->tpayload;
			root->right = deleteNode(root->right, temp->tpayload);
			return root;
		}
	}
	return root;
}

BSTNode* findMin(BSTNode* root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

BSTNode* findMax(BSTNode* root){
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

BSTNode* successor(BSTNode* p){
	if(p->right!=NULL){
		return findMin(p->right);
	}
	BSTNode* temp=p->parent;
	while(temp!=NULL&&p==temp->right){
		p=temp;
		temp=temp->parent;
	}
	return temp;
}

BSTNode* predecessor(BSTNode* p){
	if(p->left!= NULL){
		return findMax(p->left);
	}
	BSTNode* temp = p->parent;
	while(temp != NULL && p == temp->left){
		p =temp;
		temp=temp->parent;
	}
	return temp;
}

void rangeQuery(BSTNode* root, int lo, int hi){
	if(root==NULL){
		return;
	}
	
	if(root->tpayload==lo && root->tpayload==hi){
	cout<<"Range is just"<<root->key<<" "<<root->tpayload<<endl;	//the range is only this node
	}
	
	if(root->tpayload>lo)
	{rangeQuery(root->left, lo, hi);
	}
	else
	{//here you will need to add the event for skipping the entire left subtree
	//because they are all less than or equal to lower end of range and so are not in the range
	}
	
	if(root->tpayload<hi)
	{rangeQuery(root->right, lo, hi);
	}
	else
	{//here you will need to add the event for skipping the entire right subtree
	//because they are all greater than or equal to higher end of range and so are not in the range
	}
}

int kthSmallest(BSTNode* root, int k) {
    int count=0;

    BSTNode* curr=root;
    while (curr!=nullptr) {
        if (curr->left==nullptr) {
            count++;
            if (count==k) {
            	return curr->tpayload;
			}
            curr=curr->right;
        } else {
            BSTNode* prev=curr->left;
            while (prev->right!=nullptr && prev->right!=curr) {
                prev=prev->right;
            }
            if (prev->right==nullptr) {
                prev->right=curr;
                curr=curr->left;
            } else {
                count++;
                if (count==k) {
                	return curr->tpayload;
				}
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return -1;
}

BSTNode* lcaBST(BSTNode* root, BSTNode* a, BSTNode* b){
	BSTNode* temp=root;
	if (root==NULL){
		return nullptr;
	}
	do{
		if(a->tpayload<temp->tpayload&&b->tpayload<temp->tpayload){
			temp=temp->left;
			continue;
		}
		if(a->tpayload>temp->tpayload&&b->tpayload>temp->tpayload){
			temp=temp->right;
			continue;
		}
		return temp;
	}while(temp!=NULL);
	return NULL;
}