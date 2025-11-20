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

void heapify(int heap[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void removeMax(int heap[], int &n)
{
    heap[0] = heap[n - 1];
    n--;
    heapify(heap, n, 0);
}

int main()
{
    int heap[10];
    int n = 0;

    maxHeapInsert(heap, n, 5);
    maxHeapInsert(heap, n, 3);
    maxHeapInsert(heap, n, 8);

    removeMax(heap, n);

    maxHeapInsert(heap, n, 6);

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
}
