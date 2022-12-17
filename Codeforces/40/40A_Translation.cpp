/*A. Translation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The translation from the Berland language into the Birland language is not an easy task. 
Those languages are very similar: a berlandish word differs from a birlandish word with
the same meaning a little: it is spelled (and pronounced) reversely. For example,
 a Berlandish word code corresponds to a Birlandish word edoc. However, it's easy to make a mistake 
 during the «translation». Vasya translated word s from Berlandish into Birlandish as t. 
 Help him: find out if he translated the word correctly.

Input
The first line contains word s, the second line contains word t. The words consist of lowercase Latin letters.
 The input data do not consist unnecessary spaces. The words are not empty and their lengths do not exceed 100 symbols.

Output
If the word t is a word s, written reversely, print YES, otherwise print NO.*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string Berland, Birland;
    cin >> Berland >> Birland;
    int i,j, length1, length2, flag = 0;
    length1 = Berland.length();
    length2 = Birland.length();
    //cout<< length1 << " " << length2 << endl;
    if( length1 != length2)
        cout << "NO";
    else
    {
        j = length1-1;
        for( i = 0; i < length1; i++)
        {
            if(Berland[i] != Birland[j])
            {
                //cout << Berland[i] << Birland[j];
                flag = 1;
                break;
            }
            j--;
        }
        if (flag == 0)
            cout << "YES";
        else
            cout << "NO";
        }
}