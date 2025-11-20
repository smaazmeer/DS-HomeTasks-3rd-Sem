#include <iostream>
using namespace std;

void maxHeapInsert(int heap[], int &n, int value)
{
    heap[n] = value;
    int i = n;
    n++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(int heap[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void deleteMax(int heap[], int &n)
{
    heap[0] = heap[n - 1];
    n--;
    maxHeapify(heap, n, 0);
}

int main()
{
    int heap[10] = {1800, 1600, 1200, 1500};
    int n = 4;

    maxHeapInsert(heap, n, 1700);

    deleteMax(heap, n);

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
}
