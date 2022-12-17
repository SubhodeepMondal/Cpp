/*B. Letter
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya decided to write an anonymous letter cutting the letters out of a newspaper heading. 
He knows heading s1 and text s2 that he wants to send. Vasya can use every single heading 
letter no more than once. Vasya doesn't have to cut the spaces out of the heading — he just 
leaves some blank space to mark them. Help him; find out if he will manage to compose the needed text.

Input
The first line contains a newspaper heading s1. The second line contains the letter text s2. 
s1 и s2 are non-empty lines consisting of spaces, uppercase and lowercase Latin letters, 
whose lengths do not exceed 200 symbols. The uppercase and lowercase letters should be differentiated. 
Vasya does not cut spaces out of the heading.

Output
If Vasya can write the given anonymous letter, print YES, otherwise print NO*/

#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    int max_size = 200;
    string Heading, Text;

    getline(cin, Heading);
    getline(cin, Text);


    int i, j, lenText = Text.length(), lenHeading, flag = 0;
    //cout << Heading << endl << Text[5];
    //cout << Text.length() << endl;
    for ( i = 0; i < lenText; i++ )
    {
        if( Text[i] != ' '  )
        {    
            flag = 0;
            lenHeading = Heading.length();
            for ( int j = 0; j < lenHeading; j++)
            {
                if( Text[i] == Heading[j] )
                {
                    flag = 1;
                    Heading.erase(Heading.begin() + j);
                    break;
                }
            }
        }
        if ( flag == 0)
            break;

    }
    if(flag == 0)
        cout << "NO";
    else
        cout << "YES";

}