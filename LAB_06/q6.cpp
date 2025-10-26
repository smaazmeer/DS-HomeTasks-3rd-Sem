#include <iostream>
using namespace std;

#define MAX 5

struct Order
{
    string item;
    int quantity;
};

class CircularQueue
{
    Order q[MAX];
    int front, rear, count;

public:
    CircularQueue()
    {
        front = rear = count = 0;
    }

    bool isFull() { return count == MAX; }
    bool isEmpty() { return count == 0; }

    void enqueue(Order o)
    {
        if (isFull())
        {
            cout << "Queue overflow! Cannot add order.\n";
            return;
        }
        q[rear] = o;
        rear = (rear + 1) % MAX;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow! No orders.\n";
            return;
        }
        cout << "Processing order: " << q[front].item << " x" << q[front].quantity << endl;
        front = (front + 1) % MAX;
        count--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No pending orders.\n";
            return;
        }
        cout << "\nPending Orders:\n";
        int i = front;
        for (int c = 0; c < count; c++)
        {
            cout << q[i].item << " x" << q[i].quantity << endl;
            i = (i + 1) % MAX;
        }
    }
};

int main()
{
    CircularQueue orders;
    int choice;
    do
    {
        cout << "\n1. Add Order  2. Process Order  3. Show All  0. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            Order o;
            cout << "Enter item name and quantity: ";
            cin >> o.item >> o.quantity;
            orders.enqueue(o);
        }
        else if (choice == 2)
            orders.dequeue();
        else if (choice == 3)
            orders.display();
    } while (choice != 0);
}
