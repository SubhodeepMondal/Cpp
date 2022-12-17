/*C. Wrong Addition
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Tanya is learning how to add numbers, but so far she is not doing it correctly. She is adding two numbers a and b using the following algorithm:

If one of the numbers is shorter than the other, Tanya adds leading zeros so that the numbers are the same length.
The numbers are processed from right to left (that is, from the least significant digits to the most significant).
In the first step, she adds the last digit of a to the last digit of b and writes their sum in the answer.
At each next step, she performs the same operation on each pair of digits in the same place and writes the result to the left side of the answer.
For example, the numbers a=17236 and b=3465 Tanya adds up as follows:

+17236034651106911
calculates the sum of 6+5=11 and writes 11 in the answer.
calculates the sum of 3+6=9 and writes the result to the left side of the answer to get 911.
calculates the sum of 2+4=6 and writes the result to the left side of the answer to get 6911.
calculates the sum of 7+3=10, and writes the result to the left side of the answer to get 106911.
calculates the sum of 1+0=1 and writes the result to the left side of the answer and get 1106911.
As a result, she gets 1106911.

You are given two positive integers a and s. Find the number b such that by adding a and b as described above, Tanya will get s. Or determine that no suitable b exists.

Input
The first line of input data contains an integer t (1≤t≤104) — the number of test cases.

Each test case consists of a single line containing two positive integers a and s (1≤a<s≤1018) separated by a space.

Output
For each test case print the answer on a separate line.

If the solution exists, print a single positive integer b. The answer must be written without leading zeros. If multiple answers exist, print any of them.

If no suitable number b exists, output -1.*/

#include <iostream>
#include <string>

using namespace std;

void print(string  str)
{
    int len = str.length();
    int flag = 0;
    for( int i = len-1 ; i>= 0; i--)
    {
            
        if(flag != 0 || str[i] != '0')
        {
            cout << str[i];
            flag = 1;
        }
    }
    cout << endl;
}

string reverse(string str)
{
    string st;
    for(int i = str.length()-1 ; i>=0;i--)
        st += str[i];
    return st;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, i,j,k,l,a_len,s_len,b_len,top,bot,flag_2,flag_1;
    cin >> n;
    string *a, *s,*b;
    a = new string[n];
    s = new string[n];
    b = new string[n];
    for( i=0; i<n; i++ )
        cin >> a[i] >> s[i];
    
    for( i=0; i<n; i++ )
    {
        j = a[i].length()-1;
        k = s[i].length()-1;
        l = 0;
        flag_1 = 1;
        while( k>=0 )
        {

            if(j>=0)
                bot = a[i][j--] - '0';
            else
                bot = 0;


            top = (s[i][k--] - '0');
                

            if(top<bot)
            {
                if( k>=-1 )
                    top += 10 * (s[i][k--]- '0');
                else
                {
                    flag_1 = 0;
                    break;
                }
            }


            if(top <=18 && (top - bot) >= 0)
                    b[i] += to_string(top-bot);
            else
            {
                flag_1 = 0;
                break;
            }

        }


        if(j!= -1)
            flag_1 = 0;

        if(flag_1 == 1)
            print(b[i]);
        else
            cout << -1 << endl;
    }
}