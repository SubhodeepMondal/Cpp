#include<iostream>
using namespace std;
class Queue 
{
    int *a, n, head, tail;
    
    public:
        Queue(int x)
        {
            n = x;
            a = new int[n];
            head = tail = 0;
        }
        void enQueue(int x)
        {
            if(head == (tail+1)%n )
                cout << "Error! Queue Overflow." << endl;
            else
            {
                a[tail++]=x;
                tail %= n;
                cout << tail << endl;
            }
        }
        int deQueue()
        {
            int x;
            if(tail==head)
            {
                cout << "Error! Queue is Empty." << endl;
                return '\0';
            }
                
            else
            {
                x = a[head++];
                head %= n;
                return x;                
            }
        }
};
int main()
{
    int n,i,j;
    cout << "Enter size of the Queue:" << endl;
    cin >> n;
    Queue queue(n);
    while(i)
    {
        cout << "0. To quit\n1. To enqueue\n2. to dequeue:\n";
        cin >> i;
        switch (i)
        {
        case /* constant-expression */ 0:
            /* code */
            break;
        case 1:
            cout << "Enter the value:" << endl;
            cin >> j;
            queue.enQueue(j);
            break;
        case 2:
            j = queue.deQueue();
            cout << "The value is: " << j << endl;
            break;       
        default:
            i = 0;
            break;
        }
    }
}