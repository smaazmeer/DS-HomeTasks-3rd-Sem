#include <iostream>
using namespace std;

void minHeapInsert(int heap[], int &n, int value)
{
    heap[n] = value;
    int i = n;
    n++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void minHeapify(int heap[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void deleteMin(int heap[], int &n)
{
    heap[0] = heap[n - 1];
    n--;
    minHeapify(heap, n, 0);
}

int main()
{
    int heap[10] = {50, 60, 75, 100};
    int n = 4;

    minHeapInsert(heap, n, 55);

    deleteMin(heap, n);

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
}
