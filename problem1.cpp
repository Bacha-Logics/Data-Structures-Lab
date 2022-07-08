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
		void concatenates(Node *a,Node *b);   // this function link two linklists
		Node *myhead();   // my head function only return head pointer
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

void linklist::concatenates(Node *a ,Node *b)
 {
        if( a != NULL && b!= NULL )
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenates(a->next,b);  // using recurrion here 
        }
        else
        {
            cout << "One Of Them Is NULL";
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
	cout<<"Second linklist"<<endl;
	linklist s;
	s.Insert(102);
	s.Insert(103);
	s.Insert(104);
	s.InsertAtPos(104,105);
	s.print();
	cout<<endl;
	s.concatenates(l.myhead(),s.myhead());
	cout<<"Concatenates list is "<<endl;
	l.print();
	cout<<endl;
	return 0;
}