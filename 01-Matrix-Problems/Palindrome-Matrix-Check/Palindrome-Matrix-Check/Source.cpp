#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(const int matrix[4][4], short rows, short cols)
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

bool IsPalindromeMatrix(const int matrix[4][4], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            if (matrix[i][j] != matrix[i][cols - j - 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int matrix[4][4] =
    {
        {1, 2, 2, 1},
        {3, 5, 5, 3},
        {7, 3, 3, 7},
        {4, 8, 8, 4}
    };

    PrintMatrix(matrix, 4, 4);

    if (IsPalindromeMatrix(matrix, 4, 4))
        cout << "\nYes: Matrix is palindrome.";
    else
        cout << "\nNo: Matrix is not palindrome.";

    return 0;
}