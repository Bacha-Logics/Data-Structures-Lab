#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linklist
{
	protected:
		Node *head;
		Node *tail;
	public:
		linklist();
		~linklist();
		void Insert(int info);
		void InsertAtPos(int info,int val);
		void SwapNode(int x,int y);  // changing nodes positions 
		void print();
};


linklist::linklist()
{
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
{
	Node *pre;
	Node *link;
	link = head;
	while(link != NULL)
	{
		pre = link;
		link = link->next;
		delete pre;
	}
	delete link;
	delete head;
}

void linklist::Insert(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
}

void linklist::print()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<endl;
			temp = temp->next;
			i++;
		}
	}
}


void linklist::InsertAtPos(int info, int val)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
			tail = temp;
		}
		else
		{
			cout<<info<<" There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *link;
		link = head;	
		while(link != NULL)
		{
			if(link->next == tail->next && link->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
			else if(link->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = link->next;
				link->next = temp;
			}	
			link = link->next;
		}
	}
}


void linklist::SwapNode( int x, int y)
{	
   if (x == y)
   {
      return;
   }
    Node *x_prev = NULL; 
	Node *x_curr = head;
   while (x_curr && x_curr->data != x)
   {
       x_prev = x_curr;
       x_curr = x_curr->next;
   }
 
   Node *y_prev = NULL;
   Node *y_curr = head;
   while (y_curr && y_curr->data != y)
   {
       y_prev = y_curr;
       y_curr = y_curr->next;
   }

   if (x_curr == NULL || y_curr == NULL)
   {
       return;
   }
   if (x_prev != NULL)
   {
       x_prev->next = y_curr;
   }
   else
   { 
       head = y_curr;  
   }
   if (y_prev != NULL)
       y_prev->next = x_curr;
   else
   {  
       head = x_curr;
   }

   Node *temp = y_curr->next;
   y_curr->next = x_curr->next;
   x_curr->next  = temp;
   
   cout<<endl;
   cout<<"Values After Swapping Is :"<<endl;
}

int main()
{

	linklist l;
	l.Insert(30);
	l.Insert(55);
	l.Insert(88);
	l.Insert(22);
	l.Insert(22);
	l.Insert(99);
	l.InsertAtPos(88,100);
	l.InsertAtPos(99,101);
	l.print();
    l.SwapNode(30,101);
    l.print();
	return 0;
}