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

bool AreMatricesEqual(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
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

    if (AreMatricesEqual(matrix1, matrix2, 3, 3))
        cout << "\nYes: Matrices are equal.";
    else
        cout << "\nNo: Matrices are not equal.";

    return 0;
}