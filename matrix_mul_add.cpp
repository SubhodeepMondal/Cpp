#include<iostream>
using namespace std;
class matrix
{
	int **m;
	int sz1,sz2;
	public:
		matrix(int a,int b)
		{
			m=new int*[sz1=a];
			for(int i=0;i<sz1;i++)
			{
				m[i]=new int[sz2=b];
				for(int j=0;j<sz2;j++)
					m[i][j]=0;
			}
		}
		void initlize(void)
		{
			cout<<"Enter the values row-wise:";
			for(int i=0;i<sz1;i++)
				for(int j=0;j<sz2;j++)
					cin>>m[i][j];
		}
		matrix operator*(matrix b)
		{
			matrix c(sz1,b.sz2);
			int sum=0;
			if(sz2!=b.sz1)
			{
				cout<<"Matrix multiplication is not possible.";
			}
			else
			{
				for(int i=0;i<sz1;i++)
					for(int j=0;j<b.sz2;j++)
					{
						for(int k=0;k<sz2;k++)
						{
							sum+=m[i][k]*b.m[k][j];
						}
						c.m[i][j]=sum;
						sum=0;
					}
			}
			return c;
		}
		matrix operator+(matrix b)
		{
			matrix c(sz1,sz2);
			if(sz1!=b.sz1||sz2!=b.sz2)
			{
				cout<<"Matrix addition is not possible.";
			}
			else
			{
				for(int i=0;i<sz1;i++)
				{
					for(int j=0;j<sz2;j++)
					{
						c.m[i][j]=m[i][j]+b.m[i][j];
					}
				}
					
			}
			return c;
		}
		void display(matrix a)
		{
			for(int i=0;i<a.sz1;i++)
			{
				cout<<"\n";
				for(int j=0;j<a.sz2;j++)
				 cout<<a.m[i][j]<<"\t";
			}
		}
		void display()
		{
			for(int i=0;i<sz1;i++)
			{
				cout<<"\n";
				for(int j=0;j<sz2;j++)
				 cout<<m[i][j]<<"\t";
			}
		}
};
int main()
{
	int i=0,n,m,p,q;
	
	cout<<"Enter the number of rows of 1st matrix:";
	cin>>m;
	cout<<"Enter the number of columns of 1st matirx:";
	cin>>n;
	matrix a=matrix(m,n);
	a.initlize();
	cout<<"The given matrix is:\n";
	cout<<"\nEnter the number of rows of 2nd matrix:";
	cin>>p;
	cout<<"Enter the number of columns of 2nd matrix:";
	cin>>q;
	matrix b=matrix(p,q);
	b.initlize();
	cout<<"The given matrix is:\n";
	while(i<3)
	{
		cout<<"\n1. Multiplication\n2.Addition\n*. Else to exit:";
		cin>>i;
		switch(i)
		{
			case 1:
				{
					matrix c=a*b;
					a.display(c);
					break;
				}
			case 2:
				{
					matrix d=a+b;
					a.display(d);
					break;
				}
		}
	}
	return 0;
}
