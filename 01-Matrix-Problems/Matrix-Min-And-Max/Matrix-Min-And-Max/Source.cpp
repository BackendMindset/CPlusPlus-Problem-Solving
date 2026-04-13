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

int FindMin(const int matrix[3][3], short rows, short cols)
{
    int minimum = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] < minimum)
                minimum = matrix[i][j];
        }
    }

    return minimum;
}

int FindMax(const int matrix[3][3], short rows, short cols)
{
    int maximum = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] > maximum)
                maximum = matrix[i][j];
        }
    }

    return maximum;
}

int main()
{
    int matrix[3][3] =
    {
        {1, 2, 1},
        {3, 5, 3},
        {7, 3, 7}
    };

    PrintMatrix(matrix, 3, 3);

    cout << "\nMin = " << FindMin(matrix, 3, 3);
    cout << "\nMax = " << FindMax(matrix, 3, 3);

    return 0;
}