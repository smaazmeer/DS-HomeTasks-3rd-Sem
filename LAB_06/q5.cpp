#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack
{
    private:
        double arr[MAX];
        int topIndex;

    public:
        Stack() { topIndex = -1; }
        void push(double x) { arr[++topIndex] = x; }
        double pop() { return arr[topIndex--]; }
        bool empty() { return topIndex == -1; }
};

int main()
{
    Stack s;
    string exp;
    cout << "Enter prefix expression: ";
    cin >> exp;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isdigit(ch))
            s.push(ch - '0');
        else
        {
            double a = s.pop();
            double b = s.pop();
            switch (ch)
            {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(a / b); break;
            case '^': s.push(pow(a, b)); break;
            }
        }
    }
    cout << "Result = " << s.pop();
}
