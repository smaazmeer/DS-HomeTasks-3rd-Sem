#include <iostream>
using namespace std;

#define MAX 10

struct Call
{
    string name;
    string number;
    int duration;
};

class CallStack
{
    private:
        Call stack[MAX];
        int topIndex;

    public:
        CallStack()
        {
            topIndex = -1;
        }

        bool empty()
        {
            return topIndex == -1;
        }

        bool full()
        {
            return topIndex == MAX - 1;
        }

        void push(Call c)
        {
            if (full())
            {
                cout << "Call history full!\n";
                return;
            }
            stack[++topIndex] = c;
            cout << "Call added.\n";
        }

        void pop()
        {
            if (empty())
            {
                cout << "No call to remove.\n";
                return;
            }
            cout << "Removing call: " << stack[topIndex].name << endl;
            topIndex--;
        }

        void top()
        {
            if (empty())
            {
                cout << "No recent call.\n";
                return;
            }
            Call c = stack[topIndex];
            cout << "Most recent call - Name: " << c.name << ", Number: " << c.number << ", Duration: " << c.duration << " mins\n";
        }

        void display()
        {
            if (empty())
            {
                cout << "Call history empty.\n";
                return;
            }
            cout << "\nCurrent Call History:\n";
            for (int i = topIndex; i >= 0; i--)
                cout << i + 1 << ". " << stack[i].name << " - " << stack[i].number << " (" << stack[i].duration << " mins)\n";
        }
};

int main()
{
    CallStack s;
    int choice;
    do
    {
        cout << "\n1. Add Call  2. Remove Call  3. Show Last Call  4. Display All  0. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            Call c;
            cout << "Enter Name, Number, Duration: ";
            cin >> c.name >> c.number >> c.duration;
            s.push(c);
        }
        else if (choice == 2)
            s.pop();
        else if (choice == 3)
            s.top();
        else if (choice == 4)
            s.display();
    } while (choice != 0);
}
