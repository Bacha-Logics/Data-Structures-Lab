#include<iostream>
using namespace std;
int main()
{
	int Size ,Max, Min ,Num ;           // taking integer variables
	cout<<"Enter Size Of Array :"<<endl;
	cin>>Size;                            // taking array size from user
	int arr[Size];
	cout<<"Enter "<<Size<<" Integer Elements :"<<endl;
	for(int i=0;i<Size;i++)      // making of dynamic array
	{
		cin>>Num;              // num is use to store elements in the array
		arr[i]=Num;
	}
	Max = arr[0];
	for(int i=0;i<Size;i++)   // using for loop to find maximum element
	{
		if(Max<arr[i])
		{
			Max = arr[i];
		}
	}
	Min = arr[0];
	for(int i=0;i<Size;i++)     // using for loop to find minimum element
	{
		if(Min>arr[i])
		{
			Min = arr[i];
		}
	}
	
	cout<<"lARGEST NUMBER IS :: "<<Max<<endl;
	cout<<"SMALLEST NUMBER IS :: "<<Min<<endl;
	
	return 0;
}
