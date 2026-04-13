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

bool IsNumberInMatrix(const int matrix[3][3], int number, short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == number)
                return true;
        }
    }
    return false;
}

void PrintCommonValues(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            int current = matrix1[i][j];
            if (IsNumberInMatrix(matrix2, current, rows, cols))
            {
                cout << setw(4) << current << ' ';
            }
        }
    }
    cout << '\n';
}

int main()
{
    int matrix1[3][3] =
    {
        {4, 6, 12},
        {9, 5, 2},
        {0, 3, 49}
    };

    int matrix2[3][3] =
    {
        {0, 2, 12},
        {49, 5, 1},
        {5, 3, 3}
    };

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "Matrix 2:\n";
    PrintMatrix(matrix2, 3, 3);

    cout << "\nCommon Values: ";
    PrintCommonValues(matrix1, matrix2, 3, 3);

    return 0;
}