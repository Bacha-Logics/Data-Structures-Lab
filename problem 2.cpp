#include<iostream>
using namespace std;
int myfun(int arr[],int size)
{	
	int max, min;
	cout<<"Enter "<< size << " Elements in Array :"<<endl;
	for(int i=0;i<size;i++)   // the work of this loop is to store elements in array
	{
		cin>> arr[i];
	}
	max = *(arr);
	for(int i=0;i<size;i++)     // this loop is simply find maximum element in array
	{
		if(max< *(arr + i))
		{
			max = *(arr + i);
		}
	}
	min = *(arr);
	for(int i=0;i<size;i++)     // this loop is simoly find minimum element in array
	{
		if(min>*(arr + i))
		{
			min = *(arr + i);
		}
	}
	
    cout<<"Largest Element is : "<<max<<endl;
	cout<<"Smallest Element is : "<<min<<endl;
}

int main()
{
	int size;
	cout<<"Enter Size Of Array :"<<endl;                
	cin>>size;                   // declaring the size of array 
	int * arr;
	arr = new int[size];
	myfun(arr,size);   
	delete[] arr;       // passing the address of array to function and size
	return 0;
}
