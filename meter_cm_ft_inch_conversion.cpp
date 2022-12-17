#include<iostream>
using namespace std;
class dm
{
	float m,cm;
	public:
		getdata()
		{
			cout<<"Enter the value for meter:";
			cin>>m;
			cout<<"Enter the value for centimeter:";
			cin>>cm;
		}
		float calculate()
		{
			return (m*100+cm);
		}
};
class dn
{
	float ft,in;
	public:
		getdata()
		{
			cout<<"Enter the value for feet:";
			cin>>ft;
			cout<<"Enter the value for inch:";
			cin>>in;
		}
		float calculate()
		{
			return (ft*12+in);
		}
};
int main()
{
	dm a;
	dn b;
	int i=0,s;
	float sm;
	a.getdata();
	b.getdata();
	while(i<3)
	{
		cout<<"\n      ********menu********\n1. Results in meter/centimeter\n2. Results in feet/inch\n*. Else to exit:";
		cin>>i;
		switch(i)
		{
			case 1:
				{
					cout<<"Result is:";
					s=a.calculate()/100+(b.calculate()*2.54)/100;
					cout<<s<<" meter ";
					sm=(a.calculate()/100+(b.calculate()*2.54)/100)-s;
					cout<<sm<<" centimeter.\n"; 
					break;
				}
				case 2:
				{
					cout<<"Result is:";
					s=(a.calculate()*0.3937)/12+b.calculate()/12;
					cout<<s<<" feet ";
					sm=((a.calculate()*0.3937)/12+b.calculate()/12)-s;
					cout<<sm<<" inch.\n";
					break;
				}
		}
	}
	return 0;
}
