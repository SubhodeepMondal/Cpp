/*A. Square String?
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A string is called square if it is some string written twice in a row. For example, the strings "aa", "abcabc", "abab" and "baabaa" are square. But the strings "aaa", "abaaab" and "abcdabc" are not square.

For a given string s determine if it is square.

Input
The first line of input data contains an integer t (1≤t≤100) —the number of test cases.

This is followed by t lines, each containing a description of one test case. The given strings consist only of lowercase Latin letters and have lengths between 1 and 100 inclusive.

Output
For each test case, output on a separate line:

YES if the string in the corresponding test case is square,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).*/
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, i, j,len,flag;
    string *a;
    cin>>n;
    a =  new string[n];
    for( i = 0; i<n; i++)
    cin>>a[i];
    for( i=0; i<n; i++)
    {
        len = a[i].length();
        flag = 1;
        for ( j = 0; j<len/2;j++)
        {
            if(len%2 != 0)
            {
                flag = 1;
                break;
            }
            if(a[i][j] != a[i][j+len/2])
            {
                flag = 1;
                break;
            }
            flag = 0;
        }
        if(flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }

}