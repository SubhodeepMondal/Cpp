#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n,count=0,length;
	char c[100],slb,sub;
	cin>>n;
	cout<<"word"<<endl;
	for(int i =0;i<n;i++)
	{
		cin>>c;
		length =strlen(c);
		if(length<=10)
			cout<<c<<endl;
		else
			cout<<c[0]<<length-2<<c[length-1]<<endl;
	}
	return 0;

}