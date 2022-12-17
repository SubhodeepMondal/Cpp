/* F. Binary Notation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a positive integer n. Output its binary notation.

Input
The only line of input data contains an integer n (1 ≤ n ≤ 106).

Output
Output the binary notation of n (without any leading zeros).*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <charconv>
 using namespace std;

 int main()
 {
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
    int size,i=0;
    long long n,num=0;
    cin>>n;
    size = ceil(log2(n));
    int numSize = --size;
    char ch;
    char *binNumber = new char[size];
    while(n != 0)
    {
        ch = '0'+ (n%2);
        binNumber[size--] = ch;
        //cout<< binNumber[size--];
        num = num + (n%2)*pow(10, i++ );
        n = n/2;
        //cout<<ch;
    }
    for (i = 0; i<=numSize ;i++)
        cout<<binNumber[i];
    return 0;

 }