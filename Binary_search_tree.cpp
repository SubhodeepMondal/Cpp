#include<iostream>
using namespace std;

class binarySearchTree
{
	typedef struct node
	{
		int data;
		struct node *left,*right;
	}node;

	node *head;

	public:
		binarySearchTree()
		{
			head = NULL;
		}

		void insert(int item)
		{
			node *temp, *ptr = head;
			if(head == NULL)
			{
				temp=new node;
				temp->data=item;
				temp->left=temp->right=NULL;
				head = temp;
			}
			else
			{
				while(true)
				{
					if(ptr->data > item)
					{
						if(ptr->left == NULL )
						{
							temp = new node;
							temp->data=item;
							temp->left=temp->right=NULL;
							ptr->left = temp;
							break ;
						}
							
						else
							ptr = ptr->left;
					}
					else
					{
						if(ptr->right == NULL )
						{
							temp = new node;
							temp->data=item;
							temp->left=temp->right=NULL;
							ptr->right = temp;
							break ;
						}
						else
							ptr = ptr->right;
					}
				}
			}
		}
		void inorder()
		{
			node *ptr = head;
			if(ptr)
			{
				inorder(ptr->left);
				cout<<ptr->data<<" ";
				inorder(ptr->right);
			}
		}
		void postorder()
		{
			node *ptr = head;
			if(ptr)
			{
				postorder(ptr->left);
				postorder(ptr->right);
				cout<<ptr->data<<" ";
			}
		}
		void preorder()
		{
			node *ptr = head;
			if(ptr)
			{
				cout<<ptr->data<<" ";
				preorder(ptr->left);
				preorder(ptr->right);
			}
		}
};
int main()
{
	int i,item;
	binarySearchTree a;
	while(i<5)
	{
		cout<<"\nEnter a choice\n1. Insert data:\n2.Inorder\n3.postorder\n4.preorder\n5.Exit:";
		cin>>i;
		switch(i)
		{
			case 1:
				cout<<"Enter a data to be inserted:";
				cin>>item;
				a.create(item);
				break;
			case 2:
				a.inorder();
				break;
			case 3:
				a.postorder(head);
				break;
			case 4:
				a.preorder(head);
		}
	}
	return 0;
}
