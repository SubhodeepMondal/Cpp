/* Overload Two Operators for Binary Classes  */

#include<iostream>
#include<string.h>

using namespace std;

class sample
{
	char a[10];
	public:
		
		void read(char *);
		void write(void);
		sample operator - (sample);
		char operator [] (int);
};

void sample :: read(char *ch)
{
	strcpy(a,ch);
}

void sample :: write(void)
{
	for(int i=0 ; a[i] != '\0' ; i++)
		
		cout<<a[i];
}

sample sample :: operator - (sample s1)
{
	sample s2;
	int flag=0;
	int l=strlen(a);
	int j=strlen(s1.a);
	for(int i=l-1 ; i>=0 ; i--)
	{
		if(a[i] < s1.a[i] && flag==0)
		{
			a[i] = a[i] + 2;
			flag = 1;
		}
		
		if(flag == 1 && i > 0)
		{
			s1.a[i-1] = s1.a[i-1] + 1;
			flag = 0;
		}
		
		if(a[i] == s1.a[i])
		
			s2.a[i] = '0';
			
		else if(a[i] > s1.a[i])
		
			s2.a[i] = '1';
	}
	
	s2.a[l]='\0';
	return s2;
}

char sample :: operator [] (int k)
{
	return a[k-1];
}

main()
{
	sample s1,s2,s3;
	char ch1[10],ch2[10];
	int pos=0;
	
	cout<<"\nEnter First Binary Number: ";
	cin>>ch1;
	
	cout<<"\n\nEnter Second Binary Number: ";
	cin>>ch2;
	
	int l1=strlen(ch1)-strlen(ch2);
	char ch[20];
	int l,i;
	if(l1>0) l = l1;
	else l = -1 * l1;
	
	for(i=0 ; i<l ; i++ )
	{
		ch[i] = '0';
	}
	
	if(i == l)
	{
		ch[i] = '\0';
	}
	
	if(l1 > 0)
	{
		strcat(ch,ch2);
	}
	else
	{
		strcat(ch,ch1);
	}
	puts(ch1);
	puts(ch2);
	s1.read(ch1);
	
	s2.read(ch2);
	
	cout<<"\n\nFirst Binary Number is:  ";
	s1.write();
	
	cout<<"\n\nSecond Binary Number is: ";
	s2.write();  
	
	s3 = s1 - s2;
	
	cout<<"\n\nSubtraction Result is:   ";
	s3.write();
	
	cout<<"\n\nEnter a Position to Extract the Corresponding Bit: ";
	cin>>pos;
	
	cout<<"\nThe Corresponding Bit is: "<<s3[pos];
	
	return 0;
}
