/*D. Pawn
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
On some square in the lowest row of a chessboard a stands a pawn. It has only two variants of moving:
 upwards and leftwards or upwards and rightwards. The pawn can choose from which square of the lowest
  row it can start its journey. On each square lay from 0 to 9 peas. The pawn wants to reach the uppermost
   row having collected as many peas as possible. As there it will have to divide the peas between itself
    and its k brothers, the number of peas must be divisible by k + 1. Find the maximal number of peas it
     will be able to collect and which moves it should make to do it.

The pawn cannot throw peas away or leave the board. When a pawn appears in some square of the board (including
 the first and last square of the way), it necessarily takes all the peas.

Input
The first line contains three integers n, m, k (2 ≤ n, m ≤ 100, 0 ≤ k ≤ 10) — the number of rows and columns
 on the chessboard, the number of the pawn's brothers. Then follow n lines containing each m numbers from 0
  to 9 without spaces — the chessboard's description. Each square is described by one number — the number of
   peas in it. The first line corresponds to the uppermost row and the last line — to the lowest row.

Output
If it is impossible to reach the highest row having collected the number of peas divisible by k + 1, print -1.

Otherwise, the first line must contain a single number — the maximal number of peas the pawn can collect given
 that the number must be divisible by k + 1. The second line must contain a single number — the number of the
  square's column in the lowest row, from which the pawn must start its journey. The columns are numbered from
   the left to the right with integral numbers starting from 1. The third line must contain a line consisting
    of n - 1 symbols — the description of the pawn's moves. If the pawn must move upwards and leftwards, print L,
     if it must move upwards and rightwards, print R. If there are several solutions to that problem, print any of them.*/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, k,indDynMem=0;
int ** peaMatrix;
int maxPea = -1; 
int *subMax;
string maxPath ;
int intColumn ;

typedef struct subPawn
{
    int countPea, columnSub;
    string peaPath;
} subPawn;

void findPeas(int i, int j, int count, int column, char *str, int countforZero, int colZero, char *strZero,int ind,subPawn *pawn)
{
    if( i == (n-1) )
    {
        count += peaMatrix[i][j];
        countforZero += peaMatrix[i][j];
        if( count % (k+1) == 0 )
        {
            if(count > maxPea)
            {
                maxPea = count;
                maxPath = str;
                intColumn = column;
                //cout << maxPea << " " << intColumn << " " << maxPath << endl;
            }
        }
        if ( countforZero != 0 )
        {
            //cout << "(countforZero): " << colZero << " " << subMax[colZero] << " " << endl ;
            if( subMax[colZero] < countforZero )
            {
                pawn[colZero].countPea = countforZero;
                pawn[colZero].columnSub = colZero;
                pawn[colZero].peaPath = strZero;
                subMax[colZero] = countforZero;
                //cout << pawn[colZero].countPea << " " << pawn[colZero].columnSub << " " << pawn[colZero].peaPath << endl;
            }
        }
    }
    else
    {
        //For first row
        if( i == 0)
        {
            for(int a = j; a < m ; a++)
            {
                column = a;
                
                if( a > 0 )
                {
                    
                    str[i] = 'L';
                    
                    findPeas(i+1, a-1, count+peaMatrix[i][a], column, str, countforZero, colZero, strZero, ind,pawn);     
                }

                if( a < (m-1) )
                {
                    str[i] = 'R';
                    findPeas(i+1, a+1, count+peaMatrix[i][a], column, str, countforZero, colZero, strZero, ind, pawn);
                }
            }
        }
        
        // 2nd row to nth row
        else
        {
            if( column >= 2 && i == (n/2) )
            {
                maxPea = count + pawn[j].countPea;
                maxPath = str + pawn[j].peaPath;
                intColumn = column;
                return;
            }
            else
            {
                if( column < 2 && i >= (n/2) )
                {
                    if ( i == n/2 )
                        colZero = j;
                    countforZero += peaMatrix[i][j];
                    ind++;
                }
                if(j > 0)
                {
                    if( column < 2 && i >= (n/2) )
                    {
                        strZero[ind] = 'L'; 
                        cout << countforZero << " " << strZero << " " << colZero<< " " << ind << " " << i << " " << j <<endl;
                    }
                    str[i] = 'L';
                    findPeas(i+1, j-1, count+peaMatrix[i][j], column, str, countforZero, colZero, strZero, ind, pawn);
        
                }
                if( j < (m-1))
                {
                    if( column < 2 && i >= (n/2) )
                    {
                        strZero[ind] = 'R'; 
                        cout << countforZero << " " << strZero << " " << colZero<< " " << ind << " " << i << " " << j <<endl;
                    }
                    str[i] = 'R';
                    findPeas(i+1, j+1, count+peaMatrix[i][j], column, str, countforZero, colZero, strZero, ind, pawn);
                }
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
    char *strZero = new char[n/2];
    peaMatrix = new int* [n];
    subPawn *pawn = new subPawn[m];
    subMax = new int [m];
    //memset(subMax, 0, m);
    for (i = 0; i < m; i++)
    {
        subMax[i] = -1;
        //cout << i << " " << subMax[i] << " ";
    }
    //cout << endl;
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
    memset(strZero,0,n);
    findPeas(0,0,0,0,str,0,0,strZero,-1,pawn);
    if ( maxPea != -1 )
        cout << maxPea << endl << ( intColumn + 1) << endl << maxPath << endl;
    else
        cout << maxPea;
    //cout << indDynMem ;
    for(i = 0; i< m; i++)
        cout << pawn[i].countPea << " " << pawn[i].peaPath << " " << pawn[i].columnSub << endl;

} 