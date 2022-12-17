#include <iostream>
#include <sstream>
#include <ctype.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,i=0,num;
	cin >> n;
	unsigned long long int* arr = new unsigned long long[n];
	unsigned long long int* arrReverse = new unsigned long long[n];
	char* ch = new char[n];
	char* chReverse = new char[n];

	int* list = new int[n];
	string rawInput,t;
	string chararr[2];
	getline(cin, rawInput);

	while (i < n)
	{
		getline(cin, rawInput);
		stringstream myString(rawInput);
		int j = -1;
		while (getline(myString,t, ' '))
			chararr[++j] = t;
		
		ch[i] = chararr[0][0];
		if (j > 0)
			arr[i++] = stoull(chararr[1],nullptr,0);
		else
			arr[i++] = 0;
	}
    cout<<n;
}