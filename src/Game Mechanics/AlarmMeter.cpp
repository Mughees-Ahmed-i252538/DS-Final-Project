// bismillah hirahman nirahim

// This file has the alarm meter logic
#include<iostream>
#include<string>
#include<ctime>
#include "BT.cpp"
#include "BST.cpp"
#include "AVL.cpp"
#include "MaxHeap.cpp"
#include"functions.cpp"
#include"functions1.cpp"
using namespace std;

//steps
int countNodes(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	return 1+countNodes(root->left)+countNodes(root->right);
}

int L11(TreeNode*& t, int& kind, int*& nums){
	string s;
	int n=6+rand()%10;
	kind=1+rand()%4;
	s=randomizer(s, n);
	t=makeBT(s, n, nums);
	return countNodes(t);
}

TreeNode* nodeAt(TreeNode* root, int target, int& counter){
    if(root==NULL){
        return NULL;
    }
    TreeNode* found=nodeAt(root->left, target, counter);
    if(found!=NULL){
        return found;
    }
    if(counter==target){
        return root;
    }
    counter++;
    return nodeAt(root->right, target, counter);
}

int depthOf(TreeNode* n){
    int d=0;
    while(n->parent!=NULL){
        n=n->parent;
        d++;
    }
    return d;
}

int countNonLeaf(TreeNode* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return 0;
    }
    return 1+countNonLeaf(root->left)+countNonLeaf(root->right);
}

int diameterNodes(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int through=height(root->left)+height(root->right)+1;
    int l=diameterNodes(root->left);
    int r=diameterNodes(root->right);
    if(l>through){
        through=l;
    }
    if(r>through){
        through=r;
    }
    return through;
}

int countNodes(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	return 1+countNodes(root->left)+countNodes(root->right);
}

int L11(TreeNode*& t, int& kind, int*& nums){
	string s;
    int r=6+rand()%(15-6+1);
	int n=r;
	int type=1+rand()%4; //pre,post..
	s=randomizer(s, n);
	t=makeBT(s, n, nums);
	return countNodes(t);
}

int L12(TreeNode*& t, int& kind, int*& nums){
    string s;
    int n=6+rand()%10;
    kind=1+rand()%2;   // 1: pre+in, 2: post+in
    s=randomizer(s, n);
    t=makeBT(s, n, nums);
    return countNodes(t);
}

int L13(TreeNode*& t, int*& nums){
    string s;
    int n=6+rand()%10;
    s=randomizer(s, n);
    t=makeBT(s, n, nums);
    return countNodes(t)+1;
}

int L14(TreeNode*& t, TreeNode*& a, TreeNode*& b, int*& nums){
    string s;
    int n=6+rand()%10;
    s=randomizer(s, n);
    t=makeBT(s, n, nums);
    int total=countNodes(t);
    int i=rand()%total;
    int j=rand()%total;
    while(j==i){
        j=rand()%total;
    }
    int c1=0;
    int c2=0;
    a=nodeAt(t, i, c1);
    b=nodeAt(t, j, c2);
    TreeNode* meet=lca(t, a, b);
    int pathNodes=depthOf(a)+depthOf(b)-2*depthOf(meet)+1;
    return 2+1+pathNodes;
}

int L15(TreeNode*& t, int*& nums){
    string s;
    int n=6+rand()%10;
    s=randomizer(s, n);
    t=makeBT(s, n, nums);
    return countNonLeaf(t);
}

BSTNode* randomBST(int n, int keys[]){
    BSTNode* root=NULL;
    int count=0;
    while(count<n){
        int v=1+rand()%99;
        if(!searchNode(root, v)){
            root=insertNode(root, v);
            keys[count]=v;
            count++;
        }
    }
    return root;
}

