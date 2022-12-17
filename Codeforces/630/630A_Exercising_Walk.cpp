/*Alice has a cute cat. To keep her cat fit, Alice wants to design an exercising walk for her cat!

Initially, Alice's cat is located in a cell (x,y) of an infinite grid. According to Alice's theory, cat needs to move:

exactly a steps left: from (u,v) to (u−1,v);
exactly b steps right: from (u,v) to (u+1,v);
exactly c steps down: from (u,v) to (u,v−1);
exactly d steps up: from (u,v) to (u,v+1).
Note that the moves can be performed in an arbitrary order. For example, if the cat has to move 1 step left, 3 steps right 
and 2 steps down, then the walk right, down, left, right, right, down is valid.

Alice, however, is worrying that her cat might get lost if it moves far away from her. So she hopes that her cat is always in
the area [x1,x2]×[y1,y2], i.e. for every cat's position (u,v) of a walk x1≤u≤x2 and y1≤v≤y2 holds.

Also, note that the cat can visit the same cell multiple times.

Can you help Alice find out if there exists a walk satisfying her wishes?

Formally, the walk should contain exactly a+b+c+d unit moves (a to the left, b to the right, c to the down, d to the up). 
Alice can do the moves in any order. Her current position (u,v) should always satisfy the constraints: x1≤u≤x2, y1≤v≤y2. 
The staring point is (x,y).

You are required to answer t test cases independently.

Input
The first line contains a single integer t (1≤t≤103) — the number of testcases.

The first line of each test case contains four integers a, b, c, d (0≤a,b,c,d≤108, a+b+c+d≥1).

The second line of the test case contains six integers x, y, x1, y1, x2, y2 (−108≤x1≤x≤x2≤108, −108≤y1≤y≤y2≤108).

Output
For each test case, output "YES" in a separate line, if there exists a walk satisfying her wishes. Otherwise, output "NO" 
in a separate line.

You can print each letter in any case (upper or lower).*/
#include <iostream>
using namespace std;
int sumpath(int a[])
{
    return a[0] + a[1] + a[2] + a [3];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, i, j,flag = 1;
    int dirvec[4], sizevec[6];

    cin >> n;
    for ( i = 0 ; i < n; i++ )
    {
        for ( j = 0 ; j < 4 ; j++ )
            cin >> dirvec[j];
        
        for ( j = 0 ; j < 6 ; j++ )
            cin >> sizevec[j];

        
        while( sumpath(dirvec) && flag == 1)
        {
            flag  = 0;
            //left journey
            if( dirvec[0] > 0 )
            {
                if( sizevec[0]- sizevec[2] > 0)
                {
                    if ( sizevec[0]-sizevec[2] < dirvec[0])
                    {
                        dirvec[0] -= ( sizevec[0] - sizevec[2] );
                        sizevec[0] -= ( sizevec[0] - sizevec[2] );
                    }
                    else if ( sizevec[0] - sizevec[2] > dirvec[0] )
                    {
                        sizevec[0] -= dirvec[0];
                        dirvec[0] = 0;
                    }
                    flag = 1;
                }
                cout << sizevec[0] << " " << sizevec[1] << endl;
            }
            //right journey
            if( dirvec[1] > 0 )
            {
                if( (sizevec[4]-sizevec[0]) > 0 );
                {
                    if ( (sizevec[4]-sizevec[0]) < dirvec[1] )
                    {
                        dirvec[1] -= ( sizevec[4] - sizevec[0] );
                        sizevec[0] += ( sizevec[4] - sizevec[0] );
                        
                    }
                    else if ( (sizevec[4]-sizevec[0]) > dirvec[1] )
                    {
                        sizevec[0] += dirvec[1];
                        dirvec[1] = 0;
                        
                    }
                    flag = 1;
                }
                cout << sizevec[0] << " " << sizevec[1] << endl;
            }
            // down journey
            if( dirvec[2] > 0 )
            {
                if( (sizevec[5] - sizevec[1]) > 0 )
                {
                    if ( (sizevec[5] - sizevec[1]) < dirvec[2] )
                    {
                        dirvec[2] -= ( sizevec[5] - sizevec[1] );
                        sizevec[1] += ( sizevec[5] - sizevec[1] );
                        cout << " if top";
                    }
                    else if ( (sizevec[5] - sizevec[1]) > dirvec[2] )
                    {
                        sizevec[1] += dirvec[2];
                        dirvec[2] = 0;
                        cout << " else if down"; 
                    }
                    flag = 1;
                }
                cout << sizevec[0] << " " << sizevec[1] << endl;
            }
            // top journey
            if( dirvec[3] > 0 )
            {
                if( (sizevec[1] - sizevec[3]) > 0 )
                {
                    if ( (sizevec[1] - sizevec[3]) < dirvec[3] )
                    {
                        dirvec[3] -= ( sizevec[1] - sizevec[3] );
                        sizevec[1] -= ( sizevec[1] - sizevec[3] );
                        cout << " if top";
                    }
                    else if ( (sizevec[1] - sizevec[3]) > dirvec[3] )
                    {
                        sizevec[1] -= dirvec[3];
                        dirvec[3] = 0;
                        cout << " else if down"; 
                    }
                    flag = 1;
                }
                cout << sizevec[0] << " " << sizevec[1] << endl;
            }
            cout << dirvec[0] << " " << dirvec[1] << " "<< dirvec[2] << " "<< dirvec[3] << " " << endl;
            if( sumpath(dirvec) == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    


    }




}