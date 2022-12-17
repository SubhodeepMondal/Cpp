#include<iostream>
#include<string.h>
using namespace std;
class sequence
{
	char **a;
	int n,k;
	public:
		sequence()
		{
			cout<<"Object is initialized constructor:\n";
		}
		~sequence()
		{
			cout<<"Destroying object!";
		}
		void init()
		{
			k=0;
			cout<<"Enter number of string:";
			cin>>n;
			a=new char *[n+1];
			for(int i=0;i<n;i++)
				a[i]= new char[20];
		}
		int insert()
		{
			int i;
			if(n==k)
			{
				cout<<"\nArray overflow.";
				return 0;
			}
			char str[20];
			fflush(stdin);
			cout<<"\nEnter a string:";
			gets(str);
			
			for(i=0;i<k;i++)
			{
				if(strcmp(str,a[i])<0)
				{
					for(int j=k;j>i;j--)
						strcpy(a[j],a[j-1]);
					break;
				}
			}
			k++;
			strcpy(a[i],str);
			return 0;
		}
		void print()
		{
			for(int i=0;i<k;i++)
				cout<<"\n"<<a[i];
		}
		void del()
		{
			int i;
			char str[20];
			cout<<"Enter the string to delete:";
			fflush(stdin);
			gets(str);
			for(i=0;i<k;i++)
				if(strcmp(str,a[i])==0)
				{
					for(int j=i;j<k-1;j++)
						strcpy(a[j],a[j+1]);
					k--;
					cout<< "Entered item is deleted!";
					break;
				}
			if(i==k)
				cout<<"string not found";
		}
		void search()
		{
			int i;
			char str[20];
			cout<<"Enter the string to search:";
			fflush(stdin);
			gets(str);
			for(i=0;i<k;i++)
				if(strcmp(str,a[i])==0)
				{
					cout<<"Entered string "<<a[i]<<" is found at location "<<i+1;
					break;
				}
			if(i==k)
				cout<<"String not found.";
		}
};
int main()
{
	int n=0;
	sequence s;
	s.init();
	while(n<5)
	{
		cout<<"\n\n1. insert\n2.Print all string\n3.Delete\n4.Search a string\n5.Exit:";
		cin>>n;
		switch(n)
		{
			case 1:
				s.insert();
				break;
			case 2:
				s.print();
				break;
			case 3:
				s.del();
				break;
			case 4:
				s.search();
				break;
		}
	}
return 0;	
}
