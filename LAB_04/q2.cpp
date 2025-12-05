#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int arr[], int size)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }
    
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
    }
}

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

void insertionSort(int arr[], int n, int& count)
{
    count = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            count++; 
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        if (j >= 0) count++;
        arr[j + 1] = key;
    }
}
 
void selectionSort(int arr[], int n, int& count)
{
    count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
}

void shellSort(int arr[], int n, int& count)
{
    count = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap)
            {
                count++;
                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                else
                {
                    break;
                }
            }
            if (j >= gap)
            {
                count++;  
            } 
                
            arr[j] = temp;
        }
    }
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void run(int size)
{
    int arr[size];
    generateRandomArray(arr, size);

    int Initial_arr[size];
    
    for (int i = 0; i < size; i++)
    {
        Initial_arr[i] = arr[i];
    }
    
    
    display(arr, size);

    int comparisons = 0;


    //Bubble Sort
    bubbleSort(arr, size, comparisons);
    cout << "\nBubble Sort Result:" << endl;
    cout << "Sorted Array: ";
    display(arr, size);
    cout << "Comparison Count: " << comparisons << endl;

    //Insertion Sort
    insertionSort(Initial_arr, size, comparisons);
    cout << "\nInsertion Sort Result:" << endl;
    cout << "Sorted Array: ";
    display(arr, size);
    cout << "Comparison Count: " << comparisons << endl;

    //Selection Sort
    selectionSort(Initial_arr, size, comparisons);
    cout << "\nSelection Sort Result:" << endl;
    cout << "Sorted Array: ";
    display(arr, size);
    cout << "Comparison Count: " << comparisons << endl;
    
    //Shell Sort
    shellSort(Initial_arr, size, comparisons);
    cout << "\nShell Sort Result:" << endl;
    cout << "Sorted Array: ";
    display(arr, size);
    cout << "Comparison Count: " << comparisons << endl;
    
}

int main()
{
    srand(time(0)); 
    
    run(20);
    cout << endl;
    cout << endl;
    run(100);
    return 0;
}