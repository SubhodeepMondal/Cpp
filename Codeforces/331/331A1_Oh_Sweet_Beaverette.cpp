/*A1. Oh Sweet Beaverette
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
— Oh my sweet Beaverette, would you fancy a walk along a wonderful woodland belt with me?

— Of course, my Smart Beaver! Let us enjoy the splendid view together. How about Friday night?

At this point the Smart Beaver got rushing. Everything should be perfect by Friday, so he needed to prepare the belt to the upcoming walk. 
He needed to cut down several trees.

Let's consider the woodland belt as a sequence of trees. Each tree i is described by the esthetic appeal ai — some trees are very esthetically 
pleasing, others are 'so-so', and some trees are positively ugly!

The Smart Beaver calculated that he needed the following effects to win the Beaverette's heart:

The first objective is to please the Beaverette: the sum of esthetic appeal of the remaining trees must be maximum possible;
the second objective is to surprise the Beaverette: the esthetic appeal of the first and the last trees in the resulting belt must be the same;
and of course, the walk should be successful: there must be at least two trees in the woodland belt left.
Now help the Smart Beaver! Which trees does he need to cut down to win the Beaverette's heart?

Input
The first line contains a single integer n — the initial number of trees in the woodland belt, 2 ≤ n. The second line contains space-separated 
integers ai — the esthetic appeals of each tree. All esthetic appeals do not exceed 109 in their absolute value.

to get 30 points, you need to solve the problem with constraints: n ≤ 100 (subproblem A1);
to get 100 points, you need to solve the problem with constraints: n ≤ 3·105 (subproblems A1+A2).
Output
In the first line print two integers — the total esthetic appeal of the woodland belt after the Smart Beaver's intervention and the number of 
the cut down trees k.

In the next line print k integers — the numbers of the trees the Beaver needs to cut down. Assume that the trees are numbered from 1 to n from 
left to right.

If there are multiple solutions, print any of them. It is guaranteed that at least two trees have equal esthetic appeal.*/

#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, i, j, count;
    cin >> n;

    int *trees = new int [n];
    int **astheticTrees = new int* [n];
    for ( i = 0 ; i < n ; i++)
        astheticTrees[i] = new int [4];

    for (i = 0 ; i < n ; i++)
        cin>> trees[i];
    count = 0;


    for ( i = 0 ; i < n ; i++)
    {astheticTrees[i][0] = astheticTrees[i][1] = trees[i];
        astheticTrees[i][2] = 0;
        for( j = i+1 ; j < n ; j++ )
        {
            if(trees[i]>=0)
            {
                if(trees[j] != trees[i] && trees[j] >= 0)
                {
                    astheticTrees[i][1] += trees[j];
                }
                else if ( trees[j] == trees[i] )
                {
                    astheticTrees[i][2] = trees[j] + astheticTrees[i][1];
                    astheticTrees[i][1] += trees[j] ;
                    astheticTrees[i][3] = j;
                }
            } 
            else
            {
                if ( trees[j] == trees[i] )
                {
                    astheticTrees[i][2] = trees[j] + astheticTrees[i][1];
                    astheticTrees[i][1] += trees[j] ;
                    astheticTrees[i][3] = j;
                }
            }        
        }
        //cout << "i: " << i << " " << astheticTrees[i][0] << " " << astheticTrees[i][1] << " " << astheticTrees[i][2] << " " << astheticTrees[i][3] << endl;
    }

    int index = 0, max=-2147483648;
    cout << max << endl;
    //cout << index << endl;
    for ( i = 0 ; i< n ; i++ )
    {
        if( max < astheticTrees[i][2] && astheticTrees[i][3] != 0 )
        {
            index = i;
            max = astheticTrees[i][2];
        }
    }
    //cout << index << " " << astheticTrees[index][0] << " " << astheticTrees[index][1] << " " << astheticTrees[index][2] << " " << astheticTrees[index][3] << " " << endl;
    int *list = new int [n];
    count = j = 0;
    if(max>=0)
    {
        for ( i = 0 ; i < n ; i++)
        {
            if( i<index || i > astheticTrees[index][3] )
            {

                list[j++] = i+1;
                count++;
            }
            else if( ( i > index && i < astheticTrees[index][3]) && trees[i] < 0 )
            {
                list[j++] = i+1;
                count++ ;
            }
        }
    }
    else
    {
        for (i = 0 ; i < n ; i++)
        {
            if(i < index)
            {
                list[j++] = i+1;
                count++;
            }
            else if(i > index && i < astheticTrees[index][3])
            {
                list[j++] = i+1;
                count++;
            }
            else if( i > astheticTrees[index][3])
            {
                list[j++] = i+1;
                count++;
            }
        }
    }
    cout << max << " " << count << endl;
    for ( i = 0 ; i< count; i++)
        cout << list[i] << " " ;

}