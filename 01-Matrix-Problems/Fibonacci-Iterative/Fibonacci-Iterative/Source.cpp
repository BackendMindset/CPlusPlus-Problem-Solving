#include <iostream>

using namespace std;

void PrintFibonacciUsingLoop(short number)
{
    if (number <= 0)
        return;

    long long prev = 0, current = 1, next = 0;

    cout << prev << "  ";
    if (number == 1)
        return;

    cout << current << "  ";

    for (short i = 3; i <= number; i++)
    {
        next = prev + current;
        cout << next << "  ";
        prev = current;
        current = next;
    }
}

int main()
{
    PrintFibonacciUsingLoop(10);
    return 0;
}