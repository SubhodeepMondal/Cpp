#include<iostream>
#include<math.h>
using namespace std;
class circle
{
	float redius;
	
	public: 
	circle (float n)
		{
			redius=n;
			cout<<"The area of the circle is:"<<redius;
		}	
		float circumference()
		{
			float cir=2*redius*3.14285;
			return (cir);
		}
		float cir_area()
		{
			float ar=3.14285*pow(redius,2);
			return (ar);
		}
};
class cylinder :public circle
{
	float hight;
	
	public:
		cylinder (float i) { hight=i; }
		float area()
		{
			cout<<"\nThe area of the circle:"<<cir_area();
			cout<<"Area of the cylinder is:"<<2*cir_area()+hight*circumference()<<" squre unit.";
		}
		float volume()
		{
			cout<<"\nThe circumference of the circle:"<<circumference();
			return (cir_area()*hight);
		}
};
int main()
{
	cylinder c1;
	circle c2;
	int x1,x2,y1,y2;
	float red,n;
	cout<<"Enter the co-ordinate of the circle's centre:";
	cin>>x1>>y1;
	cout<<"Enter a co-ordinate of the circle's circumference:";
	cin>>x2>>y2;
	red=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	c2=circle(red);
	cout<<"\nEnter the hight of the cylinder:";
	cin>>n;
	c1=cylinder(n);
	c1.area();
	
	
	cout<<"\nVolume of the cylinder is:"<<c1.volume()<<" qubic unit.";
	return 0;
}
