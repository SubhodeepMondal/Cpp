#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class linked_list
{
	node *head,*tail;
	public:
		linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		void add_node(int n)
		{
			node *temp=new node;
			temp->data=n;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *n=head;
			while(n!=NULL)
			{
				cout<<n->data<<" ";
				n=n->next;
			}
			cout<<"\n";
		}
		void delete_node()
		{
			node *temp=head->next,*prev=head;
			int n;
			cout<<"Enter the number to delete:";
			cin>>n;
			if(n==1)
			{
				head=head->next;
			}
			else
			{
				n--;
				while(n != 1)
				{
					prev=prev->next;
					temp=temp->next;
					n--;
				}
				prev->next=temp->next;
			}
			cout<<"After deletion the list is:\n";
			display();
		}
		void insert_after()
		{
			node *temp=head->next,*prev=head;
			int i;
			cout<<"Enter the position you want to insert in:";
			cin>>i;
			node *n=new node;
			cout<<"Enter the data:";
			cin>>n->data;
			if(i==1)
			{
				n->next=head;
				head=n;
			}
			else
			{
				i--;
				while(i != 1)
				{
					prev=prev->next;
					temp=temp->next;
					i--;
				}
				n->next=temp;
				prev->next=n;
			}
			cout<<"After insertion the list is:\n";
			display();
		}
};
int main()
{
	linked_list t;
	int i=0,n;
	while(i<5)
	{
		cout<<"\nChoose one:\n1.Add_node.\n2.Display.\n3.Delete.\n4. Insert after.\n5.Exit.";
		cin>>i;
		switch(i)
		{
			case 1:
				cout<<"Enter a number:";
				cin>>n;
				t.add_node(n);
				break;
			case 2:
				t.display();
				break;
			case 3:
				t.delete_node();
				break;
			case 4:
				t.insert_after();
				break;
		}
	}
	return 0;
}
