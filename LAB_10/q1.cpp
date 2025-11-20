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

int main()
{
    int heap[10] = {1, 3, 4, 5};
    int n = 4;

    minHeapInsert(heap, n, 2);

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
}
