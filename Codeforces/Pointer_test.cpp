#include <iostream>
using namespace std;
int main()
{
    long  ptr,num;
    long  *digit;
    num = 29179191;
    ptr =(long) &num;
//    digit = (long *)ptr;

    cout << &num << endl;
    cout << ptr << endl;
    cout << *digit << endl;
}