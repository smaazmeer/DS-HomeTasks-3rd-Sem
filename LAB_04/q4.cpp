#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int interpolationSearch(int arr[], int size, int x)
{
    int low = 0;
    int high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + (int)(((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
        {
            return pos;
        }

        if (arr[pos] < x)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
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

    if (size <= 0)
    {
        cout << "Invalid size." << endl;
        return 0;
    }

    int* arr = new int[size];
    
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter integers "<< i+1 << ": ";
        cin >> arr[i];
    }

    bubbleSort(arr, size);

    cout << "\nSorted Array: ";
    display(arr, size);

    int key;
    cout << "Enter the value to search for: ";
    cin >> key;

    int index = interpolationSearch(arr, size, key);

    if (index != -1)
    {
        cout << "Element " << key << " found at index " << index << "." << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array." << endl;
    }

    delete[] arr;
    return 0;
}