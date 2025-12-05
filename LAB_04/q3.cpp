#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
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
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* arr = new int[size];
    
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter integers "<< i+1 << ": ";
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    display(arr, size);

    shellSort(arr, size);

    cout << "Sorted Array: ";
    display(arr, size);

    delete[] arr;
    return 0;
}