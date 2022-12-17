/*   Design a Class CYLINDER that can Capture the Properties of a Cylinder and Perform Usual Operation on the cylinder.
	Derive this Class from CIRCLE Class. The Operations theat Can be Performed on Cylinder are :-
	a) Calculate and Print the Volume.
	b) Calculate and Print the Surface Area.
	c) Set the Radius, Height and the Centre of Base. */

#include<iostream>
#include<cmath>
using namespace std;

class circle
{
		int x1,y1,x2,y2;
		protected:
		float radius;
		
	public:
		circle()
		{
			x1=0;
			y1=0;
			x2=0;
			y2=0;
			radius=0;
		}
		
		void input(void)
		{	
			cout<<"\nEnter Co-Ordinates of Centre of the Base of the Circle: ";
			cin>>x1>>y1;
			
			cout<<"\nEnter Co-Ordinates of Any Point on the Circumferance of the Base of the Circle: ";
			cin>>x2>>y2;
			
			radius = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
			cout<<"\nRadius of the Circle is: "<<radius;
		}
};

class cylinder : public circle
{
	float height;
	public:
		
		cylinder()
		{
			height=0;
		}
		void input(void)
		{
			cout<<"\nEnter the Height of the Cylinder: ";
			cin>>height;	
		}
		void volume(void);
		void surface_area(void);
};

void cylinder :: volume (void)
{
	cout<<"\nIN VOLUME: Radius = "<<radius;
	float vol;
	vol=3.14285*pow(radius,2)*height;
	cout<<"\nVolume of the Cylinder is: "<<vol<<" Cubic Unit \n";
} 

void cylinder :: surface_area (void)
{
	float sur_area;
	sur_area=2*3.14285*radius*(radius+height);
	cout<<"\nSurface Area of the Cylinder is: "<<sur_area<<" Square Unit \n";
}

main()
{
	cylinder c;
	c.circle::input();
	c.cylinder::input();
	c.volume();
	c.surface_area();
}

