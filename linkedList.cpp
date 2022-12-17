#include<iostream>

using namespace std;

class linkedList
{
private:
	/* data */
	class node 
	{
		public:
			int key;
			node *prev; 
			node *next;
	};

	node* head;
public:
	linkedList(/* args */);

	void insert(int );

	void print();

	void del(int );
};



linkedList::linkedList(/* args */)
{
	head = NULL;
}


void linkedList::insert(int data)
{
	node *newNode;
	newNode = new node[1];
	newNode->key = data;
	if( head == NULL )
	{
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else
	{
		node *ptr = head;
		while( ptr->next != NULL )
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
		newNode->prev = ptr;
		newNode->next = NULL;	
	}
}



void linkedList::print()
{
	node * ptr = head;
	while(ptr != NULL)
	{
		cout << ptr->key << "->";
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}



void linkedList::del(int data)
{
	node *ptr = head;
	node *prevPtr = head;
	if(ptr->key == data)
	{
		head = ptr->next;
	}
	else
	{
		ptr = ptr->next;
		while(ptr!= NULL )
		{
			if(ptr->key == data)
			{
				prevPtr->next = ptr->next;
				break ;
			}
			prevPtr = prevPtr->next;
			ptr = ptr->next;
		}
	}
}

int main()
{
	int i,n, data;
	i = 1;
	linkedList lList;
	while(i!=0)
	{
		cout << "0. to exit" << endl << "1. to insert" <<endl << "2. to delete" << endl <<"3. to print the list:" << endl;
		cin >> i;
		switch(i)
		{
			case 1:
				{
					cout << "Enter the data to be inserted! :" << endl;
					cin >> data;
					lList.insert(data);
					break;
				}
			case 2:
				{
					cout << "Enter the data of the node to be deleted:" << endl;
					cin >> data;
					lList.del(data);
					break;
				}
			case 3:
				{
					lList.print();
				}
		}
	}
}
