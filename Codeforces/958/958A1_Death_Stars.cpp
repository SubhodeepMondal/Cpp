/*A1. Death Stars (easy)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The stardate is 1977 and the science and art of detecting Death Stars is in its infancy. Princess Heidi has received information about the stars in the nearby solar system from the Rebel spies and now, to help her identify the exact location of the Death Star, she needs to know whether this information is correct.

Two rebel spies have provided her with the maps of the solar system. Each map is an N × N grid, where each cell is either occupied by a star or empty. To see whether the information is correct, Heidi needs to know whether the two maps are of the same solar system, or if possibly one of the spies is actually an Empire double agent, feeding her false information.

Unfortunately, spies may have accidentally rotated a map by 90, 180, or 270 degrees, or flipped it along the vertical or the horizontal axis, before delivering it to Heidi. If Heidi can rotate or flip the maps so that two of them become identical, then those maps are of the same solar system. Otherwise, there are traitors in the Rebel ranks! Help Heidi find out.

Input
The first line of the input contains one number N (1 ≤ N ≤ 10) – the dimension of each map. Next N lines each contain N characters, depicting the first map: 'X' indicates a star, while 'O' indicates an empty quadrant of space. Next N lines each contain N characters, depicting the second map in the same format.

Output
The only line of output should contain the word Yes if the maps are identical, or No if it is impossible to match them by performing rotations and translations.*/
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, i, j, flag = 0;
    cin >> n;

    char *a_1 = new char[n*n];
    char *a_2 = new char[n*n];

    for ( i = 0 ; i < n*n ; i++ )
            cin >> a_1[i];
    for ( i = 0 ; i < n*n ; i++ )
            cin >> a_2[i];
    
    /*for ( i = 0 ; i < n*n ; i++ )
            cout<< a_2[i];*/
    
    //for 0 degree
    if(flag == 0)
    {           
        flag = 1;
        for ( i = 0 ; i < n ; i++ )
        {
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[i*n+j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
    }
    // for 90 degree
    if ( flag == 0)
    {
        int k = n - 1;
        flag = 1;
        for ( i = 0 ; i < n ; i++ )
        {
            //int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if( a_1[i*n+j] != a_2[k+j*n] )
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
            k--;
        }
    }
    // for 180 degree
    if ( flag == 0)
    {
        flag = 1;
        int l = n-1;
        for ( i = 0 ; i < n ; i++ )
        {
            int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[k+l*n])
                {
                    flag = 0;
                    break;
                }
                k--;
            }
            if(flag == 0)
                break;
            l--;
        }
    }
    // for 270 degree
    if ( flag == 0)
    {
        flag = 1;
        for ( i = 0 ; i < n ; i++ )
        {
            int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[i+k*n])
                {
                    flag = 0;
                    break;
                }
                k--;
            }
            if(flag == 0)
                break;
        }
    }
    // for 0 degree flip
    if ( flag == 0)
    {
        flag = 1;
        int l = n-1;
        for ( i = 0 ; i < n ; i++ )
        {
            int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[k+i*n])
                {
                    flag = 0;
                    break;
                }
                k--;
            }
            if(flag == 0)
                break;
        }
    }
    // for 90 degree flip
    if ( flag == 0)
    {
        flag = 1;
        int l = n-1;
        for ( i = 0 ; i < n ; i++ )
        {
            int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[l+k*n])
                {
                    flag = 0;
                    break;
                }
                k--;
            }
            if(flag == 0)
                break;
            l--;
        }
    }
    // for 180 degree flip
    if ( flag == 0)
    {
        flag = 1;
        int l = n-1;
        for ( i = 0 ; i < n ; i++ )
        {
            int k = n - 1;
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[j+l*n])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
            l--;
        }
    }
    // for 270 degree flip
    if ( flag == 0)
    {
        flag = 1;
        int l = n-1;
        for ( i = 0 ; i < n ; i++ )
        {
            for ( j = 0 ; j < n ; j++ )
            {
                if(a_1[i*n+j] != a_2[i+j*n])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
            l--;
        }
    }
    cout << endl;
    if ( flag == 1 )
        cout << "Yes";
    else
        cout << "No";
    
}