#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class stu_1
{
	protected:
	char name[25],sub_code[5],roll[5];
};
class stu_2 : public stu_1
{
	char sub_name[25];
	int inter_marks,exter_marks;
	public:
	void write_data()
	{
		fstream fi;
		fi.open("Result.dat", ios::app);
		stu_2 m;
		cout<<"Enter name of the student:";
		fflush(stdin);
		gets(m.name);
		cout<<"Enter the subject code:";
		fflush(stdin);
		gets(m.sub_code);
		cout<<"Enter roll_no:";
		fflush(stdin);
		gets(m.roll);
		cout<<"Enter subject name:";
		fflush(stdin);
		gets(m.sub_name);
		cout<<"Enter internal marks:";
		cin>>m.inter_marks;
		cout<<"Enter external marks :";
		cin>>m.exter_marks;
		fi.write((char *) & m,sizeof(m));
		fi.close();
	}
	void read_1()
	{
		stu_2 m;
		fstream fs;
		fs.open("Result.dat", ios::in);
		while(fs.read((char *)&m,sizeof(m)))
		{
			cout<<"\n"	<< setw(10) << m.name 
						<< setw(10) << m.sub_code 
						<< setw(10) << m.roll 
						<< setw(10) << m.sub_name 
						<< setw(10) << m.inter_marks 
						<< setw(10) << m.exter_marks;
		}
		fs.close();				
	}
	void display()
	{
		stu_2 m;
		fstream fs;
		char r[5];
		cout<<"\nEnter a roll no. of the student:";
		fflush(stdin);
		gets(r);
		fs.open("Result.dat",ios::in);
		while(fs.read((char *)&m,sizeof(m)))
		{
			if(strcmpi(m.roll,r)==0)
			{
				cout<<"\n"	<< setw(10) << m.name 
							<< setw(10) << m.sub_code 
							<< setw(10) << m.roll 
							<< setw(10) << m.sub_name 
							<< setw(10) << m.inter_marks 
							<< setw(10) << m.exter_marks;
			}
		}
		fs.close();
	}
};
int main()
{
	stu_2 m;
	int i=0;
	while(i<4)
	{
		cout<<"\n1.Insert data:\n2.Read whole database:\n3.Display a data:\n4.Exit: ";
		cin>>i;
		switch(i)
		{
			case 1:
				m.write_data();
				break;
			case 2:
				m.read_1();
				break;
			case 3:
				m.display();
				break;
		}
	}
	return 0;
}
