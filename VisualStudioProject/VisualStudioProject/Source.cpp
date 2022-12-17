
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

    int i = 0, j = 0, n;
    string rawInput, temp;
    int** vartexValue, ** edges;
    cin >> n;
    vartexValue = new int* [n];
    edges = new int* [n];
    int* testCases = new int[n];

    while (i < n)
    {
        cin >> testCases[i];
        while (j < testCases[i])
        {
            vartexValue[i] = new int[testCases[i]];
            getline(cin, rawInput);
            stringstream myString(rawInput);
            int k = 0;
            while (getline(myString, temp, ' '))
                vartexValue[i][k++] = (int)stoul(temp, nullptr, 0);
            j++;
        }
        j = 0;
        while (j < testCases[i] - 1)
        {
            edges[i] = new int[testCases[i]];
            getline(cin, rawInput);
            stringstream myString(rawInput);
            int k = 0;
            while (getline(myString, temp, ' '))
                edges[i][k++] = (int)stoul(temp, nullptr, 0);
            j++;
        }
    }
    cout << testCases[0];
    for (i = 0; i < testCases[0]; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << vartexValue[i][j] << " " << edges[i][j];
        }
    }
    return 0;


}