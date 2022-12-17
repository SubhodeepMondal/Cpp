#include<iostream>
using namespace std;
class shell
{
	int a[20],n;
	public :
		void inti_array()
		{
			cout<<"Enter the size of array:";
			cin>>n;
			cout<<"Enter "<<n<<" values:";
			for(int i=0;i<n;i++)
			cin>>a[i];
		}
		void shell_sort()
		{
			for(int gap=n/2;gap>0;gap/=2)
			{
				for(int i=gap;i<n;i++)
				{
					int temp=a[i];
					int j;
					for(j=i;j>=gap && a[j-gap]>temp;j-=gap)
						a[j]=a[j-gap];
					a[j]=temp;
				}
			}
		}
		void print_array()
		{
			cout<<"\nThe array is: ";
			for(int i=0;i<n;i++)
				cout<<" "<<a[i];
		}
};
int main()
{
	shell s;
	s.inti_array();
	cout<<"Array before sorting: ";
	s.print_array();
	s.shell_sort();
	cout<<"\nArray after sorting: ";
	s.print_array();
	return 0;
}
