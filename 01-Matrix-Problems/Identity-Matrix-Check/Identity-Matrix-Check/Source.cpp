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

bool IsIdentityMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

int main()
{
    int matrix[3][3] =
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    PrintMatrix(matrix, 3, 3);

    if (IsIdentityMatrix(matrix, 3, 3))
        cout << "\nYes: This is an identity matrix.";
    else
        cout << "\nNo: This is not an identity matrix.";

    return 0;
}