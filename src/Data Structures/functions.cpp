#include <iostream>
#include <string>
#include "BT.cpp"
#include "BST.cpp"
#include "AVL.cpp"
#define CAPACITY 200
using namespace std;

TreeNode *makeBT(string s) // I think a better idea on this one was to make a dmaed char array with lebgth = chars in string, for nums capacity = nodecapcity which could have been inputer
{
	char chars[CAPACITY];
	for (int i = 0; i < s.length() && i < CAPACITY; i++)
	{
		chars[i] = s[i];
	} // i think one issue may arrive that we dont put \0 at end of char array, but it dpends on logic (if you never print using cout or use while(char array[i]!='\0) for loop):: Rethoughts after seeing code,: nodt using for the 2 purposes on ok Mashallah, Alhamulilah
	int nums[CAPACITY];
	int count = 0;
	int i = 0;
	while (i < s.length() && count < CAPACITY)
	{
		if (chars[i] == '#')
		{
			nums[count] = -1;
			continue;
		}
		if (chars[i] >= '0' && chars[i] <= '9')
		{
			int n = 0;
			while (i < s.length() && chars[i] >= '0' && chars[i] <= '9')
			{
				n = n * 10 + (chars[i] - '0');
				i++;
			}
			nums[count] = n;
			count++;
		}
		else
		{
			i++;
		}
	}

	TreeNode *root = NULL;
	for (int j = 0; j < count; j++)
	{
		if (root == NULL)
		{
			root = new TreeNode(nums[j]);
		}
		else
		{
			insert(root, nums[j]); // issue on this, BT doesnt have rules on where to isnert
		} // The logic is instead something along these lines
	} // sees index 0: if not # makes it the root with its value, sees 0 * 2 +1, if that isnt # it inserts its value in left child of index 0 , it repeats for right child , then it calls this same described fucntionality for each of its children
	// Note while checking if its children are not # first it has to check it the children are within range

	return root;
}

BSTNode *makeBST(string s)
{
	char chars[CAPACITY];
	for (int i = 0; i < s.length(); i++)
	{
		chars[i] = s[i];
	}

	int nums[CAPACITY];
	int count = 0;
	int cur = 0;
	bool reading = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (chars[i] == '#')
		{
			nums[count] = -1;
			continue;
		}
		if (chars[i] >= '0' && chars[i] <= '9')
		{
			cur = cur * 10 + (chars[i] - '0');
			reading = true;
		}
		else if (reading)
		{
			nums[count] = cur;
			count++;
			cur = 0;
			reading = false;
		}
	}

	if (reading)
	{
		nums[count] = cur;
		count++;
	}

	BSTNode *root = NULL;
	for (int i = 0; i < count; i++)
	{
		root = insertNode(root, nums[i]);
	}
	return root;
}