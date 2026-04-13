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

int CalculateColumnSum(const int matrix[3][3], short colIndex, short rows)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colIndex];
    }
    return sum;
}

void PrintColumnSums(const int matrix[3][3], short rows, short cols)
{
    for (short j = 0; j < cols; j++)
    {
        cout << "Column " << j + 1 << " Sum = " << CalculateColumnSum(matrix, j, rows) << '\n';
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int matrix[3][3];

    FillMatrix(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintColumnSums(matrix, 3, 3);

    return 0;
}