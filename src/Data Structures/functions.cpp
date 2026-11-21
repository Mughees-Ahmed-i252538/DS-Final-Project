#include<iostream>
#include<string>
#include "BT.cpp"
#include "BST.cpp"
#include "AVL.cpp"
using namespace std;

TreeNode* makeBT(string s){
	char chars[200];
	for(int i=0;i<s.length() && i<200;i++){
		chars[i]=s[i];
	}

	int nums[200];
	int count=0;
	int i=0;
	while(i<s.length() && count<200){
        if (chars[i]=='#'){
            nums[count]=-1;
            continue;
        }
		if(chars[i]>='0' && chars[i]<='9'){
			int n=0;
			while(i<s.length() && chars[i]>='0' && chars[i]<='9'){
				n=n*10+(chars[i]-'0');
				i++;
			}
			nums[count]=n;
			count++;
		}
		else{
			i++;
		}
	}

	TreeNode* root=NULL;
	for(int j=0;j<count;j++){
		if(root==NULL){
			root=new TreeNode(nums[j]);
		}
		else{
			insert(root,nums[j]);
		}
	}
	return root;
}

BSTNode* makeBST(string s){
	char chars[200];
	for(int i=0;i<s.length();i++){
		chars[i]=s[i];
	}

	int nums[200];
	int count=0;
	int cur=0;
	bool reading=false;
	for(int i=0;i<s.length();i++){
        if (chars[i]=='#'){
            nums[count]=-1;
            continue;
        }
		if(chars[i]>='0' && chars[i]<='9'){
			cur=cur*10+(chars[i]-'0');
			reading=true;
		}
		else if(reading){
			nums[count]=cur;
			count++;
			cur=0;
			reading=false;
		}
	}

	if(reading){
		nums[count]=cur;
		count++;
	}

	BSTNode* root=NULL;
	for(int i=0;i<count;i++){
		root=insertNode(root,nums[i]);
	}
	return root;
}