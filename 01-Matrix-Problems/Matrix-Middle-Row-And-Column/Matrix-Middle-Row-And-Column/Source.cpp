#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int GenerateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = GenerateRandomNumber(1, 10);
        }
    }
}

void PrintMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
        }
        cout << '\n';
    }
}

void PrintMiddleRowAndColumn(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == rows / 2 || j == cols / 2)
            {
                cout << setw(6) << matrix[i][j];
            }
            else
            {
                cout << setw(6) << ' ';
            }
        }
        cout << '\n';
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int matrix[3][3];

    FillMatrix(matrix, 3, 3);

    PrintMatrix(matrix, 3, 3);
    cout << "----------------\n";
    PrintMiddleRowAndColumn(matrix, 3, 3);

    return 0;
}