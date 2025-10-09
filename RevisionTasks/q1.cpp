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
    int arr[] = {205, 102, 310, 450, 120, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    print(arr, n);
    
    shellSort(arr, n);
    
    cout << "After sorting: ";
    print(arr, n);

    cout << endl;
    return 0;
}

//Q: Explain why Shell Sort is more efficient for this case than Insertion Sort.
/*A: The data is mixed. Shell Sort allows faster movement of small elements across the array using larger gaps. It reduces the total number of comparisons and shifts, leading to better performance overall.*/