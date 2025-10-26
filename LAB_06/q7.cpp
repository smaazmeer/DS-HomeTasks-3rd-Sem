#include <iostream>
using namespace std;

#define MAX 10

class LinearQueue
{
    private:  
        string patrons[MAX];
        int front, rear;

    public:
        LinearQueue()
        {
            front = 0;
            rear = -1;
        }

        bool isFull()
        {
            return rear == MAX - 1;
        }

        bool isEmpty()
        {
            return front > rear;
        }

        void enqueue(string name)
        {
            if (isFull())
            {
                cout << "Queue Overflow! No more patrons can be added.\n";
                return;
            }
            patrons[++rear] = name;
            cout << name << " added to the queue.\n";
        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue Underflow! No patrons to serve.\n";
                return;
            }
            cout << patrons[front] << " has been served and removed from the queue.\n";
            front++;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "No patrons in the queue.\n";
                return;
            }
            cout << "\nCurrent Patrons in Queue:\n";
            for (int i = front; i <= rear; i++)
                cout << i - front + 1 << ". " << patrons[i] << endl;
        }
};

int main()
{
    LinearQueue queue;
    int choice;
    string name;

    do
    {
        cout << "\n1. Add Patron  2. Complete Transaction  3. Show Queue  0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            queue.enqueue(name);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.display();
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