int optimalSearch(BSTNode* root, int key){
    int steps=0;
    BSTNode* temp=root;
    while(temp!=NULL){
        steps++;
        if(key==temp->tpayload){
            return steps;
        }
        if(key<temp->tpayload){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return steps;
}

int countRange(BSTNode* root, int lo, int hi){
    if(root==NULL){
        return 0;
    }
    int steps=1;
    if(root->tpayload>lo){
        steps=steps+countRange(root->left, lo, hi);
    }
    if(root->tpayload<hi){
        steps=steps+countRange(root->right, lo, hi);
    }
    return steps;
}

int L21(BSTNode*& root, int& key){
    int keys[20];
    int n=6+rand()%10;
    root=randomBST(n, keys);
    key=keys[rand()%n];
    return optimalSearch(root, key);
}

int L22(BSTNode*& root, int& key){
    int keys[20];
    int n=6+rand()%10;
    root=randomBST(n, keys);
    key=1+rand()%99;
    while(searchNode(root, key)){
        key=1+rand()%99;
    }
    return optimalSearch(root, key);
}

int L23(BSTNode*& root, int& key){
    int keys[20];
    int n=6+rand()%10;
    root=randomBST(n, keys);
    key=keys[rand()%n];
    return optimalSearch(root, key)+1;
}

int L24(BSTNode*& root, int& lo, int& hi){
    int keys[20];
    int n=8+rand()%8;
    root=randomBST(n, keys);
    lo=keys[rand()%n];
    hi=keys[rand()%n];
    if(lo>hi){
        int temp=lo;
        lo=hi;
        hi=temp;
    }
    return countRange(root, lo, hi);
}

int L25(BSTNode*& root, int& key){
    int n=10+rand()%6;
    root=NULL;
    for(int i=1;i<=n;i++){
        root=insertNode(root, i);
    }
    key=n;
    return optimalSearch(root, key);
}

AVLNode* plainInsert(AVLNode* root, int key){
    if(root==NULL){
        return new AVLNode(key);
    }
    if(key<root->value){
        root->left=plainInsert(root->left, key);
        root->left->parent=root;
    }
    else if(key>root->value){
        root->right=plainInsert(root->right, key);
        root->right->parent=root;
    }
    else{
        return root;
    }
    root->height=(getHeight(root->left)>getHeight(root->right) ? getHeight(root->left) : getHeight(root->right))+1;
    root->size=1+getSize(root->left)+getSize(root->right);
    return root;
}

int countUnbalanced(AVLNode* root){
    if(root==NULL){
        return 0;
    }
    int mine=0;
    if(getBalanceFactor(root)>1 || getBalanceFactor(root)<-1){
        mine=1;
    }
    return mine+countUnbalanced(root->left)+countUnbalanced(root->right);
}

void distinctKeys(int count, int keys[]){
    int made=0;
    while(made<count){
        int v=1+rand()%99;
        bool used=false;
        for(int i=0;i<made;i++){
            if(keys[i]==v){
                used=true;
            }
        }
        if(!used){
            keys[made]=v;
            made++;
        }
    }
}

int countRotations(int keys[], int size){
    int before=rotationCount;
    AVLNode* t=NULL;
    for(int i=0;i<size;i++){
        t=insert(t, keys[i]);
        t->parent=NULL;
    }
    return rotationCount-before;
}

void rotationKeys(int kind, int keys[]){
    int lo=1+rand()%30;
    int mid=lo+1+rand()%30;
    int hi=mid+1+rand()%30;
    if(kind==1){        // LL
        keys[0]=hi; keys[1]=mid; keys[2]=lo;
    }
    else if(kind==2){   // RR
        keys[0]=lo; keys[1]=mid; keys[2]=hi;
    }
    else if(kind==3){   // LR
        keys[0]=hi; keys[1]=lo; keys[2]=mid;
    }
    else{               // RL
        keys[0]=lo; keys[1]=hi; keys[2]=mid;
    }
}

int optimalKth(AVLNode* root, int k){
    int rank=getSize(root)-k+1;
    int steps=0;
    while(root!=NULL){
        steps++;
        int leftSize=getSize(root->left);
        if(rank==leftSize+1){
            return steps;
        }
        if(rank<=leftSize){
            root=root->left;
        }
        else{
            rank=rank-leftSize-1;
            root=root->right;
        }
    }
    return steps;
}

int L31(AVLNode*& root){
    int keys[20];
    int bad=0;
    while(bad==0){
        int n=7+rand()%6;
        distinctKeys(n, keys);
        root=NULL;
        for(int i=0;i<n;i++){
            root=plainInsert(root, keys[i]);
        }
        bad=countUnbalanced(root);
    }
    return bad;
}

int L32(int keys[], int& kind){
    kind=1+rand()%2;
    rotationKeys(kind, keys);
    return countRotations(keys, 3);
}

int L33(int keys[], int& kind){
    kind=3+rand()%2;
    rotationKeys(kind, keys);
    return countRotations(keys, 3);
}

int L34(int base[], int ins[], int rots[]){
    int all[9];
    distinctKeys(9, all);
    for(int i=0;i<5;i++){
        base[i]=all[i];
    }
    for(int i=0;i<4;i++){
        ins[i]=all[5+i];
    }
    AVLNode* t=NULL;
    for(int i=0;i<5;i++){
        t=insert(t, base[i]);
        t->parent=NULL;
    }
    for(int i=0;i<4;i++){
        int before=rotationCount;
        t=insert(t, ins[i]);
        t->parent=NULL;
        rots[i]=rotationCount-before;
    }
    return 4;
}

int L35(AVLNode*& root, int& k){
    int keys[20];
    int n=7+rand()%8;
    distinctKeys(n, keys);
    root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root, keys[i]);
        root->parent=NULL;
    }
    k=1+rand()%n;
    return optimalKth(root, k);
}

