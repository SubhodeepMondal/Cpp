/*A. Parsa's Humongous Tree
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Parsa has a humongous tree on n vertices.

On each vertex v he has written two integers lv and rv.

To make Parsa's tree look even more majestic, Nima wants to assign a number av (lv≤av≤rv) to each vertex v such that the 
beauty of Parsa's tree is maximized.

Nima's sense of the beauty is rather bizarre. He defines the beauty of the tree as the sum of |au−av| over all edges (u,v)
 of the tree.

Since Parsa's tree is too large, Nima can't maximize its beauty on his own. Your task is to find the maximum possible beauty
 for Parsa's tree.

Input
The first line contains an integer t (1≤t≤250) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤105) — the number of vertices in Parsa's tree.

The i-th of the following n lines contains two integers li and ri (1≤li≤ri≤109).

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n,u≠v) meaning that there is an edge between the vertices u
 and v in Parsa's tree.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅10^5.

Output
For each test case print the maximum possible beauty for Parsa's tree.*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i = 0, j = 0, n;
    string rawInput,temp;
    int ** vartexValue, **edges;
    cin>> n;
    vartexValue = new int*[n];
    edges = new int*[n];
    int *testCases = new int [n];

    while(i<n)
    {
        cin >> testCases[i];
        while( j < testCases[i] )
        {
            vartexValue[i] = new int[testCases[i]];
            getline(cin,rawInput);
            stringstream myString(rawInput);
            int k = 0;
            while(getline(myString,temp,' '))
                vartexValue[i][k++] =(int) stoul(temp, nullptr,0);
            j++;      
        }
        j=0;
        while(j< testCases[i]-1)
        {
            edges[i] = new int[testCases[i]];
            getline(cin,rawInput);
            stringstream myString(rawInput);
            int k = 0;
            while(getline(myString,temp,' '))
                edges[i][k++] =(int) stoul(temp, nullptr,0);
            j++;
        }
    }
    cout<< testCases[0];
    for ( i = 0; i < testCases[0] ;i++)
    {
        for ( int j = 0; j<2;j++)
        {
            cout << vartexValue[i][j] << " " << edges[i][j];
        }
    }
    

}