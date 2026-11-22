#include <iostream>
#include <string>
#include "BT.cpp"
#include "BST.cpp"
#include "AVL.cpp"
#include "MaxHeap.cpp"
using namespace std;

void putChildrem_BT(int *&array, int size, TreeNode *&Current_Node, int Current_index)
{
	if (Current_Node == nullptr)
	{
		cout << "error" << endl;
	}

	int left_child_index = Current_index * 2 + 1;
	int right_child_index = Current_index * 2 + 2;

	if (left_child_index > size - 1) // if not in range set == nullptr (greater than last index)
	{
		Current_Node->left = nullptr;
	}
	else
	{
		if (array[left_child_index] == -1)
		{
			Current_Node->left = nullptr;
		} // if was #; also put nullptr
		else
		{
			// Current_Node->left = new TreeNode(array[left_child_index]); // Done without using insert fucniton for now ALhamdulilah
			insert(Current_Node, array[left_child_index], true);
			putChildrem_BT(array, size, Current_Node->left, left_child_index);
		}
	}

	if (right_child_index > size - 1)
	{
		Current_Node->right = nullptr;
	}
	else
	{
		if (array[right_child_index] == -1)
		{
			Current_Node->right = nullptr;
		} // if was #; also put nullptr
		else
		{
			// Current_Node->right = new TreeNode(array[right_child_index]); // Done without using insert fucniton for now ALhamdulilah
			insert(Current_Node, array[right_child_index], false);
			putChildrem_BT(array, size, Current_Node->right, right_child_index);
		}
	}
}

TreeNode *makeBT(string s, int NodeCap, int *&nums) // I think a better idea on this one was to make a dmaed char array with lebgth = chars in string, for nums capacity = nodecapcity which could have been inputer
{
	string &chars = s;
	// for (int i = 0; i < s.length() && i < CAPACITY; i++)
	//{
	//	chars[i] = s[i];
	// } // i think one issue may arrive that we dont put \0 at end of char array, but it dpends on logic (if you never print using cout or use while(char array[i]!='\0) for loop):: Rethoughts after seeing code,: nodt using for the 2 purposes on ok Mashallah, Alhamulilah
	nums = new int[NodeCap];
	int count = 0;
	int i = 0;
	while (i < s.length() && count < NodeCap)
	{
		if (chars[i] == '#')
		{
			nums[count] = -1;
			count++;
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

	root = new TreeNode(nums[0]);

	// insert(root, nums[j]); // issue on this, BT doesnt have rules on where to isnert
	putChildrem_BT(nums, NodeCap, root, 0);

	// The logic is instead something along these lines
	// sees index 0: if not # makes it the root with its value, sees 0 * 2 +1, if that isnt # it inserts its value in left child of index 0 , it repeats for right child , then it calls this same described fucntionality for each of its children
	// Note while checking if its children are not # first it has to check it the children are within range

	// delete chars;

	return root;
}

void putChildrenBST(int nums[], int size, BSTNode *current, int index)
{
	int leftIndex = index * 2 + 1;
	int rightIndex = index * 2 + 2;

	if (leftIndex < size && nums[leftIndex] != -1)
	{
		current->left = new BSTNode(nums[leftIndex]);
		current->left->parent = current;
		putChildrenBST(nums, size, current->left, leftIndex);
	}
	if (rightIndex < size && nums[rightIndex] != -1)
	{
		current->right = new BSTNode(nums[rightIndex]);
		current->right->parent = current;
		putChildrenBST(nums, size, current->right, rightIndex);
	}
}

BSTNode *makeBST(string s, int CAPACITY, int *&nums)
{
	char *chars = new char[CAPACITY];
	for (int i = 0; i < s.length(); i++)
	{
		chars[i] = s[i];
	}

	nums = new int[CAPACITY];
	int count = 0;
	int cur = 0;
	bool reading = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (chars[i] == '#')
		{
			nums[count] = -1;
			count++;
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

	if (count == 0 || nums[0] == -1)
	{
		return NULL;
	}

	BSTNode *root = NULL;
	putChildrenBST(nums, count, root, 0);
	return root;
}

AVLNode *makeAVL(string s, int CAPACITY, int *&nums)
{
	char *chars = new char[CAPACITY];
	for (int i = 0; i < s.length(); i++)
	{
		chars[i] = s[i];
	}

	nums = new int[CAPACITY];
	int count = 0;
	int cur = 0;
	bool reading = false;
	for (int i = 0; i < s.length(); i++)
	{
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

	AVLNode *root = NULL;
	for (int i = 0; i < count; i++)
	{
		root = insert(root, nums[i]);
		root->parent = NULL;
	}
	return root;
}

MaxHeap *makeMH(string s, int CAPACITY, int *&nums)
{
	int len = s.length();
	if (len > CAPACITY)
	{
		len = CAPACITY;
	}
	char *chars = new char[CAPACITY];
	for (int i = 0; i < len; i++)
	{
		chars[i] = s[i];
	}

	nums = new int[CAPACITY];
	int count = 0;
	int cur = 0;
	bool reading = false;
	for (int i = 0; i < len; i++)
	{
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

	MaxHeap *h = new MaxHeap(CAPACITY);
	h->buildMaxHeap(nums, count);
	return h;
}