int siftCount(int a[], int i, int size){
    int swaps=0;
    while(1){
        int left=i*2+1;
        int right=i*2+2;
        int biggest=i;
        if(left<size && a[left]>a[biggest]){
            biggest=left;
        }
        if(right<size && a[right]>a[biggest]){
            biggest=right;
        }
        if(biggest==i){
            break;
        }
        int temp=a[i];
        a[i]=a[biggest];
        a[biggest]=temp;
        swaps++;
        i=biggest;
    }
    return swaps;
}

int countBuildSwaps(int arr[], int size){
    int copy[30];
    for(int i=0;i<size;i++){
        copy[i]=arr[i];
    }
    int swaps=0;
    for(int i=size/2-1;i>=0;i--){
        swaps=swaps+siftCount(copy, i, size);
    }
    return swaps;
}

int countExtractSteps(int arr[], int size){
    int copy[30];
    for(int i=0;i<size;i++){
        copy[i]=arr[i];
    }
    int steps=0;
    for(int end=size-1;end>=1;end--){
        int temp=copy[0];
        copy[0]=copy[end];
        copy[end]=temp;
        steps++;
        steps=steps+siftCount(copy, 0, end);
    }
    return steps;
}

int L41(int arr[], int& n){
    n=7+rand()%8;
    for(int i=0;i<n;i++){
        arr[i]=1+rand()%99;
    }
    return countBuildSwaps(arr, n);
}

int L42(int arr[], int& n){
    n=7+rand()%8;
    for(int i=0;i<n;i++){
        arr[i]=1+rand()%99;
    }
    for(int i=n/2-1;i>=0;i--){
        siftCount(arr, i, n);
    }
    int fixes=0;
    while(fixes==0){
        arr[rand()%n]=1+rand()%99;
        fixes=countBuildSwaps(arr, n);
    }
    return fixes;
}

int L43(int arr[], int& n){
    n=7+rand()%8;
    for(int i=0;i<n;i++){
        arr[i]=1+rand()%99;
    }
    for(int i=n/2-1;i>=0;i--){
        siftCount(arr, i, n);
    }
    return countExtractSteps(arr, n);
}

int L44(int arr[], int& n){
    n=10+rand()%6;
    for(int i=0;i<n;i++){
        arr[i]=1+rand()%99;
    }
    return countBuildSwaps(arr, n)+countExtractSteps(arr, n);
}

int L45(int arr[], int& n){
    n=15+rand()%6;
    for(int i=0;i<n;i++){
        arr[i]=1+rand()%99;
    }
    return countBuildSwaps(arr, n)+countExtractSteps(arr, n);
}

class AlarmMeter{
	public:
	int optimal;
	int capacity;
	int steps;
	int penaltyAlarm;
	int penaltyCount;
	int penaltyPoints;
	int bonus;
	bool hintUsed;

	AlarmMeter(int opt){
		optimal=opt;
		capacity=(3*opt+1)/2+2;
		steps=0;
		penaltyAlarm=0;
		penaltyCount=0;
		penaltyPoints=0;
		bonus=0;
		hintUsed=false;
	}

	void addStep(){
		steps++;
	}

	void wrongClick(){
		penaltyAlarm=penaltyAlarm+1;
		penaltyCount++;
	}

	void wrongRotation(){
		penaltyAlarm=penaltyAlarm+2;
		penaltyPoints=penaltyPoints+50;
		penaltyCount++;
	}

	void invalidSwap(){
		penaltyAlarm=penaltyAlarm+1;
		penaltyCount++;
	}

	void useHint(){
		hintUsed=true;
	}

	void addBonus(int b){
		bonus=bonus+b;
	}

	void shrink(){
		if(capacity>1){
			capacity--;
		}
	}

	int alarm(){
		return steps+penaltyAlarm;
	}

	int remaining(){
		int r=capacity-alarm();
		if(r<0){
			r=0;
		}
		return r;
	}

	bool isFull(){
		return alarm()>=capacity;
	}

	int stars(){
		if(isFull()){
			return 0;
		}
		int result=1;
		if(steps<=optimal && penaltyCount==0){
			result=3;
		}
		else if(steps*4<=optimal*5 && penaltyCount<=1){
			result=2;
		}
		if(hintUsed && result>2){
			result=2;
		}
		return result;
	}

	int score(){
		int s=1000-10*alarm()-penaltyPoints+bonus;
		if(s<0){
			s=0;
		}
		return s;
	}

	void show(){
		cout<<"Alarm: "<<alarm()<<"/"<<capacity<<endl;
	}
};