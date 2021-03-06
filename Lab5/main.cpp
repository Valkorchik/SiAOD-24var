#include <iostream>
using namespace std;
struct Node
{
	short data;
	Node* next;
};
Node* insert(short data, Node*& l);
void list_init(Node*& l);
void list_fill(Node*& l);
void list_print(Node*& l);
void list_split(Node*& l, short x, short y);
void delete_node(Node*& l);
void list_delete(Node*& l);
void list_clear(Node*& l);
void list_insert(Node*& l);
int main()
{
	Node* l_source;
	list_init(l_source);
	cout << "Enter a list node (0 - end): \n";
	list_fill(l_source);
	cout << "List:\n";
	list_print(l_source);
	short X,Y;
	cout<< "Enter X, Y parameters to mark list: \n";
	cin>>X>>Y;
	list_split(l_source,X,Y);
	cout<<"\nNew list: \n";
	list_print(l_source);
	list_clear(l_source);
	cout<<"Source list after clearing:\n";
	list_print(l_source);
	list_insert(l_source);
	cout<<"List after insert:\n";
	list_print(l_source);
	list_delete(l_source);

}
Node* insert(short data, Node*& l)
{
	return new Node{data,l};
}
void list_fill(Node*& l)
{
	short fill;
	while (true)
	{
		cin >> fill;
		if (fill == 0)
			return;
		l = insert(fill, l);
	}
}
void list_init(Node*& l)
{
	l= nullptr;
}
void list_print(Node*& l)
{
	Node* temp = l;
	while (l)
	{
		cout << l->data<<"\t";
		l = l->next;
	}
	cout << endl;
	l = temp;
}
void list_split(Node*& l, short x, short y)
{
	int counter_x=0, counter_y=0;
	Node* temp=l;
	while(l)
	{
		if(x==l->data) counter_x+=1;
		if(y==l->data) counter_y+=1;
		l=l->next;
	}
	l=temp;
	Node* tempo;
	if(counter_x>=1 && counter_y>=1)
	{
		while(l)
		{
			if(l->data==x)
			{
				cout<<"\nX-Y List: \n";
				while(l->next->data!=y)
				{
					cout<<l->next->data<<"\t";
					l=l->next;
				}
			}
			l=l->next;
		}
		l=temp;
	}
	else
		cout<<"NULL\n";
	while(l)
	{
		if(l->next->data==x)
		{
			tempo = l;
			while (l->data != y)
			{
				l = l->next;
			}
			tempo->next = l;
			l=temp;
			while(l)
			{
				if(l==tempo)
				{
					l->next=tempo->next;
					return;
				}
				l=l->next;
			}
		}
		l=l->next;
	}
}
void delete_node(Node*& l)
{
	Node* temp = l;
	l = l->next;
	delete temp;
}
void list_delete(Node*& l)
{
	while (l)
		delete_node(l);
}
void list_clear(Node*& l)
{
	short temp;
	cout<<"Enter value to delete: \n";
	cin>>temp;
	Node* zero=l;
	while(l->next)
	{
		if(l->next->data==temp)
		{
			delete_node(l->next);
		}
		else
			l=l->next;
	}
	l=zero;
}
void list_insert(Node*& l)
{
	cout<<"Enter value before which the insert should be:\n";
	short value;
	cin>>value;
	Node* zero=l;
	cout<<"Enter data to insert:\n";
	short data;
	cin>>data;
	while(l->next)
	{
		if(l->next->data==value)
		{
			l->next=insert(data,l->next);
			l=l->next->next;
		}
		else
			l=l->next;
	}
	l=zero;
}


