/*B. Plane of Tanks: Pro
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has been playing Plane of Tanks with his friends the whole year. 
Now it is time to divide the participants into several categories depending on their results.

A player is given a non-negative integer number of points in each round of the Plane of Tanks.
Vasya wrote results for each round of the last year. He has n records in total.

In order to determine a player's category consider the best result obtained by the player and the best
results of other players. The player belongs to category:

"noob" — if more than 50% of players have better results;
"random" — if his result is not worse than the result that 50% of players have, but more than 20% of players 
have better results;
"average" — if his result is not worse than the result that 80% of players have, but more than 10% of players 
have better results;
"hardcore" — if his result is not worse than the result that 90% of players have, but more than 1% of players 
have better results;
"pro" — if his result is not worse than the result that 99% of players have.
When the percentage is calculated the player himself is taken into account. 
That means that if two players played the game and the first one gained 100 points and the second one 1000 points, 
then the first player's result is not worse than the result that 50% of players have, and the second one is not worse than the result that 100% of players have.

Vasya gave you the last year Plane of Tanks results. Help Vasya determine each player's category.

Input
The first line contains the only integer number n (1 ≤ n ≤ 1000) — a number of records with the players' results.

Each of the next n lines contains a player's name and the amount of points, obtained by the player for the round, separated with a space. 
The name contains not less than 1 and no more than 10 characters. The name consists of lowercase Latin letters only. 
It is guaranteed that any two different players have different names. The amount of points, obtained by the player for the round, 
is a non-negative integer number and does not exceed 1000.

Output
Print on the first line the number m — the number of players, who participated in one round at least.

Each one of the next m lines should contain a player name and a category he belongs to, separated with space. Category can be one of the following: 
"noob", "random", "average", "hardcore" or "pro" (without quotes). The name of each player should be printed only once. 
Player names with respective categories can be printed in an arbitrary order.*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,i,numOfPlayer,j,k=0,flag = 0;
    cin>>n;
    string *playersName = new string[n];
    string *finalPlayersName = new string[n];
    int *playersScore = new int[n];
    int *finalPlayersScore = new int[n];
    for (i = 0; i<n; i++)
    {
        cin>> playersName[i] >> playersScore[i];
    }
    for (i = 0; i<n ; i++)
    {
        flag = 0;
        for (j = i+1; j<n; j++)
        {
            if(playersName[i] != "NULL")
            {
                if(playersName[i] == playersName[j])
                {
                    flag = 1;
                    playersName[j] = "NULL";
                    if(playersScore[i] > playersScore[j])
                        finalPlayersScore[k] = playersScore[i];
                    else
                        finalPlayersScore[k] = playersScore[j];
                }
            }    
        }
        if(flag == 1)
            finalPlayersName[k++] = playersName[i];
        else if(flag == 0 && playersName[i] != "NULL" )
        {    
            finalPlayersName[k] = playersName[i];
            finalPlayersScore[k++] = playersScore[i];
        }
    }
    numOfPlayer = k;
    for( i=0 ; i < numOfPlayer  ; i++)
    {
        string tempPlayerName;
        int tempScore;
        for ( j = 0 ; j < numOfPlayer - i - 1 ; j++)
        {
            if(finalPlayersName[j] > finalPlayersName[j+1])
            {
                tempPlayerName = finalPlayersName[j];
                tempScore = finalPlayersScore[j];
                finalPlayersName[j] = finalPlayersName[j+1];
                finalPlayersScore[j] = finalPlayersScore[j+1];
                finalPlayersName[j+1] = tempPlayerName;
                finalPlayersScore[j+1] = tempScore;
            }
        }
        //cout << finalPlayersName[numOfPlayer-i-1] << " " << finalPlayersScore[numOfPlayer-i-1] << " " << numOfPlayer-i-1 << endl;
    }
    //cout << finalPlayersName[i] << " " << finalPlayersScore[i] << endl;
    
    string *playersRemark = new string[numOfPlayer];
    float * playersBetterPerecentage = new float[numOfPlayer];
    float * playersWorstPerecentage = new float[numOfPlayer];

    for ( i=0 ; i < numOfPlayer ; i++)
    {
        int better = 0, worst = 0;
        for ( j = 0 ; j < numOfPlayer ; j++)
        {
            if( finalPlayersScore[i] >= finalPlayersScore[j] )
                better++;
            else if( finalPlayersScore[i] < finalPlayersScore[j] )
                worst++;
        } 
        //cout<< better << " " << worst << endl;
        playersBetterPerecentage[i] = ((float)better/(better+worst)) * 100;
        playersWorstPerecentage[i] = ((float)worst/(better+worst)) * 100;
        //cout << playersBetterPerecentage[i] << " " << playersWorstPerecentage[i] << endl;

    }
    cout << numOfPlayer << endl;
    for( i=0 ; i < numOfPlayer ; i++)
    {
        if(playersWorstPerecentage[i] > 50)
            cout << finalPlayersName[i] << " noob" << endl;
        else if(playersBetterPerecentage[i] >= 50 && playersWorstPerecentage[i] > 20 )
            cout << finalPlayersName[i] << " random" << endl;
        else if(playersBetterPerecentage[i] >= 80 && playersWorstPerecentage[i] > 10 )
            cout << finalPlayersName[i] << " average" << endl;
        else if(playersBetterPerecentage[i] >= 90 && playersWorstPerecentage[i] > 1 )
            cout << finalPlayersName[i] << " hardcore" << endl;
        else if(playersBetterPerecentage[i] > 99 )
            cout << finalPlayersName[i] << " pro" << endl;
    }
    return 0;
}
