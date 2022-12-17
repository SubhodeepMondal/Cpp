#include <iostream>
#include <string>

void main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    std::string str;
    std::cin >> str;
    std::cout << str;
}
