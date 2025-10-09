#include <iostream>
using namespace std;

bool isSafe(int arr[][4], int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool findPath(int arr[][4], int (&sol_arr)[4][4], int x, int y, int n)
{
    if (x == (n-1) && y == (n-1)) 
    {
        sol_arr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n) == 1)
    {
        sol_arr[x][y] = 1;

        //check below
        if (findPath(arr, sol_arr, x+1, y, n))
        {
            return true;
        }

        //check right
        else if (findPath(arr, sol_arr, x, y+1, n))
        {
            return true;
        }

        sol_arr[x][y] = 0;   
        return false;
    }
       
}

int main()
{
    int grid[4][4] = {{1, 0, 1, 1},
                      {1, 1, 0, 1},
                      {0, 1, 1, 1},
                      {1, 0, 1, 1}};
    
    int sol_grid[4][4] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};

    if(findPath(grid, sol_grid, 0, 0, 4))
    {
        if (findPath(grid, sol_grid, 0, 0, 4))
        {
        cout << "Path found:\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sol_grid[i][j] << " ";
            }
            cout << endl;
        }
        }
        else
        {
            cout << "No path found.\n";
        }
    }
    
    return 0;
}

/*Q: If multiple paths exist, explain how the algorithm decides which one to follow first.*/
/*A: Since we check the downward direction first, then rightward, the robot will always try to move down before moving right. If both directions are possible, it chooses the first one (down), and only backtracks to try the next (right) if the first path leads to a wrong path('0').*/