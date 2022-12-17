/*A. Heroes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The year of 2012 is coming...

According to an ancient choradrican legend in this very year, in 2012, Diablo and his brothers Mephisto and Baal 
will escape from hell, and innumerable hordes of demons will enslave the human world.
 But seven brave heroes have already gathered on the top of a mountain Arreat to protect us mere mortals 
 from the effect of this terrible evil.

The seven great heroes are: amazon Anka, barbarian Chapay, sorceress Cleo, druid Troll, necromancer Dracul,
 paladin Snowy and a professional hit girl Hexadecimal. Heroes already know how much experience will be given 
 for each of the three megabosses: a for Mephisto, b for Diablo and c for Baal.

Here's the problem: heroes are as much as seven and megabosses are only three! Then our heroes decided to
 split into three teams, where each team will go to destroy their own megaboss. Each team member will receive a 
  of experience, rounded down, where x will be the amount of experience for the killed megaboss and y — the number
   of people in the team.

Heroes do not want to hurt each other's feelings, so they want to split into teams so that the difference between 
the hero who received the maximum number of experience and the hero who received the minimum number of experience
 were minimal. Since there can be several divisions into teams, then you need to find the one in which the total
  amount of liking in teams were maximum.

It is known that some heroes like others. But if hero p likes hero q, this does not mean that the hero q likes
 hero p. No hero likes himself.

The total amount of liking in teams is the amount of ordered pairs (p, q), such that heroes p and q are in the
 same group, and hero p likes hero q (but it is not important if hero q likes hero p). In case of heroes p and q
  likes each other and they are in the same group, this pair should be counted twice, as (p, q) and (q, p).

A team can consist even of a single hero, but it is important that every megaboss was destroyed. All heroes must
 be involved in the campaign against evil. None of the heroes can be in more than one team.

It is guaranteed that every hero is able to destroy any megaboss alone.

Input
The first line contains a single non-negative integer n (0 ≤ n ≤ 42) — amount of liking between the heroes.
 Next n lines describe liking in the form "p likes q", meaning that the hero p likes the hero q (p  ≠  q).
  Every liking is described in the input exactly once, no hero likes himself.

In the last line are given three integers a, b and c (1 ≤ a, b, c ≤ 2·109), separated by spaces: the experience
 for Mephisto, the experience for Diablo and experience for Baal.

In all the pretests, except for examples from the statement, the following condition is satisfied: a = b = c.

Output
Print two integers — the minimal difference in the experience between two heroes who will receive the maximum and
 minimum number of experience points, and the maximal total amount of liking in teams (the number of friendships
  between heroes that end up in one team).

When calculating the second answer, the team division should satisfy the difference-minimizing contraint. 
I.e. primary you should minimize the difference in the experience and secondary you should maximize the total 
amount of liking.*/

#include <iostream>
#include <cmath>
using namespace std;

string list[7],heros[7];
int n, maxLikings = 0;

