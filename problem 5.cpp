#include<iostream>
using namespace std;
int myfun(int arr1[],int size1,int arr2[],int size2)
{
	int temp;
	cout<<"Enter Elements in First Array"<<endl;  // this for loop store elements in first array
	for(int i=0;i<size1;i++)
	{
		cin>>*(arr1+i);
	}
	cout<<"Enter Elements in Second Array"<<endl;   // this for loop store elements in second array
	for(int i=0;i<size2;i++)
	{
		cin>>*(arr2+i);
	}
		cout<<"Elements Of First Array After Swapping "<<endl; 
	for(int i=0;i<size1;i++)  //  this for loop swaps arrays and cout array of first elements
	{
		temp = *(arr1+i);      // storing first array elements in temp variable
		*(arr1+i)=*(arr2+i);
		*(arr2+i)= temp;
		cout<<*(arr1+i)<<endl;
		
	}
		cout<<"Elements of Second Array After Swapping "<<endl;
	for(int i=0;i<size1;i++)    // this for loop cout array of second elements after swapping
	{
		cout<<*(arr2+i)<<endl;	
	}
}

int main()
{
	int size1,size2;
	cout<<"Enter Size For First Array"<<endl;
	cin>>size1;
	cout<<"Enter size For Second Array"<<endl;
	cin>>size2;
	int *arr1, *arr2;
	 arr1 = new int[size1];
	 arr2 = new int[size2];
	 myfun(arr1,size1,arr2,size2);   // calling function
	 delete[] arr1;
	 delete[] arr2;
	return 0;
}
