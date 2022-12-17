#include<iostream>
using namespace std;
struct node
{
	char *ch,name[15];
	bool avil;
};
class ticket
{
	node *a[13][6];
	public:
		void assign()
		{
			node *temp;
			int i;
			for(i=0;i<3;i++)
				for(int j=0;j<6;j++)
				{
					temp=new node;
					a[i][j]=temp;
					a[i][j]->ch="First Class";
					a[i][j]->avil=0;
				}
			for(;i<8;i++)
				for(int j=0;j<6;j++)
				{
					temp=new node;
					a[i][j]=temp;
					a[i][j]->ch="Business class";
					a[i][j]->avil=0;
				}
			for(;i<13;i++)
				for(int j=0;j<6;j++)
				{
					temp=new node;
					a[i][j]=temp;
					a[i][j]->ch="Economy Class";
					a[i][j]->avil=0;
				}
		}
		void ticket_details()
		{
			cout<<"* for avaliable.\n. for booked.";
			for(int i=0;i<13;i++)
			{
				cout<<"\n";
				for(int j=0;j<6;j++)
				{
					if(a[i][j]->avil==true)
						cout<<"*\t";
					else
						cout<<".\t";
				}
			}
		}
		void desired_seat()
		{
			int i,j;
			cout<<"Enter the row and collumn no. of desired sit:";
			cin>>i>>j;
			cout<<"Ticket details for seat["<<j<<"]["<<i<<"]:\n";
			i--;
			j--;
			cout<<"\nclass type:"<<a[i][j]->ch;
			cout<<"\nAvaliability:\t";
			if(a[i][j]->avil==false)
			{
				cout<<"avaliable.";
				cout<<"\nDo you want to book this ticket(1/0):";
				cin>>a[i][j]->avil;
				if(a[i][j]->avil==true)
				{
					cout<<"\nEnter your name:";
					cin>>a[i][j]->name;
					cout<<"Your sit is reserved for you:";
				}
			}	
			else
				cout<<"booked by."<<a[i][j]->name;
			
		}
};
int main()
{
	ticket t;
	t.assign();
	int i=0;
	while(i<3)
	{	
		cout<<"\nEnter a choice:\n1. for booking ticket.\n2. for ticket details.";
		cin>>i;
		switch(i)
		{
			case 1:
				t.desired_seat();
				break;
			case 2:
				t.ticket_details();
				break;
		}
	}
	return 0;
}
