#include <iostream>

using namespace std;

int main()
{
	int n,a[3],count =0;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cin>>a[0]>>a[1]>>a[2];
		int sum = a[0]+a[1]+a[2];
		if(sum>1)
			count++;
	}
	cout<<count<<endl;
}