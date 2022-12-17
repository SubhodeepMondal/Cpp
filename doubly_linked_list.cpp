#include<iostream>
using namespace std;
struct node
{
	int data;
	node *pre,*next;
};
class doubly
{
	node *head=NULL,*tail=NULL;
	public :
		void create_node()
		{
			node *temp=new node;
			cout<<"Enter a data:";
			cin>>temp->data;
			temp->next=NULL;
			if(head == NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				tail->next=temp;
				temp->pre=tail;
				tail=temp;
			}
		}
		void display()
		{
			node *temp;
			for(temp=head;temp!=NULL;temp=temp->next)
				cout<<temp->data<<" ";
		}
		void delete_item()
		{
			node *temp=head,*prev=head;
			int n;
			cout<<"\nEnter a data to be deleted:";
			cin>>n;
			if(temp->data==n)
				head=head->next;
			else
			{
				while(temp)
				{
						temp=temp->next;
					if(temp->data==n)
					{
						prev->next=temp->next;
						break;
					}
					prev=prev->next;
				}
			}
			cout<<"\nAfter deletion the linked list is:\n";
			display();
		}
};
int main()
{
	doubly d;
	int i;
	while(i<4)
	{
		cout<<"\nEnter a choice\n1.Insert node\n2.Display\n3.Delete Item:";
		cin>>i;
		switch(i)
		{
			case 1:
				d.create_node();
				break;
			case 2:
				d.display();
				break;
			case 3:
				d.delete_item();
				break;
		}
	}
	return 0;
}
