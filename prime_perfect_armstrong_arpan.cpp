#include<iostream>
#include<cmath>
using namespace std;
class misc
{
	int m;
	public:
		void getdata();
		void isprime();
		void isperfect();
		void isarmstrong();
};//end of class misc
void misc::getdata()
{
	cout<<"Enter the number:";
	cin>>m;
}//end of getdata()
void misc::isprime()
{
	bool flag=true;
	for(int i=2;i<m/2;i++)
	{
		if(m%i==0)//searching for factors till mid of m
		{	
			flag=false;
			break;
		}//end of if
}//end of for loop
if(flag==true)//if prime
	cout<<"The number"<<m<<"is Prime\n";
else
	cout<<"The number"<<m<<"is Not Prime\n";
}//end of isprime()
void misc::isarmstrong()
{
	int copy=m,d=0;
	while(copy>0)//counting no. of digits
	{
		d++;
		copy=copy/10;
	}//end of while
	copy=m;
	int sum=0;
	while(copy>0)
	{
		sum=sum+pow(copy%10,d);
		copy=copy/10;
	}//end of while
	if(sum==m)//if armstrong
		cout<<"The number"<<m<<"is Armstrong\n.";
	else//if not armstrong
		cout<<"The number"<<m<<"is Not Armstrong\n.";
}//end of isarmstrong()
void misc::isperfect()
{
	int sum=1;
	for(int i=2;i<=m/2;i++)//searching for all factors
	{
		if(m%i==0)//if factor then add to sum
			sum=sum+i;
	}
	if(sum==m)//if no. is perfect
		cout<<"The number"<<m<<"is Perfect\n.";
	else//if no. is not perfect
		cout<<"The number"<<m<<"is Not Perfect\n.";
}//end of isperfect()
int main()
{	
	misc obj;//creation of obj
	obj.getdata();//taking input
	obj.isperfect();//checking if perfect
	obj.isarmstrong();//checking if armstrong
	obj.isprime();//checking if prime
}//end of main()

