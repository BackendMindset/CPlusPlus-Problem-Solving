#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursion(short number, long long prev, long long current)
{
    if (number <= 0)
        return;

    long long next = prev + current;
    cout << next << "  ";

    PrintFibonacciUsingRecursion(number - 1, current, next);
}

int main()
{
    cout << "0  1  ";
    PrintFibonacciUsingRecursion(8, 0, 1);

    return 0;
}