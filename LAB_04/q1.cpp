#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int& count)
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    cout << "Input list: ";
    display(arr, n);

    bubbleSort(arr, n, comparisons);

    cout << "Sorted Element List: ";
    display(arr, n);

    cout << "Total number of comparisons performed: " << comparisons << endl;

    return 0;
}