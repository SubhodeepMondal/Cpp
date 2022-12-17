#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int org,num,rem,n=0,sum=0;
	cout<<"enter a positive integer:";
	cin>>org;
	num=org;
	while(num!=0)
	{
		num=num/10;
		n++;
	}
	num=org;
	while(num!=0)
	{
		int digit=num%10;
		sum+=pow(digit,n);
		num/=10;
	}
	if(sum==org)
		cout<<org <<" is an Armstrong number.";
	else
		cout<<org<<" is not an Armstrong number.";
	return 0;
}
