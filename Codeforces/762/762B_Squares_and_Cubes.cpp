/*B. Squares and Cubes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp likes squares and cubes of positive integers. Here is the beginning of the sequence of numbers he likes: 1, 4, 8, 9, ....

For a given number n, count the number of integers from 1 to n that Polycarp likes. In other words, find the number of such x that x is a square of a positive integer number or a cube of a positive integer number (or both a square and a cube simultaneously).

Input
The first line contains an integer t (1≤t≤20) — the number of test cases.

Then t lines contain the test cases, one per line. Each of the lines contains one integer n (1≤n≤109).

Output
For each test case, print the answer you are looking for — the number of integers from 1 to n that Polycarp likes.*/
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n , i,x,y,cube_root;
    long int *a, square, cube;
    cin >> n;
    a= new long int[n];
    int **count = new int*[n];

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        square = cube = 0;
        count[i] = new int[5];
        count[i][0] = count[i][1] = count[i][2] = count[i][3] = count[i][4] = 0;
        x = y = 1;
        while( a[i] >= cube || a[i] >= square )
        {
            cube = y*y*y;
            if( a[i] >= cube)
            {
                int square_root = sqrt(y);
                if(sqrt(y)- square_root != 0)
                    count[i][1]++;
                y++;
            }
            
            square = x*x;
            if( a[i] >= square)
            {
                count[i][0]++;
                x++;             
            }            
        }
        count[i][2] = x-1;
        count[i][3] = y-1;
        count[i][4] = count[i][0]+count[i][1];
        cout << count[i][4] << endl;
    }
}