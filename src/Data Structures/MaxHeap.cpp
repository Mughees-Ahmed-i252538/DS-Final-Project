#include<iostream>
#include <string>
#define CAPACITY 200
using namespace std;
struct MaxHeap
{
	int cap= CAPACITY;
	int top=-1;
	int array[CAPACITY];
	int filled=0;
	
	void buildMaxHeap(int arr[], int s){
		for (int i=0; i<s; i++){
		array[++top]=arr[i];
		Heapify_down(i);
		}
		filled=s;
	}
	
	void heapSort(int arr[]){
		int size=cap;
		for(int i=0;i<cap;i++)
		{
			int temp= arr[0];
			arr[0]=arr[cap-1];
			arr[cap-1]=temp;
			cap=cap-1;
			Heapify_down(0);
			cap=size;
		}
		cap= size;
	}
	
	void insert(int priority)
	{
		if(top>=cap-1)
		{		
			cout<<"Heap Full"<<endl;
			cout<<"No of elements: "<<top+1<<endl;
			cout<<"Capacity: "<<cap<<endl;
			return;
		}
		
		array[++top]=priority;
		Heapify_up(top);
		filled++;
	}
	
	int extractMax()
	{
		if(top==-1)
		{
			cout<<"Empty"<<endl;
			return 0;
		}
		
		int Value_To_Return= array[0];
		
		int temp= array[0];
		array[0]=  array[top];
		array[top]=temp;
		top--;
		Heapify_down(0);
		filled--;
		return Value_To_Return;
	}
	
	int getHighestPriority()
	{
		if(top==-1)
		{
			cout<<"Empty"<<endl;
			return 0;
		}
		return array[0];
	}
	
	void displayHeap()
	{
		cout<<"Heap: ";
		for (int i=0;i<=top;i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}	

	void Heapify_up(int cur_loc)
	{
		while(1)
		{
			if(cur_loc==0)
			{
				return;
			}
			int parent_loc =  (cur_loc-1) /2 ;
			if(array[cur_loc]<=array[parent_loc])
			{
				return;
			} 
			
			int temp;
			
			if(array[cur_loc]>array[parent_loc])
			{
				temp = array[cur_loc];
				array[cur_loc]=array[parent_loc];
				array[parent_loc]=temp;
				
				cur_loc=parent_loc;
			}
		}
	}
	
	void Heapify_down(int cur_loc)
	{
		if(top==-1)
		{
			cout<<"Got empty"<<endl;
			return;
		}
		
		while(1)
		{
			int No_of_children=0;
			int p_left_loc = cur_loc*2 +1;
			int p_right_loc = cur_loc*2 +2;
			
			if(p_left_loc<=top)
			{
				No_of_children++;
			}
			if(p_right_loc<=top)
			{
				No_of_children++;
			}
			if(No_of_children==0)
			{
				return;
			}
			int temp=0;
			
			if(No_of_children==1)
			{
				if(array[p_left_loc]>array[cur_loc])
				{
					temp=array[p_left_loc];
					array[p_left_loc]=array[cur_loc];
					array[cur_loc]=temp;
				}
				
				return;
			}
			int parent_val= array[cur_loc];
			int left_val= array[p_left_loc];
			int right_val= array[p_right_loc];
			if(No_of_children==2)	
			{
				if(parent_val>=left_val&&parent_val>=right_val)
				{
					return;
				}
				if(left_val>=right_val)	{
					temp= array[cur_loc];
					array[cur_loc]=array[p_left_loc];
					array[p_left_loc]=temp;
					cur_loc=p_left_loc;
				}
				else
				{
					temp= array[cur_loc];
					array[cur_loc]=array[p_right_loc];
					array[p_right_loc]=temp;
					cur_loc=p_right_loc;
				}
			}
			
		}
	}
};
