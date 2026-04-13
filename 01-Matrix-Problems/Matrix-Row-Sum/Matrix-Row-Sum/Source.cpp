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
            matrix[i][j] = GenerateRandomNumber(1, 100);
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

int CalculateRowSum(const int matrix[3][3], short rowIndex, short cols)
{
    int sum = 0;
    for (short j = 0; j < cols; j++)
    {
        sum += matrix[rowIndex][j];
    }
    return sum;
}

void PrintRowSums(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << CalculateRowSum(matrix, i, cols) << '\n';
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int matrix[3][3];

    FillMatrix(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintRowSums(matrix, 3, 3);

    return 0;
}