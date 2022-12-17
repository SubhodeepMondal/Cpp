#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>
using namespace std;

class fix
{
	string infix;
	stack <char> temp;
	stack <char> postfix;
	public:
		fix()
		{
			cout<<"Enter a expression use () at the beggning):";
		    fflush(stdin);
		    getline(cin,infix);
		}
		int priority(char a) 
		{
		    int temp;
		    if (a == '^')
		        temp = 1;
		        else if (a=='(')
		         temp =4;
		    else  if (a == '*' || a == '/')
		        temp = 2;
		    else  if (a == '+' || a == '-')
		        temp = 3;
		    return temp;
		}
		int in2post()	
			{
			    for(int i=0;i<infix.length();i++)
			    {
			    	if(infix[i]=='/' || infix[i]=='*' || infix[i]=='+' || infix[i]=='-'||infix[i]=='^')
			    	{
			    		if(!temp.empty() && priority(temp.top())<=priority(infix[i]))
			    		{
			    			cout<<temp.top();
			    			temp.pop();
			    			temp.push(infix[i]);
						}
						else
			    			temp.push(infix[i]);
					}	
			    	else if(infix[i]=='(')
			    	{
			    		temp.push(infix[i]);
					} 
					else if(infix[i]==')')
					{
						do
						{
							cout<<temp.top();
							temp.pop();
						}while(temp.top()!='(');
						temp.pop();
					}
					else
			    	{
			    		postfix.push(infix[i]);
			    		cout<<postfix.top();
					}
				}
				return 0;
			}
};

int main() 
{
	fix f;
	cout<<"The expression in postfix:  ";
	f.in2post();
	return 0;
}