void find_likings(string **str,string *list, int *team, int depth)
{
    int i,j,k,count=0;
    for(j = 0; j < 7 ; j++)
    {
        int flag = 0;
        for( k = 0; k < depth; k++)
        {
            if(heros[j] == list[k])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        list[depth++]=heros[j];
    }
    //for ( int l = 0; l < 7; l++)
            //cout << list[l] << " ";
        //cout << endl;

    /*for( i = 0; i< n; i++)
    {
        for( j = 0; j < team[0]; j++)
    }*/
    for( i = 0 ; i < n ; i++ )
    {
        for( j = 0 ; j < team[0] ; j++ )
        {
            for( k = 0 ; k < team[0]; k++)
            {
                if( str[0][i] == list[j] && str[1][i] == list[k] )
                {
                    //cout << " :" << list[j] << "->" << list[k];
                    count ++;
                }
            }
        }
    }
    
    for( i = 0 ; i < n ; i++ )
    {
        for( j = team[0] ; j < team[0]+team[1] ; j++ )
        {
            for( k = team[0] ; k < team[0]+team[1] ; k++)
            {
                if( str[0][i] == list[j] && str[1][i] == list[k] )
                {
                    //cout << " :" << list[j] << "->" << list[k];
                    count ++;
                }
            }
        }
    }
    
    for( i = 0 ; i < n ; i++ )
    {
        for( j = team[0]+team[1] ; j < 7 ; j++ )
        {
            for( k = team[0]+team[1] ; k < 7 ; k++)
            {
                if( str[0][i] == list[j] && str[1][i] == list[k] )
                {
                    //cout << " :" << list[j] << "->" << list[k];
                    count ++;
                }
            }
        }
    }
    //cout << " :" << count << endl;

    if( maxLikings < count)
        maxLikings = count;
    
}

void permutation_team2( string **str,int *team, int i, int depth )
{
    if( depth == team[0]+team[1] )
    {
        //cout << "Returing." ;
        /*for ( int l = 0; l < team[2]+team[1] ; l++)
            cout << list[l] << " ";
        cout << endl;*/
        find_likings(str,list,team,depth);
        return;
    }
    else
    {
        for(int j = i; j < team[2]+team[1]+team[0]; j++)
        {
            //cout << " In for: ";
            int flag = 0;
            for(int k = 0; k < depth ; k++ )
            {
                //cout << list[k] << " " ;
                if( list[k] == heros[j] )
                {
                    flag = 1;
                    break;
                }
            }
            //cout << endl ;
            if ( flag == 0)
            {
                list[depth] = heros[j];
                permutation_team2(str,team, j+1, depth+1);
            }
        }
    }
}

void permutation_team1(string **str,int *team, int i,int depth)
{
    if( depth == team[0] )
    {
        //cout << "Returing." ;
        //for ( int l = 0; l < team[2] ; l++)
        //    cout << list[l] << " ";
            
        permutation_team2(str,team, 0, depth);
        //cout << endl;
        return;
    }
    else
    {
        for(int j = i; j < team[2]+team[1]+team[0]; j++)
        {
            //cout << " In for: ";
            int flag = 0;
            for(int k = 0; k < depth ; k++ )
            {
                //cout << list[k] << " " ;
                if( list[k] == heros[j] )
                {
                    flag = 1;
                    break;
                }
            }
            //cout << endl ;
            if ( flag == 0)
            {
                list[depth] = heros[j];
                permutation_team1(str,team, j+1, depth+1);
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i;
    int arr[3], team[3], score[3];
    cin >> n;
    string *str[2];
    string temp;
    str[0] = new string[n];
    str[1] = new string[n];
    heros[0] = "Anka";
    heros[1] = "Chapay";
    heros[2] = "Cleo";
    heros[3] = "Troll";
    heros[4] = "Dracul";
    heros[5] = "Snowy";
    heros[6] = "Hexadecimal";

    for ( i = 0; i < n; i++ )
    {
        cin >> str[0][i];
        cin >> temp;
        cin >> str[1][i];
    }
    cin >> arr[0] >> arr[1] >> arr[2];
    /*for ( i = 0; i < n; i++ )
    {
        cout << str[0][i] << " ";
        cout << str[1][i] << endl;
    }*/
    //cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    for ( i = 0 ; i< 3; i++)
    {
        for ( int j = 0; j< 2; j++)
            if( arr[j] > arr[j+1] )
            {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
    }
    //cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    int totalStrangth = arr[0] + arr[1] + arr[2]; 
    
    float teamMember;

    teamMember = ((float)arr[0]/(totalStrangth))*7;
    //cout << teamMember << endl;
    if( teamMember - floor(teamMember) >= 0.49  )    
        team[0] = ceil(teamMember);
    else if ( floor(teamMember) == 0)
        team[0] = 1;
    else
        team[0] = floor(teamMember);
    teamMember = ((float)arr[1]/(totalStrangth))*7;
    if( teamMember - floor(teamMember) >= 0.49  )    
        team[1] = ceil(teamMember);
    else if ( floor(teamMember) == 0)
        team[1] = 1;
    else
        team[1] = floor(teamMember);
    team[2] = 7 - team[0]- team[1];
    
    for( i = 0; i < 3; i++)
        score[i] = arr[i]/team[i];
    //cout << team[0] << " " << team[1] << " " << team[2] << endl;
    //cout << score[0] << " " << score[1] << " " << score[2] << endl;

    for ( i = 0 ; i< 3; i++)
        for ( int j = 0; j < 2; j++)
            if(score[j] > score[j+1])
            {
                score[j] = score[j] + score[j+1];
                score[j+1] = score[j] - score[j+1];
                score[j] = score[j] - score[j+1];
            }
    cout << abs(score[0] - score[2]) ;
    permutation_team1(str,team, 0, 0);
    cout << " " << maxLikings;
}