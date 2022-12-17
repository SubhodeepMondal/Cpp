/*D. Pawn
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
On some square in the lowest row of a chessboard a stands a pawn. It has only two variants of moving:
 upwards and leftwards or upwards and rightwards. The pawn can choose from which square of the lowest
  row it can start its journey. On each square lay from 0 to 9 peas. The pawn wants to reach the uppermost
   row having collected as many peas as possible. As there it will have to divide the peas between itself
    and its k brothers, the number of peas must be divisible by k?+?1. Find the maximal number of peas it
     will be able to collect and which moves it should make to do it.

The pawn cannot throw peas away or leave the board. When a pawn appears in some square of the board (including
 the first and last square of the way), it necessarily takes all the peas.

Input
The first line contains three integers n, m, k (2???n,?m???100,?0???k???10) — the number of rows and columns
 on the chessboard, the number of the pawn's brothers. Then follow n lines containing each m numbers from 0
  to 9 without spaces — the chessboard's description. Each square is described by one number — the number of
   peas in it. The first line corresponds to the uppermost row and the last line — to the lowest row.

Output
If it is impossible to reach the highest row having collected the number of peas divisible by k?+?1, print -1.

Otherwise, the first line must contain a single number — the maximal number of peas the pawn can collect given
 that the number must be divisible by k?+?1. The second line must contain a single number — the number of the
  square's column in the lowest row, from which the pawn must start its journey. The columns are numbered from
   the left to the right with integral numbers starting from 1. The third line must contain a line consisting
    of n?-?1 symbols — the description of the pawn's moves. If the pawn must move upwards and leftwards, print L,
     if it must move upwards and rightwards, print R. If there are several solutions to that problem, print any of them.*/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, k, index = -1;
int** peaMatrix;
int* storePea = new int[10000];
string* storePath = new string[10000];
int* intColumn = new int[10000];

void findPeas(int i, int j, int count, int column, char* str)
{
    if (i == (n - 1))
    {
        count += peaMatrix[i][j];
        if (count % (k + 1) == 0)
        {
            index++;
            storePea[index] = count;
            storePath[index] = str;
            intColumn[index] = column;
            //cout << "Final count(if): " << i << " " << j << " " << peaMatrix[i][j] << " " << count << " " << str << " " << column << endl;
        }
        else
        {
            index++;
            //cout << "Final count(else): " << i << " " << j << " " << peaMatrix[i][j] << " " << count << " " << str << " " << column << endl;
            storePea[index] = -1;
        }
    }
    else
    {
        if (i == 0)
        {
            for (int a = j; a < m; a++)
            {
                if (i == 0)
                    column = a;

                if (a > 0)
                {
                    //cout << "In for(a>0): L " << i << " " << a << " " << count << " " << peaMatrix[i][a] << " ";
                    str[i] = 'L';
                    findPeas(i + 1, a - 1, count + peaMatrix[i][a], column, str);

                }

                if (a  < (m-1))
                {
                    //cout << "In for(a<m): R " << i << " " << a << " " << count << " " << peaMatrix[i][a] << " ";
                    str[i] = 'R';
                    findPeas(i + 1, a + 1, count + peaMatrix[i][a], column, str);
                }
            }
        }
        else
        {
            if (j > 0)
            {
                //cout << "In for(j>0): L " << i << " " << j << " " << count << " " << peaMatrix[i][j] << " ";
                str[i] = 'L';
                findPeas(i + 1, j - 1, count + peaMatrix[i][j], column, str);
            }
            if (j  < (m-1))
            {
                //cout << "In for(j<m): R " << i << " " << j << " " << count << " " << peaMatrix[i][j] << " ";
                str[i] = 'R';
                findPeas(i + 1, j + 1, count + peaMatrix[i][j], column, str);
            }
        }
    }
}

int main()
{
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

    int i, j, l;
    cin >> n >> m >> k;
    char* str = new char[n];
    peaMatrix = new int* [n];
    l = n - 1;
    for (i = 0; i < n; i++)
    {
        peaMatrix[l] = new int[m];
        cin >> str;
        for (j = 0; j < m; j++)
            peaMatrix[l][j] = str[j] - '0';
        l--;
    }
    //cout << peaMatrix[0][2];
    memset(str, 0, n);
    findPeas(0, 0, 0, 0, str);
    int max = -2, id;
    for (i = 0; i <= index; i++)
    {
        if (max < storePea[i])
        {
            max = storePea[i];
            id = i;
        }
    }
    //cout << storePea[i] << " " << storePath[i] << " " << intColumn[i] << endl;*/
    if (max != -1)
    {
        cout << storePea[id] << endl << (intColumn[id] + 1) << endl << storePath[id];
    }
    else
    {
        cout << storePea[id];
    }
}