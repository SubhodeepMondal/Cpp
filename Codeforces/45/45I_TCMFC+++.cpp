/*I. TCMCF+++
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has gotten interested in programming contests in TCMCF+++ rules.
On the contest n problems were suggested and every problem had a cost — a certain integral number 
of points (perhaps, negative or even equal to zero). According to TCMCF+++ rules, only accepted 
problems can earn points and the overall number of points of a contestant was equal to the product
 of the costs of all the problems he/she had completed. If a person didn't solve anything, 
 then he/she didn't even appear in final standings and wasn't considered as participant. 
 Vasya understood that to get the maximal number of points it is not always useful to solve all 
 the problems. Unfortunately, he understood it only after the contest was finished. 
 Now he asks you to help him: find out what problems he had to solve to earn the maximal number of 
 points.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of the suggested problems. 
The next line contains n space-separated integers ci ( - 100 ≤ ci ≤ 100) — the cost of the i-th 
task. The tasks' costs may coinсide.

Output
Print space-separated the costs of the problems that needed to be solved to get the maximal 
possible number of points. Do not forget, please, that it was necessary to solve at least one 
problem. If there are several solutions to that problem, print any of them.*/

#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, countNeg = 0 , coountZero = 0, i ;
    cin>> n;
    int *arr = new int[n];
    for ( int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        if(arr[i] < 0)
            countNeg++;
        else if ( arr[i] == 0 )
            coountZero++;
    }

    //int *arrNeg = 
    for ( i = 0; i < n - 1 ; i++ )
    {
        for ( int j = 0; j < n - i - 1; j++)
        { 
            if(arr[j]> arr[j+1])
            {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                } 
        }
    }

    for ( i = 0; i < countNeg ; i++)
    {
        if( arr[i] < 0 && countNeg % 2 == 0 )
            cout << arr[i] << " ";
        else
            if(arr[i] < 0 && i != countNeg-1)
                cout << arr[i] << " ";
            else if ( arr[i] < 0 && n == 1 )
                cout << arr[i] << " ";
    }

    if( countNeg == 0)
    {
        i = 0;
        if(arr[i] == 0 && n == coountZero)
            cout << arr[i++] << " ";
    }
    else
    {
        if(countNeg = 1 && arr[i] == 0 && n == 2)
            cout << arr[i++] << " ";
        for ( ; i< countNeg + coountZero; i++);
    }

    if( countNeg == 0 && coountZero == 0)
        i = 0;
    for( ; i < n ; i++)
        if( arr[i] > 0 )
            cout << arr[i] << " " ;

}