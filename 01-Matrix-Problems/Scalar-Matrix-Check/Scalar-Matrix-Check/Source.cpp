#include <iostream>
#include <iomanip>

using namespace std;

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

bool IsScalarMatrix(const int matrix[3][3], short rows, short cols)
{
    int diagonalValue = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if ((i == j && matrix[i][j] != diagonalValue) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

int main()
{
    int matrix[3][3] =
    {
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    };

    PrintMatrix(matrix, 3, 3);

    if (IsScalarMatrix(matrix, 3, 3))
        cout << "\nYes: This is a scalar matrix.";
    else
        cout << "\nNo: This is not a scalar matrix.";

    return 0;
}