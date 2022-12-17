#include<iostream>
using namespace std;

class matrix
{
	int *a;
	int x,y;
	void initilize()
	{
		for(int i = 0; i<x; i++)
		{
			for(int j = 0; j<y; j++)
			{
				a[i*y+j] = rand() % 10;
//				cout<<&a[i*x+j]<<" "<<a[i*x+j]<<" "<<i*x+j<<" "<<i<<" "<<j<<" "<<x<<endl;
			}
		}
	}



public:
	matrix(int m, int n,int i)
	{
		x=m;
		y=n;
//		cout<<x*y<<endl;
		a = new(nothrow) int[x*y];
/*		if( !a )
		{
			cout<<"Memory allocation failed";
		}*/
		cout<<a<<" "<<x<<" "<<y<<endl;
		initilize();
	}
	matrix(int m,int n)
	{
		x=m;
		y=n;
		a= new int[x*y];
	}
	~matrix()
	{
		delete [] a;
	}


	void print()
	{
		cout<<endl<<"The matrix is:\n";
		for(int i = 0; i<x; i++)
		{
			for(int j =0; j<y; j++)
			{
				cout<<a[i*y+j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
	}


	matrix operator +(matrix b)
	{
		matrix c(x,y);

		for(int i = 0; i<y; i++)
		{
			for(int j = 0; j<x; j++)
			{
				*(c.a+(i*x)+j) = *(b.a+(i*x)+j) + *(a+(i*x)+j);
			}
		}
		return c;
	}


	matrix operator *(matrix b)
	{
		int sum;
		matrix c(x,b.y);

		for(int i = 0; i<x; i++)
		{
			for(int j = 0; j<b.y; j++)
			{
				sum = 0;
				for(int k = 0; k<y; k++)
				{
					sum= sum + a[i*x+k] * b.a[k*b.y+j];
//					cout<<a[i*x+k]<<" "<<b.a[k*b.y+j]<<" "<<&b.a[k*b.y+j]<<" "<<k*b.y+j<<"\t";
				}
				c.a[i*x+j] = sum;
//				cout<<c.a[i*x+j]<<endl;
			}
		}
		return c;
	}

};

int main()
{
	int n,m;

	cout<<"Enter the row and column size of matrix:"<<endl;
	cin>>m;
	cin>>n; 
	matrix mat1 = matrix(m,n,0);
	mat1.print();

	cout<<"Enter the row and column size of matrix:"<<endl;
	cin>>m;
	cin>>n;
	matrix mat2 = matrix(m,n,0);
	mat2.print();

//	matrix mat3 = mat1 + mat2;
//	mat3.print();

	matrix mat3 = mat1 * mat2;
	mat3.print();
	return 0;
}