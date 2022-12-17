#include<iostream>
#include<string.h>
using namespace std;
class binary
{
	char a1[20];
	public:
		void takval()
		{
			cout<<"Enter the value of the first binary digit";
			gets(a1);
		}
		
		binary operator - (binary s1)
		{
			binary s2;
			int flag=0;
			int l=strlen(a1);
			int j=strlen(s1.a1);
			for(int i=l-1;i>=0;i--)
			{
				j--;
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
			}
			s2.a1[l]='\0';
			cout<<"The result of the substraction is :";
			for( int i=0;i<=strlen(s2.a1);i++)
			cout<<s2.a1[i];
			return s2;
		}
		char operator [] (int n)
		{
			return a1[n-1];
		}
};
int main()
{
	binary s1,s2,s3;
	int n;
	s1.takval();
	s2.takval();
	s3=s1-s2;
	cout<<"\nEnter the digit to be extracted:";
	cin>>n;
	cout<<"The following corrosponding digit is :" <<s3[n];
	return 0;
}
