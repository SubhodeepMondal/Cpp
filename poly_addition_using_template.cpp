#include<iostream>
#include<conio.h>
using namespace std;
template<class any>
class poly
{
	any x,y,co;
	poly *link;
	int flag;
	public:
	poly *head1,*head2,*head3;
	poly create(poly **ptr)
	{
		poly **temp,*curr;
		char ch;
		do
		{
			temp =new poly;
			cout<<"\nEnter the co-efficient:";
			cin>>temp->co;
			cout<<"\nEnter power value of x and y:";
			cin>>temp->x;
			cin>>temp->y;
			temp->flag=0;
			if(*ptr==NULL)
			{
				*ptr=temp;
				curr=temp;
			}
			else
			{
				curr->link=temp;
				curr=temp;
			}
			cout<<"Do you want to add another node:";
			fflush(stdin);
			ch=getche();		
		}while(ch=='y');
	}
	void addpoly(poly *head1,poly *head2,poly *ptr3)
	{
		poly *ptr1=head1,*ptr2,*curr;
		int a,b;
		while(ptr1)
		{
			ptr3=new poly;
			a=ptr1->x;
			b=ptr1->y;
			ptr2=findpow(a,b);
				if(ptr2)
					ptr3->co=ptr1->co+ptr2->co;
				else
					ptr3->co=ptr1->co;
				ptr3->x=ptr1->x;
				ptr3->y=ptr1->x;
				ptr3->link=NULL;
				if(head3==NULL)
				{
					head3=ptr3;
					curr=ptr3;
				}
				else
				{
					curr->link=ptr3;
					curr=ptr3;
				}
		}
		ptr2=head2;
		while(ptr2)
		{
			if(ptr2->flag==0)
			{
				ptr3=new poly;
				ptr3->co=ptr2->co;
				ptr3->x=ptr2->x;
				ptr3->y=ptr2->y;
				ptr3->link==NULL;
				if(head3==NULL)
				{
					head3=ptr3;
					curr=ptr3;
				}
				else
				{
					curr->link=ptr3;
					curr=ptr3;
				}
			}
		}
	}
	poly *findpow(int a,int b)
	{
		poly *ptr1,*ptr2;
		ptr1=ptr2=head2;
		if(ptr1->x==a&&ptr1->y==b)
		{
			head2=head2->link;
			return(ptr1);
		}
		ptr1=ptr1->link;
		while(ptr1)
		{
			if(ptr1->x==a&&ptr1->y==b)
			{
				head2=head2->link;
				return(ptr1);
				ptr1=ptr1->link;
				ptr2=ptr2->link;
			}	
		}
		return(NULL);
	}
	void print(poly *ptr)
	{
		while(ptr)
		{
			cout<<ptr->co<<"x^"<<ptr->x<<"y^"<<ptr->y;
			ptr=ptr->link;
		}
	}
}
main()
{	int i;
	poly <int>a;
	poly <int>b;
	poly <int>c;	
	cout<<"which type of calculation you want(int=0 or float=1):";
	cin>>i;
	if (i=0)
	{
		poly <int>a;
		poly <int>b;
		poly <int>c;
		poly *head1=&a,*head2=&b,*head3=&c;
		a.create(*head1);
		a.print(*head1)
		cout<<"Enter proper value for another polynomial:";
		b.create(*head2);
		b.print(*head2)
		c=a.addpoly(*head1,*head2,*head3);
		c.print(*head3);
	}
}
