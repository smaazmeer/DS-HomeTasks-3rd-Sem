#include <iostream>
using namespace std;

void printArray(char** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(char** array, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (array[row][y] == 'Q')
        {
            return false;
        }
    }

    int row = x, col = y;
    while (row >= 0 && col >= 0)
    {
        if (array[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (array[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool NQueen(char** array, int x, int n, int& solCount, bool& firstPrinted)
{
    if (x >= n)
    {
        solCount++;
        if (!firstPrinted)
        {
            cout << "One valid solution:" << endl;
            printArray(array, n);
            firstPrinted = true;
        }
        return false;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(array, x, col, n))
        {
            array[x][col] = 'Q';

            if (NQueen(array, x + 1, n, solCount, firstPrinted))
            {
                return true;
            }

            array[x][col] = '.';
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    char** array = new char*[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            array[i][j] = '.';
        }
    }

    int solCount = 0;
    bool firstPrinted = false;

    NQueen(array, 0, n, solCount, firstPrinted);

    cout << "Total number of distinct solutions for N = " << n << " is: " << solCount << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
