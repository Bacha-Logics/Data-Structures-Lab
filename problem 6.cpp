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
		Node *myhead();
		void removeDuplicates(Node* head);// this function removing duplicates 
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

Node * linklist::myhead()
{
	return head;
}


void linklist:: removeDuplicates(Node* head)
{
	Node* current = head;
	Node* next_next;
	if (current == NULL)
	return;

	while (current->next != NULL)
	{
	if (current->data == current->next->data)
	{
		next_next = current->next->next;
		removeDuplicates(current->next);
		current->next = next_next;
	}
	else
	{
		current = current->next;
	}
	}
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
    cout<<endl;
    cout<<"After Removing of Element "<<endl;
    l.removeDuplicates(l.myhead());
    l.print();
	return 0;
}