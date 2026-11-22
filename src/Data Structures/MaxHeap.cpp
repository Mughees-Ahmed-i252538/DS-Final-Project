#include <iostream>
#include <string>
using namespace std;

struct MaxHeap
{
	int cap;
	int top;
	int* array;
	int filled;

	MaxHeap(){
		
	}

	MaxHeap(int c){
		cap=c;
		top=-1;
		array=new int[c];
		filled=0;
	}
	~MaxHeap()
	{
    delete[] array;
	}

	void buildMaxHeap(int arr[], int s){
		if (s>cap){
			s=cap;
		}
    for (int i=0; i<s; i++)
    {
        array[i] = arr[i];
    }
    top = s-1;
    filled = s;
    for (int i = s/2-1;i>= 0; i--)
    {
        Heapify_down(i);
    }
	}

	void heapSort()
	{
		 int n=top+1;
    	for (int i=n/2-1;i>=0;i--)
    	{
        Heapify_down(i);
    }
    while (top>0)
    {
        int temp = array[0];
        array[0] = array[top];
        array[top] = temp;
        top--;
		filled--;
        Heapify_down(0);
    }
    top = n-1;
    filled=n;
	}

	void insert(int priority)
	{
		if (top>=cap-1)
		{
			cout << "Heap Full" << endl;
			cout << "No of elements: " << top + 1 << endl;
			cout << "Capacity: " << cap << endl;
			return;
		}

		array[++top] = priority;
		Heapify_up(top);
		filled++;
	}

	int extractMax()
	{
		if (top == -1)
		{
			cout << "Empty" << endl;
			return 0;
		}

		int Value_To_Return = array[0];

		int temp = array[0];
		array[0] = array[top];
		array[top] = temp;
		top--;
		Heapify_down(0);
		filled--;
		return Value_To_Return;
	}

	int getHighestPriority()
	{
		if (top == -1)
		{
			cout << "Empty" << endl;
			return 0;
		}
		return array[0];
	}

	void displayHeap()
	{
		cout << "Heap: ";
		for (int i = 0; i <= top; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void Heapify_up(int cur_loc)
	{
		while (1)
		{
			if (cur_loc == 0)
			{
				return;
			}
			int parent_loc = (cur_loc - 1) / 2;
			if (array[cur_loc] <= array[parent_loc])
			{
				return;
			}

			int temp;

			if (array[cur_loc] > array[parent_loc])
			{
				temp = array[cur_loc];
				array[cur_loc] = array[parent_loc];
				array[parent_loc] = temp;

				cur_loc = parent_loc;
			}
		}
	}

	void Heapify_down(int cur_loc)
	{
		if (top == -1)
		{
			cout << "Got empty" << endl;
			return;
		}

		while (1)
		{
			int No_of_children = 0;
			int p_left_loc = cur_loc * 2 + 1;
			int p_right_loc = cur_loc * 2 + 2;

			if (p_left_loc <= top)
			{
				No_of_children++;
			}
			if (p_right_loc <= top)
			{
				No_of_children++;
			}
			if (No_of_children == 0)
			{
				return;
			}
			int temp = 0;

			if (No_of_children == 1)
			{
				if (array[p_left_loc] > array[cur_loc])
				{
					temp = array[p_left_loc];
					array[p_left_loc] = array[cur_loc];
					array[cur_loc] = temp;
				}

				return;
			}
			int parent_val = array[cur_loc];
			int left_val = array[p_left_loc];
			int right_val = array[p_right_loc];
			if (No_of_children == 2)
			{
				if (parent_val >= left_val && parent_val >= right_val)
				{
					return;
				}
				if (left_val >= right_val)
				{
					temp = array[cur_loc];
					array[cur_loc] = array[p_left_loc];
					array[p_left_loc] = temp;
					cur_loc = p_left_loc;
				}
				else
				{
					temp = array[cur_loc];
					array[cur_loc] = array[p_right_loc];
					array[p_right_loc] = temp;
					cur_loc = p_right_loc;
				}
			}
		}
	}
};
