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

int GetIntersectedElements(const int matrix1[3][3], const int matrix2[3][3], int result[9], short rows, short cols)
{
    int count = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix1[i][j] == matrix2[i][j])
            {
                result[count++] = matrix1[i][j];
            }
        }
    }

    return count;
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

    int result[9] = { 0 };

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "Matrix 2:\n";
    PrintMatrix(matrix2, 3, 3);

    int count = GetIntersectedElements(matrix1, matrix2, result, 3, 3);

    cout << "\nNumber of intersected elements: " << count << '\n';
    cout << "Intersected elements: ";
    for (int i = 0; i < count; i++)
    {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}