/*C. Count Triangles
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Like any unknown mathematician, Yuri has favourite numbers: A, B, C, and D, where A≤B≤C≤D. 
Yuri also likes triangles and once he thought: how many non-degenerate triangles with integer sides 
x, y, and z exist, such that A≤x≤B≤y≤C≤z≤D holds?

Yuri is preparing problems for a new contest now, so he is very busy. That's why he asked you to calculate 
the number of triangles with described property.

The triangle is called non-degenerate if and only if its vertices are not collinear.

Input
The first line contains four integers: A, B, C and D (1≤A≤B≤C≤D≤5⋅105) — Yuri's favourite numbers.

Output
Print the number of non-degenerate triangles with integer sides x, y, and z such that the inequality 
A≤x≤B≤y≤C≤z≤D holds.*/

#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i, j, k, a, b, c, d, count = 0, x ;
    cin >> a >> b >> c >> d;
    //cout << a << " " << b << " " << c << " " << d << endl;

    for (i = c ; i <= d; i++)
    {
        for ( j = b  ; j <= c ; j++ )
        {
            x = i - j + 1;
             
            if( x > b )
                continue;

            else 
                count += ( b - j + 1 ) ;
        }
    }

    cout << count;
    return 0;
}