#include<iostream>
#include<math.h>
using namespace std;
class circle
{
		float radius;
	public:
		circle(float i)
		{
			radius=i;
		}
		void val (float red)
		{
			radius=red;
			cout<<"The radius of the circle is:"<<radius<<" unit.";
		}	
		float circumference()
		{
			return (2*radius*3.14);
		}
		float cir_area()
		{
			return (3.14*pow(radius,2));
		}
};
class cylinder : public circle
{
	protected:
	float hight;
	
	public:
		/*cylinder (float n)
		{
			hight=n;
		}*/
		void tak_val (float i) { hight=i; }
		void area()
		{
			cout<<"\nArea of the cylinder is:"<<2*cir_area()+circumference()*hight<<" squre unit.";
		}
		void volume()
		{
			cout<<"\nVolume of the cylinder is:"<<cir_area()*hight<<" qubic unit.";
		}
};
int main()
{
	cylinder c1;
	float red,n,x1,x2,y1,y2;
	cout<<"Enter the co-ordinate of the circle's centre:";
	cin>>x1>>y1;
	cout<<"Enter a co-ordinate of the circle's circumference:";
	cin>>x2>>y2;
	red=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	c1.circle::circle(red);
	cout<<"\nEnter the hight of the cylinder:";
	cin>>n;
	c1.tak_val(n);
	c1.area();
	c1.volume();
	return 0;
}
