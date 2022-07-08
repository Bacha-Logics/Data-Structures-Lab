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
		void Insert(char info);
		void InsertAtPos(char info,char val);
		void reverse(Node**);
        bool compareLists(Node*,Node*); // comparing two linklist elements  return true or false
        bool isPalindrome(Node* head);  // finding ispalindrome
		Node *myhead();   // returning pointer head
		Node **myreference();  // returning reference of head 
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

void linklist::Insert(char info)
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


void linklist::InsertAtPos(char info, char val)
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

Node ** linklist::myreference()
{
	return &head;
}

bool linklist::isPalindrome(Node* head)
{
    Node *temp = head, *temp1 = head;
    Node *temp2, *temp3 = head;
     
    Node* mid = NULL;
     
    bool res = true;
 
    if (head != NULL && head->next != NULL)
    {
         
        while (temp1 != NULL && temp1->next != NULL)
        {
            temp1 = temp1->next->next;
 
            temp3 = temp;
            temp = temp->next;
        }
 
        if (temp1 != NULL)
        {
            mid = temp;
            temp = temp->next;
        }
 
        temp2 = temp;
        
        temp3->next = NULL;
         
        reverse(&temp2);
         
        res = compareLists(head, temp2);
 
        reverse(&temp2); 
 
        if (mid != NULL)
        {
            temp3->next = mid;
            mid->next = temp2;
        }
        else
            temp3->next = temp2;
    }
    return res;
}
 
void linklist::reverse(Node** head_ref)
{
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
     
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
bool linklist::compareLists(Node* head1,Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
 
    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return false;
    }
 
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    return false;
}

int main()
{
	linklist l;
	linklist s;
	l.Insert(1);
	l.Insert(2);
	l.Insert(1);
	s.Insert(1);
	s.Insert(2);
	s.Insert(1);
	l.compareLists(l.myhead(),s.myhead());
	l.reverse(l.myreference());
	l.isPalindrome(l.myhead());
	l.print();

	return 0;
}





