#include <iostream>
using namespace std;

struct Node
{
    string site;
    Node *next;
};

class WebHistory
{
    Node *head;
    string stack[10];
    int topIndex;

public:
    WebHistory()
    {
        head = NULL;
        topIndex = -1;
    }

    void visit(string url)
    {
        Node *temp = new Node{url, head};
        head = temp;
        stack[++topIndex] = url;
    }

    void goBack(int times)
    {
        while (times-- && topIndex >= 0)
        {
            cout << "Going back from: " << stack[topIndex--] << endl;
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        if (topIndex >= 0)
            cout << "Now at: " << stack[topIndex] << endl;
    }

    void display()
    {
        cout << "\nCurrent history:\n";
        for (Node *p = head; p != NULL; p = p->next)
            cout << p->site << endl;
    }
};

int main()
{
    WebHistory h;
    h.visit("Google");
    h.visit("Facebook");
    h.visit("Twitter");
    h.visit("LinkedIn");
    h.visit("Instagram");
    h.display();
    h.goBack(2);
    h.display();
}
