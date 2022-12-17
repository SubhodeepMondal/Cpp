#include <iostream>
using namespace std;
class AC
{
	friend class remote;
	bool ac_con;
	public :
		void remote();
};
class remote
{
	friend class AC;
	bool rc_con=false;
	public:
		void display(AC x)
		{
			int n;
			cout<<"\nchecking AC condition";
			if(x.ac_con!=true)
			{
				cout<<"\nAC is not in off state. !!! can't work.";
			}
			if(x.ac_con==true)
			{
				if(rc_con==true)
				cout<<"\nThe remote control is in normal mode";
				else if(rc_con!=true)
				cout<<"\nThe remote control is in inactive mode";
			}
		};
};
void AC::remote()
{
	int n;
	cout<<"AC:\n0 for turning off.\n1 for to turning on.";
	cin>>n;
	if(n==0)
	 {
	 	ac_con=false;
	 	cout<<"\nAC is turned off";
	 }
	 else if(n==1)
	 {
	 	ac_con=true;
	 	cout<<"\nAC is turned on.";
	 }
}

int main()
{
	AC a;
	remote b;
	int n=1;
	while(n<3)
	{
		cout<<"\n1 to toggle AC state.\n2 to display remote condition.\n3 to exit.";
		cin>>n;
		switch(n)
		{
			case 1: a.remote();
					break;
			case 2: b.display(a);
					break;
		}
	}
	return 0;	
}