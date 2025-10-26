#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    private:
        char arr[MAX];
        int topIndex;

    public:
        Stack() { topIndex = -1; }

        void push(char ch)
        {
            arr[++topIndex] = ch;
        }

        char pop()
        {
            return arr[topIndex--];
        }

        char top()
        {
            return arr[topIndex];
        }

        bool empty()
        {
            return topIndex == -1;
        }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = "";
    Stack s;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
                postfix += s.pop();
            s.pop();
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
                postfix += s.pop();
            s.push(ch);
        }
    }

    while (!s.empty())
        postfix += s.pop();

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
