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
        double top() { return arr[topIndex]; }
};

int main()
{
    Stack s;
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    for (char ch : exp)
    {
        if (isdigit(ch))
            s.push(ch - '0');
        else
        {
            double b = s.pop();
            double a = s.pop();
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
    cout << "Result = " << s.top();
}
