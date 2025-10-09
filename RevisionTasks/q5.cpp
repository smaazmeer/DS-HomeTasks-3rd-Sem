#include <iostream>
using namespace std;

bool isSafe(int arr[][5], int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool catPath(int arr[][5], int (&sol_arr)[5][5], int x, int y, int n)
{
    if (x == 2 && y == 2)
    {
        sol_arr[x][y] = 1;
        return true;
    }
    
    if (isSafe(arr, x, y, n))
    {
        if (sol_arr[x][y] == 1)
        {
            return false;
        }

        sol_arr[x][y] = 1;

        if (catPath(arr, sol_arr, x+1, y, n))   // down
        {
            return true;
        }
        if (catPath(arr, sol_arr, x-1, y, n))   // up
        {
            return true;
        }
        if (catPath(arr, sol_arr, x, y-1, n))   // left
        {
            return true;
        }
        if (catPath(arr, sol_arr, x, y+1, n))   // right
        {
            return true;
        }
        
        sol_arr[x][y] = 0;
        return false;
    }
    return false;
}

bool rabbitPath(int arr[][5], int (&sol_arr)[5][5], int x, int y, int n)
{
    if (x == 2 && y == 2)
    {
        sol_arr[x][y] = 1;
        return true;
    }
    
    if (isSafe(arr, x, y, n))
    {
        if (sol_arr[x][y] == 1)
        {
            return false;
        }

        sol_arr[x][y] = 1;

        if (rabbitPath(arr, sol_arr, x+1, y, n))   // down
        {
            return true;
        }
        if (rabbitPath(arr, sol_arr, x-1, y, n))   // up
        {
            return true;
        }
        if (rabbitPath(arr, sol_arr, x, y-1, n))   // left
        {
            return true;
        }
        if (rabbitPath(arr, sol_arr, x, y+1, n))   // right
        {
            return true;
        }
        
        sol_arr[x][y] = 0;
        return false;
    }
    return false;
}

void findIntersections(int rabbitSol[][5], int catSol[][5], int n)
{
    cout << "\nIntersection point(s):" << endl;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rabbitSol[i][j] == 1 && catSol[i][j] == 1)
            {
                cout << "(" << i << "," << j << ")\n";
                found = true;
            }
        }
    }

    if (!found)
        cout << "No intersection found." << endl;
}

int main()
{
    int grid[5][5] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}};

    int rabbitSol[5][5] = {0};
    int catSol[5][5] = {0};

    if (rabbitPath(grid, rabbitSol, 0, 0, 5))
    {
        cout << "Rabbit path:\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << rabbitSol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Rabbit cannot reach the food" << endl;
    }

    if (catPath(grid, catSol, 4, 4, 5))
    {
        cout << "\nCat path:\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << catSol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Cat cannot reach the food" << endl;
    }

    findIntersections(rabbitSol, catSol, 5);
    return 0;
}
