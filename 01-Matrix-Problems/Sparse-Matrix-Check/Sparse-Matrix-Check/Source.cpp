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

bool IsSparseMatrix(const int matrix[3][3], short rows, short cols)
{
    int zeroCount = 0;
    int totalCount = rows * cols;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
                zeroCount++;
        }
    }

    return zeroCount > totalCount / 2;
}

int main()
{
    int matrix[3][3] =
    {
        {2, 0, 0},
        {0, 1, 0},
        {0, 0, 2}
    };

    PrintMatrix(matrix, 3, 3);

    if (IsSparseMatrix(matrix, 3, 3))
        cout << "\nYes: This is a sparse matrix.";
    else
        cout << "\nNo: This is not a sparse matrix.";

    return 0;
}