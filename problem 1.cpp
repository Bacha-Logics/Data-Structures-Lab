#include<iostream>
using namespace std;
void myfun(int arr[],int size)
{
	int index;           // taking integer local variable
	cout<<"At Which Index You Want To Insert Element (From 0 to "<<size-1<<")"<<endl;
	cin>>index;              //    taking index number from user 
	for(int i=0;i<size;i++)        // using for loop 
	{
		if(index <= size-1 && index >= 0)            //  using if condition for entering element in the array at specific postion
		{
			cout<<"Enter Element "<<endl;
			cin>>*(arr + index);
		}
		break;    // using break statement to out from loop 
	}
	if(index <= size-1)  // using nested if condition to cout the element at specific  index
	    if(index>=0)
     	{
        	cout<<"Element At Index No : "<<"arr["<<index<<"] is  ";
	
	        for(int j=0;j<size;j++)
        	{
	   	        cout<<*(arr + index)<<endl;
		        break;	         // using break statement  to out from loop
        	}
		
        }
	if(index > size-1 || index < 0)            //  using if condition 
     	cout<<"ARRAY IS OUT OF THE BOUND  "<<endl;
}

int main()
{
	int size;
	cout<<"Enter size of array "<<endl;  
	cin>>size;    // taking size from user
	int * arr;
	arr = new int[size];   // making dynamic array
	myfun(arr,size);    // calling function
	delete[] arr;     // deleting dynamic array 
	return 0;
}