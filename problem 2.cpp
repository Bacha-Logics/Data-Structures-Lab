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
		Node* Merge(Node *a,Node *b);  // merging two linklists
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


Node* linklist::Merge(Node* a, Node* b)
{
	Node* result = NULL;
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);
	
	if (a->data <= b->data)
	{
		result = a;
		result->next = Merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = Merge(a, b->next);
	}
	return(result);
}








int main()
{

	linklist l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.Insert(4);
	l.InsertAtPos(4,5);
	l.InsertAtPos(5,6);
	l.print();
	cout<<"Second linklist"<<endl;
	linklist s;
	s.Insert(7);
	s.Insert(8);
	s.Insert(9);
	s.InsertAtPos(9,10);
	s.print();
	cout<<endl;
    cout<<"Merge sort is :"<<endl;
	l.Merge(l.myhead(),s.myhead());

    l.print();
	return 0;
}





