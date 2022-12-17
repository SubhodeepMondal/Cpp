#include<iostream>
using namespace std;
class stack
{
	int top,*a,n;
	public:
		void input()
		{
			cout<<"Enter the size of the stack: ";
			top=-1;
			cin>>n;
			a=new int(n-1);
		}
		void push()
		{
			int num;
			if(top==n-1)
				throw(top);
			else
			{
				top++;
				cout<<"Enter a number to push: ";
				cin>>num;
				a[top]= num;
				cout<<"You have pushed: "<<a[top];
			}
		}
		void pop()
		{
			if(top==-1)
				throw(top);
			else
			{
				cout<<"You have popped: "<<a[top];
				top--;
			}
		}
		void display()
		{
			if(top==-1)
				throw(top);
			else
			{
				for(int i=top;i>=0;i--)
				cout<<"\n"<<a[i];
			}
		}	
};
int main()
{
	stack a;
	int num,i=0;
	a.input();
	while(i<4)
	{
		cout<<"\nEnter a choice:\n1.push\n2.pop\n3.display.\n4. exit:";
		cin>>i;
		switch(i)
		{
			case 1:
				try
				{
					a.push();
				}
				catch(int i)
				{
					cout<<"\n!You have push too many numbers!";
				}
				break;
			case 2:
				try
				{
					a.pop();
				}
				catch(int i)
				{
					cout<<"\n!The stack is empty!";
				}
				break;
			case 3:
				try
				{
					a.display();
				}
				catch(int i)
				{
					cout<<"\n!The stack is empty!";
				}
				break;
		}
	}
	return 0;
}
