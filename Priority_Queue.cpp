#include <iostream>
#include <ctype.h>
#include <string>
#include <sstream>


using namespace std;

	
unsigned long long int sumFinal = 0;

int sumSequence(int depth, int* list, unsigned long long int* arr, char* ch) 
{

	unsigned long long sum = 0,acDepth=depth+1;
	unsigned long long* a = new unsigned long long[acDepth];
	char* c = new char[acDepth];
	for (int i = 0; i <= depth; i++) {
		a[i] = arr[list[i]];
		c[i] = ch[list[i]];
	}
	for (int i = 0; i <= depth; i++) {
		if (c[i] == '+') {
			sum = (sum % 998244353 + a[i] % 998244353) % 998244353;
		}
		else if (c[i] == '-') {
			unsigned long long int min = 998244353,index;
			for (int j = 0; j <= depth; j++) {
				if (min > a[j] && a[j] != 0) {
					min = a[j];
					index = j;
				}
			}
			if (min != 998244353)
				a[index] = 0;
		}
	}
	sumFinal = (sumFinal % 998244353 + sum % 998244353) % 998244353;
	delete[] a;
	delete[] c;
	return sum;
}

void subsequence(int i, int depth, int n, int* list, unsigned long long int* arr, char* ch)
{
	if (i == n)
		return;
	else
	{
		for (int j = i; j < n; j++)
		{
			list[depth] = j;
			for (int k = 0; k <= depth; k++) {
				cout << list[k] << " ";
			}

			cout << ":" << sumSequence(depth, list, arr, ch) << endl;
			subsequence(j + 1, depth + 1, n, list, arr, ch);
		}
	}
}

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
	int j = n - 1;
	for (i = 0; i < n; i++)
	{
		arrReverse[j] = arr[i];
		chReverse[j--] = ch[i];
	}
	for (i = 0; i < n; i++)
		cout << ch[i] << " " << arr[i]<<endl;
	subsequence(0, 0, n, list, arr, ch);
	cout << sumFinal << " " << sumFinal;

/*	sumFinal = 0;
	cout << endl << "Reverse:" << endl;
	for (i = 0; i < n; i++)
		cout << chReverse[i] << " " << arrReverse[i] << endl;
	subsequence(0, 0, n, list, arrReverse, chReverse);
	cout << sumFinal << " " << sumFinal % 998244353;*/
	return 0;
}