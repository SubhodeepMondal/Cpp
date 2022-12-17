#include<iostream>
#include<string.h>
#include <iomanip>
using namespace std;
class binary
{
	char a1[20];
	public:
		void takval()
		{
			gets(a1);
			check();
		}
		void check()
		{
			for(int i=0;i<strlen(a1);i++)
				if(a1[i]!='0')
				{
					if(a1[i]!='1')
					{
						cout<<"\n!!Digit is not a binary number!!\nEnter again:";
						exit(0);
					}
				}		
		}
		binary operator -(binary s1)
		{
			
			binary s2;
			int flag=0;
			int l=strlen(a1);
			int j=strlen(s1.a1);
			for(int i=l-1;i>=0;i--)
			{
				j--;
				if(j<0)
					s1.a1[j]='0';
				cout<<"\ns1.a:"<<a1[i]<<"\ts2.a:"<<s1.a1[j]<<"\tflag:"<<flag;
				if(a1[i]==s1.a1[j])
				{
					if(flag==0)
						s2.a1[i]='0';
					else if(flag==1)
						s2.a1[i]='1';
				}
				else if(a1[i]>s1.a1[j])
				{
					if(flag==0)
						s2.a1[i]='1';
					else if(flag==1)
					{
						s2.a1[i]='0';
						flag=0;
					}
				}
				else if(a1[i]<s1.a1[j])
				{
					if(flag==0)
					{
						s2.a1[i]='1';
						flag=1;
					}
					else if (flag==1)
						s2.a1[i]='0';
				}
				cout<<"\ts3.a:"<<s2.a1[i];
			}
			s2.a1[l]='\0';
			if(flag==1)
			{
				cout<<"\nSubtraction is not possible!!!";
				exit (0);
			}
			return s2;
		}
		void display()
		{
			for(int i=0;i<=strlen(a1);i++)
			cout<<a1[i];
			return ;
		}
		 char operator[](int n)
		{
			return a1[n-1];
		}
};
int main()
{
	binary s1,s2,s3;
	int n;
	cout<<"Enter value for first binary number:";
	s1.takval();
	cout<<"Enter value for second binary number:";
	s2.takval();
	cout<<"The first binary digit is:\t";
	s1.display();
	cout<<"\nThe second binary digit is: -\t";
	s2.display();
	s3=s1-s2;
	cout<<"\nResult of the subtraction is: \t";
	s3.display();
	cout<<"\nEnter the digit to be extracted(from left):";
	cin>>n;
	cout<<"The following corrosponding digit is :" <<s3[n];
	return 0;
}

