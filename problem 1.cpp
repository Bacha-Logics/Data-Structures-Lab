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
	public:
		dll();
		void insert(int info);
		void insertat(int key,int info);
		void sortlink(int x,int y);
		void display();
};

dll::dll()
{
	head  = NULL;
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


void dll::sortlink(int x, int y)
{
    if (x == y)
        return;
 
    node *pre = NULL;
	node *currX = head;
    while (currX && currX->data != x) {
        pre = currX;
        currX = currX->next;
    }
    
    node *prev = NULL, *currY = head;
    while (currY && currY->data != y) {
        prev = currY;
        currY = currY->next;
    }
    
    if (currX == NULL || currY == NULL)
        return;
 
    if (pre != NULL)
        pre->next = currY;
    else 
        head = currY;
    if (prev != NULL)
        prev->next = currX;
    else 
        head = currX;
 
    node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
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
	l.insertat(55,65);
	l.insertat(65,75);
	l.display();
	cout<<"sorting linkes "<<endl;
	l.sortlink(44,55);
	l.display();
	
	return 0;
}
