/*A. Football
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya decided to have a look at the results of Berland 1910 Football Championship’s finals. 
Unfortunately he didn't find the overall score of the match; however, he got hold of a profound 
description of the match's process. On the whole there are n lines in that description each of which 
described one goal. Every goal was marked with the name of the team that had scored it. Help Vasya, 
learn the name of the team that won the finals. It is guaranteed that the match did not end in a tie.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of lines in the description. 
Then follow n lines — for each goal the names of the teams that scored it. The names are non-empty 
lines consisting of uppercase Latin letters whose lengths do not exceed 10 symbols. It is guaranteed 
that the match did not end in a tie and the description contains no more than two different teams.

Output
Print the name of the winning team. We remind you that in football the team that scores more goals is considered the winner.*/

#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i, n, team1_score = 0, team2_score = 0;
    cin >> n;
    string team_1, team_2;
    string * teamScores = new string[n];

    for ( i=0 ; i<n ; i++ )
    {
        cin >> teamScores[i];

        if ( i == 0)
        {
            team_1 = teamScores[i];
            team1_score++;
        }
        else if (team_1 == teamScores[i])
            team1_score++;
        else
        {
            team_2 = teamScores[i];
            team2_score++;
        }
    }
    //cout << team_1 << " " << team_2 << endl;
    if( team1_score > team2_score )
        cout << team_1;
    else if( team2_score > team1_score)
        cout << team_2;

}