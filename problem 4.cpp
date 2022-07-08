#include<iostream>
using namespace std;
int main()
{
    int arr1[3][3],arr2[3][3],arr3[3][3]; // declare 3*3 array
	int * p,*q,*s;                      // these are integer pointers 
	cout<<"Enter Elements for First Matrix "<<endl;
	for(int i=0;i<3;i++)     // this for loop is to store elements in first array
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter Elements for Second Matrix "<<endl;
	for(int i=0;i<3;i++)        //        this for loop is to store elements in second array
	{
    	for(int j=0;j<3;j++)
	    {
			cin>>arr2[i][j];
		}
	}
	
		cout<<"First Matrix "<<endl;
	for(int i=0;i<3;i++)      // this nested for loop makes first matrix using pointers
	{
		for(int j=0;j<3;j++)
		{
		    q=&arr1[i][j];
		    cout<<*q;
            cout<<endl;
            q++;
		}
	}
	cout<<"Second Matrix "<<endl;
	for(int i=0;i<3;i++)      //   this nested for loop makes second matrix using pointers
	{
    	for(int j=0;j<3;j++)
	    {
	    	p = &arr2[i][j];
		   cout<<*p;
            cout<<endl;
            p++;
		}
	}
	cout<<"Sum Of Two Matrix "<<endl;
	for(int i=0;i<3;i++)                   //  this nested for loop add two matrix and store in third matrix
	{
    	for(int j=0;j<3;j++)
	    {
	      arr3[i][j] = arr1[i][j]+arr2[i][j];
	       cout<<arr3[i][j];
	       cout<<endl;
		}
	}
	cout<<"Multiplication Of Two Matrix "<<endl;
	for(int i=0;i<3;i++)                //  this nested for loop multiply two matrix and store in third matrix
	{
    	for(int j=0;j<3;j++)
	    {
	    	 arr3[i][j] = arr1[i][j]*arr2[i][j];
	       cout<<arr3[i][j];
	    
            cout<<endl;
		}
	}
	
return 0;		
	
}
