#include <iostream>
#include <cstring>
using namespace std;
 
int n, m, k;
int ** peaMatrix;
int storePea = -1;
string storePath ;
int intColumn ;
 
void findPeas(int i, int j, int count, int column, char *str)
{
    if( i == (n-1) )
    {
        count += peaMatrix[i][j];
        if( count % (k+1) == 0 )
        {
            if(count>= storePea)
            {
                storePea = count;
                storePath = str;
                intColumn = column;
                //cout << storePea << endl;
            }
        }
    }
    else
    {
        if( i == 0)
        {
            for(int a = j; a < m ; a++)
            {
                column = a;
                
                if( a > 0 )
                {
                    str[i] = 'L';
                    findPeas(i+1, a-1, count+peaMatrix[i][a], column, str);     
                }
 
                if( a < (m-1) )
                {
                    str[i] = 'R';
                    findPeas(i+1, a+1, count+peaMatrix[i][a], column, str);
                }
            }
        }
        else
        {
            if(j > 0)
            {
                str[i] = 'L';
                findPeas(i+1,j-1,count+peaMatrix[i][j],column,str);
            }
            if( j < (m-1))
            {
                str[i] = 'R';
                findPeas(i+1, j+1, count+peaMatrix[i][j], column, str);
            }
        }
    }
}
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    #endif
 
    int i, j, l;
    cin >> n >> m >> k;
    char *str = new char[n];
    peaMatrix = new int* [n];
    l = n-1;
    for ( i = 0; i < n ; i++)
    {
        peaMatrix[l] = new int [m];
        cin >> str;
        for ( j = 0 ; j < m; j++)
            peaMatrix[l][j] = str[j] - '0';
        l--;
    }
    memset(str,0,n);
    findPeas(0,0,0,0,str);
    if ( storePea != -1 )
        cout << storePea << endl << ( intColumn + 1) << endl << storePath;
    else
        cout << storePea;
}