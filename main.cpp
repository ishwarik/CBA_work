#include <iostream>
using namespace std;

int main()
{
    int n=12345, remainder,reversedNumber;

    

    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }

    cout << "Reversed Number = " << reversedNumber;

    return 0;
}
