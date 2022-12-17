/*B. Martian Dollar
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya got hold of information on the Martian dollar course in bourles for the next n days. 
The buying prices and the selling prices for one dollar on day i are the same and are equal to a_i. 
Vasya has b bourles. He can buy a certain number of dollars and then sell it no more than once in n days. 
According to Martian laws, one can buy only an integer number of dollars. Which maximal sum of money in 
bourles can Vasya get by the end of day n?

Input
The first line contains two integers n and b (1 ≤ n, b ≤ 2000) — the number of days and the initial number of 
money in bourles. The next line contains n integers ai (1 ≤ ai ≤ 2000) — the prices of Martian dollars.

Output
Print the single number — which maximal sum of money in bourles can Vasya get by the end of day n.*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, b,i,j,k,max = 0, min =2001,minPrev;
    int *bourles1,*bourles2,doller=0,minIndex,maxIndex=0,initial = 0, **a;
    cin >> n >> b;
    bourles1 = new int[n];
    a = new int* [n];
    for ( i = 0 ; i<n; i++)
    {
        cin >> bourles1[i];
        a[i] = new int [4];
    }
    i=0;
    int l = 0;

    while( i < n )
    {    
        for ( i = initial; i < n; i++)
        {
            if( i != 0 && max < bourles1[i] && bourles1[i-1] < bourles1[i] )
            {
                max = bourles1[i];
                maxIndex = i;
                //break;
            }
        }
        //cout << max << " "<< maxIndex<< endl;
        for ( j = initial; j< maxIndex; j++)
        {  
                
            minIndex = -1;
            int minPrev = minIndex;    
            for ( k = initial ; k< maxIndex ; k++)
            {
                if( min > bourles1[k] )
                {
                    //cout << min <<endl;
                    min = bourles1[k];
                    bourles1[k] = 2001;
                    minIndex = k;
                    //cout << min << " "<< minIndex <<endl;
                }
            }
        }
        initial = maxIndex + 1;
    }
    
            if (minPrev != minIndex && minIndex != -1 && b > min && max != 0)
            {
                int imidiatePurcase = floor(b/min);
                doller += imidiatePurcase;
                b -= imidiatePurcase * min;
                //cout << doller << " " << min << " " << b <<endl;
                minPrev = minIndex;
            }
    cout << ( doller * max ) + b;
}