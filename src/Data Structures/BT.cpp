#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
	static int id;
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int v){
		left=right=parent=NULL;
		value=v;
		id=id+1;
	}
};
int TreeNode::id=0;

class BTQueue{
	public:
	TreeNode** root;
	int front;
	int rear;
	BTQueue(){
		root=new TreeNode*[1000];
		front=-1;
		rear=-1;
	}
	~BTQueue(){
		delete[] root;
	}
	bool isEmpty() const{
		return front== -1;
	}
	bool isFull() const{
		return rear== 999;
	}
	void enqueue(TreeNode* n){
		if (isFull()){
			cout << "Queue is full." << endl;
			return;
		}
		if (isEmpty())
			front= 0;
		rear++;
		root[rear] = n;
	}
	void dequeue(){
		if (isEmpty()){
			cout << "Queue is empty." << endl;
			return;
		}
		if (front == rear){
			front= -1;
			rear= -1;
		}
		else{
			front++;
		}
	}
	TreeNode* front(){
		return root[front];
	}
};

//Binary Tree
void insert(TreeNode* p, int value){
		if (p == nullptr) {
			cout << "Parent is null!" << endl;
			p=new TreeNode(value);
			return;
		}

		if(value < p->value) {
			if (p->left == nullptr){
				p->left = new TreeNode(value);
				p->left->parent=p;
			}
			else{
				insert(p->left, value);
			}
		}
		else {
			if (p->right==nullptr){
				p->right=new TreeNode(value);
				p->right->parent=p;
			}
			else{
				insert(p->right, value);
			}
		}
	}

	void preOrder(TreeNode* root){
		if (root== NULL) {
			return;
		}
		cout<<root->id<<" ";
		cout << root->value<<endl;
		preOrder(root->left);
		preOrder(root->right);
	}

	void postOrder(TreeNode* root) {
		if (root== NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->id<<" ";
		cout << root->value<<endl;
	}

	void inOrder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		inOrder(root->left);
		cout<<root->id<<" ";
		cout << root->value<<endl;
		inOrder(root->right);
	}

	void levelOrder(TreeNode* root){
		if (root == nullptr)
			return;

		BTQueue q;
		q.enqueue(root);

		while (!q.isEmpty()) {
			TreeNode* node = q.front();
			q.dequeue();
			cout << node->value << " ";

			if (node->left != nullptr)
				q.enqueue(node->left);
			if (node->right != nullptr)
				q.enqueue(node->right);
		}
	}

	int searchIn(int inorder[], int value, int left, int right){
		for(int i=left;i<=right;i++){
			if(inorder[i]==value){
				return i;
			}
		}
		return -1;
	}

	TreeNode* buildpre(int inorder[], int preorder[], int &preIndex, int left, int right){
		if(left>right){
			return nullptr;
		}
		int rootVal=preorder[preIndex];
		preIndex++;
		TreeNode* node=new TreeNode(rootVal);
		int index=searchIn(inorder, rootVal, left, right);
		node->left=buildpre(inorder, preorder, preIndex, left, index-1);
		if(node->left!=nullptr){
			node->left->parent=node;
		}
		node->right=buildpre(inorder, preorder, preIndex, index+1, right);
		if(node->right!=nullptr){
			node->right->parent=node;
		}
		return node;
	}

	TreeNode* buildPreIn(int inorder[], int preorder[], int size){
		int preIndex=0;
		return buildpre(inorder, preorder, preIndex, 0, size-1);
	}

	TreeNode* buildpo(int inorder[], int postorder[], int &postIndex, int left, int right){
		if(left>right){
			return nullptr;
		}
		int rootVal=postorder[postIndex];
		postIndex--;
		TreeNode* node=new TreeNode(rootVal);
		if(left==right){
			return node;
		}
		int index=searchIn(inorder, rootVal, left, right);
		node->right=buildpo(inorder, postorder, postIndex, index+1, right);
		if(node->right!=nullptr){
			node->right->parent=node;
		}
		node->left=buildpo(inorder, postorder, postIndex, left, index-1);
		if(node->left!=nullptr){
			node->left->parent=node;
		}
		return node;
	}

	TreeNode* buildPostIn(int inorder[], int postorder[], int size){
		int postIndex=size-1;
		return buildpo(inorder, postorder, postIndex, 0, size-1);
	}

	int height(TreeNode* root){
		if(root==NULL){
			return 0;
		}
		int h1=1+ (height(root->left));
		int h2=1+ (height(root->right));
		if(h1>h2){
			return h1;
		}
		return h2;
	}

	int diameter(TreeNode* root){
		if(root->left==NULL&&root->right==NULL){
			return 1;
		}
		if (height(root->left)>height(root->right)){
			return height(root->left);
		}
		return height(root->right);
	}

	TreeNode* lca(TreeNode* root, TreeNode* n1, TreeNode* n2){
		if (root==NULL){
			return nullptr;
		}
		if (root==n1||root==n2){
			return root;
		}
		TreeNode* left=lca(root->left, n1, n2);
		TreeNode* right=lca(root->right, n1, n2);
		if(left!=NULL&&right!=NULL){
			return root;
		}
		if(left!=NULL&&right==NULL){
			return left;
		}
		if(left==NULL&&right!=NULL){
			return right;
		}
		return nullptr;
	}

	void pathTo(TreeNode* root, TreeNode* n){
		int pathl=0;
		if(root==NULL){
			cout<<"Node does not exist"<<endl;
			return;
		}
		if(root==n){
			cout<<"Path length: "<<pathl<<endl;
			return;
		}
		TreeNode* temp=n;
		while(temp->parent!=NULL){
			temp=temp->parent;
			pathl++;
			cout<<temp->id<<" ";
		}
		if(temp!=root){
			cout<<"Node does not exist"<<endl;
		}
		cout<<"Path length: "<<pathl<<endl;
	}

	void mirror(TreeNode* n){
		if(n==NULL){
			return;
		}
		TreeNode* temp=n->left;
		n->left=n->right;
		n->right=temp;
		mirror(n->left);
		mirror(n->right);
	}

	bool isSameTree(TreeNode* r1, TreeNode* r2){
		if (r1==NULL&&r2==NULL){
			return true;
		}
		if(r1==NULL&&r2!=NULL||r1!=NULL&&r2==NULL){
			return false;
		}
		if(r1->value!=r2->value){
			return false;
		}
		if (isSameTree(r1->left, r2->left)&&isSameTree(r1->right, r2->right)){
			return true;
		}
		return false;
	}

	bool isSymmetric(TreeNode* n){
		if(n==NULL){
			return true;
		}
		mirror(n->left);
		bool check=isSameTree(n->left,n->right);
		mirror(n->left);
		return check;
}

void display(TreeNode* r){
	if(r==NULL){
		return;
	}
	cout<<r->value<<endl;
	display(r->left);	
	display(r->right);	
}