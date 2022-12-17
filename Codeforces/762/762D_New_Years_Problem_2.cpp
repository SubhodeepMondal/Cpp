#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Param{
    int friendA,friendB, max, secndMax,shop;
}param;

param findMaxPair(int shop, int *a,int n)
{
    param abc;
    int max,secMax;
    max = secMax = 0;
    abc.friendA = abc.friendB = 0;
    for(int i=0; i<2; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i == 0)
            {
                if(a[j]>max)
                {
                    max = a[j];
                    abc.friendA = j;
                }
            }
            else if( i == 1 )
            {
                if( a[j] > secMax && a[j] <= max && j != abc.friendA )
                {
                    abc.friendB = j;
                    secMax = a[j];
                }
            }
            
        }
    }
    abc.shop = shop;
    abc.max = a[abc.friendA];
    abc.secndMax = a[abc.friendB];
//    cout << abc.max << " " << abc.secndMax << " " << abc.friendA << " " << abc.friendB << "\t\t";
    return abc;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif

    int n, m, i, j, maxJoy, tCase, sum, shopCount,min;
    int maxfriend, secMaxFriend=0, maxPairShop=0,secMax=0;
    int **b, **a, *visitedShop;
    cin >> tCase;
    

    while( tCase > 0 )
    {
        cin >> m >> n;
        a = new int* [m];
        b = new int* [n];
        visitedShop = new int[m];
        //taking input for joy Matrix
        for ( i=0; i < m; i++ )
        {
            visitedShop[i] = 0;
            a[i] = new int[n];
            for( j=0; j<n; j++)
                cin >> a[i][j];
        }

        // assigining space for b array!
        for ( i=0; i<n; i++ )
            b[i] = new int[2];

        // finding best shop for each friend!
        for( i=0; i<n; i++)
        {
            maxJoy = 0;
            for( j=0; j<m; j++ )
            {
                if( maxJoy < a[j][i] )
                {
                    b[i][0] = maxJoy = a[j][i];
                    b[i][1] = j;
                }
            }
        }

        // counting no of shop visited
        shopCount = 0;
        for( i=0; i<n; i++ )
        {
            if(visitedShop[b[i][1]] == 0)
            {
                shopCount ++;
                visitedShop[b[i][1]] = 1;
            }
        }

        
        int *shop = new int[n];
        param abc;
        //if shopCount > (n-1)
        if(shopCount==n)
        {
            for( i=0; i<m; i++ )
            {
                for(j =0; j<n; j++)
                    shop[j] = a[i][j];

                abc = findMaxPair(i,shop,n);
//                cout << abc.friendA << " " << abc.friendB << " " << abc.max << " " << abc.secndMax << " " << abc.shop << "\t";
                if( abc.secndMax  > secMax)
                {
                    maxfriend = abc.friendA;
                    secMaxFriend = abc.friendB;
                    maxPairShop = i;
                    secMax = abc.secndMax;
//                    cout << secMax << " " << endl;
                }

            }
            //cout << maxfriend << " " << secMaxFriend << " " << maxPairShop << endl;
            b[maxfriend][0]= a[maxPairShop][maxfriend];
            b[secMaxFriend][0] = a[maxPairShop][secMaxFriend];
        }
/*        for( i = 0; i<n; i++)
            cout << b[i][0] << " ";
        cout << endl;*/
        min =2147483647;
        for( i = 0; i<n; i++)
            if(min>b[i][0])
                min = b[i][0];
        cout << min<< endl;
        tCase--;  
    }
}
