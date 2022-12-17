/*C. Email address
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sometimes one has to spell email addresses over the phone. Then one usually pronounces a dot as dot,
 an at sign as at. As a result, we get something like vasyaatgmaildotcom. Your task is to transform
  it into a proper email address (vasya@gmail.com).

It is known that a proper email address contains only such symbols as . @ and lower-case Latin letters, 
doesn't start with and doesn't end with a dot. Also, a proper email address doesn't start with and doesn't 
end with an at sign. Moreover, an email address contains exactly one such symbol as @, yet may contain any
 number (possible, zero) of dots.

You have to carry out a series of replacements so that the length of the result was as short as possible and
 it was a proper email address. If the lengths are equal, you should print the lexicographically minimal result.

Overall, two variants of replacement are possible: dot can be replaced by a dot, at can be replaced by an at.

Input
The first line contains the email address description. It is guaranteed that that is a proper email address with
 all the dots replaced by dot an the at signs replaced by at. The line is not empty and its length does not exceed
  100 symbols.

Output
Print the shortest email address, from which the given line could be made by the described above replacements.
 If there are several solutions to that problem, print the lexicographically minimal one (the lexicographical
  comparison of the lines are implemented with an operator < in modern programming languages).

In the ASCII table the symbols go in this order: . @ ab...z*/

#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    #endif

    string emailAddress;
    cin >> emailAddress;
    
    char *transformedEmailAddress = new char[emailAddress.length()];
    int i, j, k,count,flagAt= 0;
    i = j = k = count = 0;
    //cout << emailAddress.length() << endl;
    //cout << emailAddress << " " << i <<" " << j << " " << k << endl;
    while ( i < emailAddress.length() )
    {
        int flag = 0;
        //cout << emailAddress[i] << " " ;
        if( emailAddress[i] == 'd' && i != 0 && i != emailAddress.length() - 3)
        {
            i++;
            if( emailAddress[i] == 'o' )
            {
                i++;
                if( emailAddress[i] == 't' )
                {
                    //cout << "1st if : "<< emailAddress[i] <<" " ;
                    transformedEmailAddress[j++] = 46;
                    //cout << transformedEmailAddress[j++];
                    flag = 1;
                    count++;
                }
                else
                    i = k;
            }
            else
                i = k;
        }
        if ( emailAddress[i] == 'a' && i != emailAddress.length() - 2  && i != 0 && flagAt ==0 )
        {
            i++;
            if( emailAddress[i] == 't' )
            {
                //cout << "2nd else if" << emailAddress[i] <<" " ;
                transformedEmailAddress[j++] = 64;
                //cout << transformedEmailAddress[j++] << endl;
                flag = 1;
                flagAt = 1;
                count++;
            }
            else 
                i = k;
        }
        if (flag == 0)
        {
            //cout << "3rd else if : " ;
            transformedEmailAddress[j++] = emailAddress[k];
            //cout << transformedEmailAddress[j++] << endl;
            count++;
            i = k;
        }
        i++;
        k = i;
        //cout << i << endl;
    }
    for ( i = 0; i < count ; i++)
        cout << transformedEmailAddress[i] ;
}