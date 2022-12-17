/*D. New Year's Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vlad has n friends, for each of whom he wants to buy one gift for the New Year.

There are m shops in the city, in each of which he can buy a gift for any of his friends. If the j-th friend
(1≤j≤n) receives a gift bought in the shop with the number i (1≤i≤m), then the friend receives pij units of
joy. The rectangular table pij is given in the input.

Vlad has time to visit at most n−1 shops (where n is the number of friends). He chooses which shops he will
visit and for which friends he will buy gifts in each of them.

Let the j-th friend receive aj units of joy from Vlad's gift. Let's find the value α=min{a1,a2,…,an}.
Vlad's goal is to buy gifts so that the value of α is as large as possible. In other words, Vlad wants
to maximize the minimum of the joys of his friends.

For example, let m=2, n=2. Let the joy from the gifts that we can buy in the first shop: p11=1, p12=2,
in the second shop: p21=3, p22=4.

Then it is enough for Vlad to go only to the second shop and buy a gift for the first friend, bringing joy 3,
and for the second — bringing joy 4. In this case, the value α will be equal to min{3,4}=3
Help Vlad choose gifts for his friends so that the value of α is as high as possible. Please note that
each friend must receive one gift. Vlad can visit at most n−1 shops (where n is the number of friends).
In the shop, he can buy any number of gifts.

Input
The first line of the input contains an integer t (1≤t≤10^4) — the number of test cases in the input.

An empty line is written before each test case. Then there is a line containing integers m and n
(2≤n, 2≤n⋅m≤10^5) separated by a space — the number of shops and the number of friends, where n⋅m is
the product of n and m.

Then m lines follow, each containing n numbers. The number in the i-th row of the j-th column pij
(1≤pij≤10^9) is the joy of the product intended for friend number j in shop number i.

It is guaranteed that the sum of the values n⋅m over all test cases in the test does not exceed 10^5.

Output
Print t lines, each line must contain the answer to the corresponding test case — the maximum possible
value of α, where α is the minimum of the joys from a gift for all of Vlad's friends.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct parameterPass
{
    int sum, maxShop, minDif,friendA,friendB;
    struct parameterPass *next;
}param;

class hashTable
{
    class node
    {
        public:
        int key;
        node* next;
    };
    node ** table;
    int size;
    public:
    hashTable(int n)
    {
        size = n;
        table = new node*[size];
        for(int i = 0; i<size; i++)
            table[i] = NULL;
    }
    
    void insert(int data, int keyPosition)
    {
        node *newNode = new node;
        newNode->key = data;
        newNode->next = NULL;
        if( table[keyPosition] == NULL )
        {
            table[keyPosition] = newNode;
        }
        else
        {
            node *ptr = table[keyPosition];
            while(ptr->next!=NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }

    }

    int search(int data)
    {
        int keyPosition = function(data);
        int flag = 0;
        node *ptr = table[keyPosition];
//        cout << ptr << " " << endl;

        while(ptr!=NULL)
        {
            if(ptr->key == data)
            {
                flag = 1;
                break;
            }
            else
                ptr = ptr->next;
        }

        if(flag==0)
            insert(data,keyPosition);

        return flag;
    }


    int function(int key)
    {
        return (key % 97);
    }
    ~hashTable()
    {
        delete [] table;
    }
};

class linkedList
{
    param *head;

    public:
    linkedList()
    {
        head = NULL;
    }

    void insert(param node)
    {
        param *newNode = new param;
        newNode->sum = node.sum;
        newNode->minDif = node.minDif;
        newNode->maxShop = node.maxShop;
        newNode->friendA = node.friendA;
        newNode->friendB = node.friendB;
        newNode->next = NULL;
        if(head == NULL)
            head = newNode;
        else
        {
            param * ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }
//        cout << newNode->friendA << " " << newNode->friendB << " " << newNode->sum << " " << newNode->minDif << " " << newNode->maxShop << " " << newNode->next << " "<< endl << endl;

    }

    param* searchMin()
    {
        param * ptr, *ret;
        ptr = ret = head;
        int mindef = ptr->minDif;
        int maxsum = ptr->sum;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            if(maxsum <= ptr->sum && mindef < ptr->minDif )
            {
                maxsum = ptr->sum;
                mindef = ptr->minDif;
                ret = ptr;
            }
        }
        return ret; 
    }

    void print()
    {
        param * ptr = head;
        while(ptr!=NULL)
        {
            cout << ptr->sum << " " << ptr->minDif << " " << ptr->maxShop << " " << ptr->friendA << " " << ptr->friendB << endl;
            ptr = ptr->next;
        }
    }
    ~linkedList()
    {
        delete [] head;
    }
    
};

param findMax(int j, int k, int m, int *minarr, int **a)
{
    int friendA = minarr[j];
    int friendB = minarr[k];
    param node;
    int max = 0, mindiff = 0,sum,dif;

    for( int i=0; i<m; i++ )
    {
        sum = a[i][friendA] + a[i][friendB];

        if(a[i][friendA]<a[i][friendB])
            dif = a[i][friendA];
        else
            dif = a[i][friendB];

//        cout << friendA << " " << friendB << " " << sum << " " << dif << endl;
        if( max<=sum && mindiff<dif )
        {
            max = sum;
            mindiff = dif;
            node.sum = sum;
            node.minDif = dif;
            node.maxShop = i;
            node.friendA = friendA;
            node.friendB = friendB;
//            cout << node.friendA << " " << node.friendB << " " << node.sum << " " << node.minDif << " " << node.maxShop << " " << endl;

        }
    }
//    cout << endl;
//    cout << node.friendA << " " << node.friendB << " " << node.sum << " " << node.minDif << " " << node.maxShop << " " << endl << endl;
    return node;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tCase, n, m, i, j,k;
    int max,min,mincount,maxShop,count=0,minFriend;
    int firstMin,secondMin;
    int *minArr;

    cin >> tCase;

    int **a,**b;

    for (i = 0; i < tCase; i++)
    {
        cin >> m >> n;
        a = new int*[m];
        b = new int*[n];

        for( j=0; j<n; j++ )
            b[j] = new int[2];

        for (j = 0; j < m; j++) // input for joy matrix;
        {
            a[j] = new int[n];
            for (k = 0; k < n; k++)
                cin >> a[j][k];
        }

        for( j=0; j<n; j++) // getting max joy gift for all friends
        {
            max = 0;
            for(k=0; k<m; k++)
            {
                if(a[k][j] > max)
                {
                    max = a[k][j];
                    maxShop = k;
                }      
            }
            b[j][0] = max;
            b[j][1] = maxShop;
        }
            
        //Counting no. of shop visited
        hashTable hashtable(97);
        count = 0;
        for(j = 0; j<n; j++) 
        {
            if(hashtable.search(b[j][1]) == 0)
            {
//                cout << b[j][1] << " ";
                count++;
            }
                
        }


//        cout << count << endl;
        // if we visited n no of shops
        if(count==n && n != 1)    
        {
            min = 1000000009;
            for(j = 0; j< n; j++) //find the first min no.
                if(min>b[j][0])
                    min = b[j][0];

            mincount = k= 0;
            minArr = new int[n];

            for( j=0; j<n; j++ ) // count no of first min
            {
                if(min == b[j][0])
                {
                    minArr[k++] = j;
                    mincount++;
                }
            }


            int secondMin = 1000000009;
            // find the second min
            for( j=0; j<n; j++ )    
            {
                if(b[j][0]>min && b[j][0]<secondMin)
                    secondMin = b[j][0];
            }
            // count second min no
            for( j=0; j<n; j++) 
            {
                if(b[j][0] == secondMin)
                {
                    minArr[k++] = j;
                    mincount++;
                }
            }
            
            // print minArr;
/*            for(j=0;j<mincount;j++)
                cout << minArr[j] << " ";
            cout << endl;*/

            //finding max joy shop for pair of 2 lowest joy friends
            param maxSum;
            max = 0;
            linkedList list;
            for( j=0; j<mincount -1; j++)
            {
                for( k=j+1; k<mincount; k++ )
                {
                    maxSum = findMax(j,k,m,minArr,a);
                    if(max<=maxSum.sum)
                    {
                        list.insert(maxSum);
                        max = maxSum.sum;
                    }
                }
            }

            list.print();

            //finding max joy min difference shop for friends
            param *ptr = list.searchMin();


            //transfering data to main 'b' array
            b[ptr->friendA][0] = a[ptr->maxShop][ptr->friendA];
            b[ptr->friendB][0] = a[ptr->maxShop][ptr->friendB];
            b[ptr->friendA][1] = b[ptr->friendB][1] = ptr->maxShop;
        } 

/*        for( j=0; j<n; j++)
            cout << b[j][0] << " " << b[j][1] << endl;
        cout << endl;*/
        
        min =1000000009;
        for(j = 0; j<n; j++)
        {
            if(min>b[j][0])
            {
                min = b[j][0];
                minFriend = j;
            }               
        }

        cout << min << endl;

        delete[] a;
        delete[] b;
    }
}