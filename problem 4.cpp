#include<iostream>
using namespace std;
struct node
{
	node *next;
	node *pre;
	int data;
};

class dll
{
	private:
		node *head;
		node *head1;
		node *head2;
	public:
		dll();
		void insert(int info);
		void insertat(int key,int info);
		void frontBackSplit(node* p, node** front, node** back);
		int findLength(node* head);
		node* myhead();
		node** head11();
		node** head21();
		void display();
};

dll::dll()
{
	head  = NULL;
	head1 =NULL;
	head2 =NULL;
}

void dll::insert(int info)
{
	if(head  == NULL)
	{
		head = new node;
		head->next =NULL;
		head->pre =NULL;
		head->data  = info;
		
	}
	else
	{
		node *p;
		p =head;
		while(p!=NULL)
		{
			if(p->next ==NULL)
			{
				node*temp  = new node;
				temp->data =info;
				temp->next =NULL;
				temp->pre =p;
				p->next =temp;
				return ;
			}
			p =p->next;
		}
	}
}
node** dll::head11()
{
	return &head1;
}
node ** dll::head21()
{
	return &head2;
}

void dll::insertat(int key, int info)
{
	if(head ==NULL)
	{
		cout<<"empty"<<endl;
	}
	else if(head->next ==NULL&&head->data ==key)
	{
		node*temp  =new node;
		temp->next =NULL;
		temp->pre  = head;
		temp->data =info;
		head->next =temp;
	}
	else
	{
		node *p;
		p =head;
		while(p!=NULL)
		{
			if(p ==head&&p->data ==key)
			{
				node *temp =new node;
				temp->next = head->next;
				temp->pre =head;
				temp->data =info;
				head->next->pre =temp;
				head->next =temp;
				p =p->next;
				
			}
			else if(p->data ==key&&p->next ==NULL)
			{
				node *temp =new node;
				temp->next =p->next;
				temp->pre =p;
				temp->data =info;
				p->next =temp;
				p =p->next;
			}
			else if(p->data ==key)
			{
				node *temp =new node;
				temp->next =p->next;
				temp->pre =p;
				temp->data =info;
				p->next->pre =temp;
				p->next =temp;
				p =p->next;
			}
			p=p->next;
		}
	}
}

node * dll::myhead()
{
	return head;
}

int dll::findLength(node* head)
{
    int count = 0;
    node* curr = head;
    while (curr != NULL)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
 
void dll::frontBackSplit(node* p, node** front, node** back)
{
    int len = findLength(p);
    if (len < 2)
    {
        *front = p;
        *back = NULL;
        return;
    }
 
    node* curr = p;
 
    int Count = (len - 1) / 2;       
    for (int i = 0; i < Count; i++) {
        curr = curr->next;
    }
    *front = p;
    *back = curr->next;
    curr->next = NULL;
}
 
void dll::display()
{
	node *p;
	p = head;
	int count = 1;
	while(p != NULL)
	{
		cout<<count<<" : "<<p->data<<endl;
		p = p->next;
		count += 1;
	}
}

int main()
{
	dll l;
	l.insert(44);
	l.insert(55);
	l.insert(75);
	l.insert(65);
	l.display();
	l.findLength(l.myhead());
	l.frontBackSplit(l.myhead(),l.head11(),l.head21());
	cout<<"sublist"<<endl;
	l.display();
	return 0;
}
