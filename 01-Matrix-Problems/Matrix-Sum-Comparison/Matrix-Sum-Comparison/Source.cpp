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
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }
}

int SumMatrix(const int matrix[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrix(matrix1, 3, 3);
    FillMatrix(matrix2, 3, 3);

    PrintMatrix(matrix1, 3, 3);
    cout << "-------------\n";
    PrintMatrix(matrix2, 3, 3);

    int sum1 = SumMatrix(matrix1, 3, 3);
    int sum2 = SumMatrix(matrix2, 3, 3);

    cout << "\nSum of Matrix 1 = " << sum1;
    cout << "\nSum of Matrix 2 = " << sum2;
    cout << "\n-------------\n";

    if (sum1 == sum2)
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}