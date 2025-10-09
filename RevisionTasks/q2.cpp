/*Q1: Compare the efficiency of Shell Sort with Bubble Sort for this case. Why would the airport prefer Shell Sort?*/

/*A1: Shell Sort is faster because it moves items long distances early using gaps. Bubble Sort only swaps adjacent elements, requiring many passes. Airport prefers Shell Sort as it’s more efficient for large or unsorted data, reducing processing time.*/

/*Q2: If most of the luggage is already nearly sorted, explain how Shell Sort’s performance
would change.*/

/*A2: Shell Sort’s performance improves further, approaching O(n) time. It needs very few comparisons and swaps, since elements are already close to their correct positions.*/

#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
       cout << arr[i] << (i == size-1 ? "]":", ");
    }
    cout << endl;
}

void shellSort(int arr[], int n)
{
    int count = 1;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }


            arr[j] = temp;
        }
        cout << "Pass " << count++ << ": ";
        print(arr, n);
    }
}


int main()
{
    int arr[] = {32, 25, 40, 12, 18, 50, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    print(arr, n);
    
    shellSort(arr, n);
    
    cout << "After sorting: ";
    print(arr, n);

    cout << endl;
    return 0;
}
