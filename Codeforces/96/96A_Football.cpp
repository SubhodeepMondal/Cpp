/*A. Football
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".*/

#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    string playersStanding;
    cin>>playersStanding;
//    cout<<playersStanding;
    int flag =0,count= 1;
    char prev_ch;
    prev_ch = playersStanding[0];
    for(int i = 1; i<playersStanding.length();i++)
    {
        if(prev_ch == playersStanding[i])
        {
            count++;
            if(count==7)
            {
                flag= 1;
                break;
            }
        }
        else
        {
            prev_ch = playersStanding[i];
            count = 1;
        }
    }
    if(flag == 1)
        cout<<"YES";
    else
        cout<<"NO";
}