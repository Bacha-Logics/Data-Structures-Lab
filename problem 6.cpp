#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
};


class cll
{
	private:
		Node *head;
	public:
		cll();
		~cll();
		void InsertAtBegin(int info);
	    void delAtEnd(int key);
		void display();
};


cll::cll()
{
	head = NULL;
}

cll::~cll()
{
	Node *query = head->next;
	Node *pre = query;
	while(query->next != head)
	{
		pre = query;
		query = query->next;
		delete pre;
	}
	delete head, query;
}


void cll::InsertAtBegin(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
	}
	else
	{
		Node *query = head;
		if (query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			head->next = temp;
			head = temp;
		}
		else
		{
			while(query->next != head)
			{
				query = query->next;
			}
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			query->next = temp;
			head = temp;	
		}
	}
}


void cll::display()
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
		return;
	}
	Node *query = head;
	if (query->next == head)
	{
		cout<<query->data<<" ";
	}
	else
	{
		while(query->next != head)
		{
			cout<<query->data<<" ";
			query = query->next;
		}	
		cout<<query->data<<" "<<endl;
	}
}

void cll::delAtEnd(int key)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *query = head;
		delete query;
		head = NULL; 
	}
	else
	{
		Node *query = head;
		Node *pre = head;
		while(query->next != head)
		{
			if (query->data == key && query == head)
			{
				while(query->next != head)
				{
					query = query->next;
				}
				head = head->next;
				query->next = head;
				delete pre;
				return;
			}
			if (query->data == key)
			{
				pre->next = query->next;
				delete query;
				return;
			}
			pre = query;
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			pre->next = query->next;
			delete query;
			return;
		}
	}
}




int main()
{
	cll l;
	l.InsertAtBegin(1);
	l.InsertAtBegin(2);
	l.InsertAtBegin(3);
	l.InsertAtBegin(4);
	l.display();
	cout<<"delete is :"<<endl;
	l.delAtEnd(1);
	l.display();
	return 0;
}
