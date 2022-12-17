#include<iostream>
#include<math.h>
using namespace std;
class number
{
	int num;
	public:
		number(int x)  	/* constructor*/
		{
			num=x;
		}
		~number() 		/*destructor*/
		{
			cout<<"\nDestroying the object.\n";
		}
		void prime();
		void perfect();
		void armstrong();
}; 						/*end of class number*/
void getdata(int &n)
{
	cout<<"Enter the number:";
	cin>>n;
}						/*end of function getdata*/
void number::prime()
{
	int i,f=0,n;
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
		cout<<"\nThe number "<<num<<" is prime.";
	else
		cout<<"\nThe number "<<num<<" not is prime.";
}						/*end of function getdata*/
void number::perfect()
{
	int i,r,s=0;
	for(i=1;i<=num/2;i++)
	{
		if(num %i==0)
		{
			s+=i;
		}
	}
	if(s==num)
		cout<<"\nThe number "<<num<<" is perfect.";
	else
		cout<<"\nThe number "<<num<<" is not perfect.";
}						/*end of function perfect()*/
void number::armstrong()
{
	int a=num,r,n=0,s=0;
	while (a!=0)
	{
		r=a%10;
		n++;
		a=a/10;
	}
	a=num;
	while(a!=0)
	{
		r=a%10;
		s=s+pow(r,n);
		a=a/10;
	}
	if(s==num)
		cout<<"\nThe number "<<num<<" is an armstrong number.";
	else
		cout<<"\nThe number "<<num<<" is not an armstrong number.";
}						/*end of function armstrong()*/
int main()
{
	
	int n,i=0;
	
	while(i<4)
	{
		cout<<"\nEnter a choice:\n1. prime number\n2. perfect number\n3. Armstrong number.";
		cin>>i;
		switch(i)
		{
			case 1:
				{
					getdata(n);
					number a(n);
					{
						a.prime();
					}
					break;
				}
			case 2:
				{
					getdata(n);
					number a(n);
					{
						a.perfect();
					}
					break;
				}
			case 3:
				{
					getdata(n);
					number a(n);
					{
						a.armstrong();
					}
					break;
				}
		}
	}
	return 0;
}								/*end of function main()*/
