#include<iostream>
using namespace std;
int myfun(int arr1[],int size1,int arr2[],int size2)
{
	int counter = 0;
	cout<<"Enter Elements In First Array "<<endl;
	for(int i=0;i<size1;i++)    // this loop is storing elements in first array
	{
		cin>>*(arr1+i);
		
	}
	cout<<"Enter Elements In Second Array "<<endl;
	for(int i=0;i<size2;i++)    //   this loop is storing elements in second array
	{
		cin>>*(arr2+i);
	}
	for(int i=0;i<size1;i++)     // this for loop is calculaing number of same elements and storing in a counter
	{
		for(int j=0;j<size2;j++)
		{
			if(*(arr1+i) == *(arr2+j))
			{
			  	counter++;
			}
	    }	
			
				
	}
	int * arr3;

	 arr3= new int[counter];
	cout<<"Number Of Same Elements are :"<<endl;	
	for(int i=0;i<size1;i++)      //   this for loop is storing same elements in third array 
	{
		for(int j=0;j<size2;j++)
		{
			if(*(arr1+i) == *(arr2+j))
			{
				*(arr3 + counter) = *(arr1+i);
				cout<<*(arr3 + counter)<<endl;
				break;                          // using break statement
			}
			
		}
	}
 delete[] arr3;
	
}				

int main()
{
	int size1,size2;
	cout<<"Enter size for First Array :"<<endl;    // declaring array size
	cin>>size1;
	cout<<"Enter size for Second Array :"<<endl;
	cin>>size2;
	int *arr1, *arr2;
	arr1 = new int[size1];
	arr2 = new int[size2];
	
	myfun(arr1,size1,arr2,size2);   // calling function
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
}
