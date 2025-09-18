#include <iostream>
using namespace std;

class Node
{
    public:
        string itemName;
        int price;
        Node* next;

        Node()
        {
            itemName = "";
            price = 0;
            next = nullptr;
        }

        Node(string name, int pr)
        {
            itemName = name;
            price = pr;
            next = nullptr;
        }

};

class LinkedList
{
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void InsertAtHead(string name, int price)
        {
            Node* newNode = new Node(name, price);
            newNode->next = head;
            head = newNode;

            if (tail == nullptr)
            {
                tail = newNode;
            }
            
        }

        void AddtoTail(string name, int price)
        {
            Node* newNode = new Node(name, price);
            newNode->next = nullptr;

            if (head == nullptr)
            {
                newNode = head;
                newNode = tail;
            }
            
            tail->next = newNode;
            tail = newNode;
        }

        void InsertAfterItem(string afterName, string name, int price)
        {
            Node* temp;
            temp = head;

            while (temp != NULL)
            {
                if (temp->itemName == afterName)
                {
                    if (temp == tail)
                    {
                        AddtoTail(name, price);
                        return;
                    }
                    
                    Node* newNode = new Node(name, price);
                    newNode->next = temp->next;
                    temp->next = newNode;

                    return;
                }
                temp = temp->next;
            }

            cout << afterName << " not found" << endl;
            
        }

        void searchByName(string name)
        {
            Node* temp;
            temp = head;

            while(temp != nullptr)
            {
                if(temp->itemName== name)
                {
                    cout << name << " exists in the cart. Price: $" << temp->price << endl;
                    return;
                }
                temp = temp->next;
            }

            cout << name << " doesn't in the cart" << endl;
            return;
        }

        void displayList()
        {
            Node* temp = head;
            int i = 0;
            while (temp != nullptr)
            {
                cout << i+1 << ". " << temp->itemName << " - $" << temp->price << endl;
                i++;
                temp = temp->next;
            }
            
        }

        void deleteFromHead()
        {
            if (head == nullptr)
            {
                return;
            }
            
            Node* del;
            del = head;

            head = head->next;
            delete del;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }

        void searchByPosition(int pos)
        {
            Node* temp = head;

            for (int i = 0; i < pos-1  && temp != nullptr; i++)
            {                
                temp = temp->next;
            }

            if (temp != nullptr)
            {
                cout << temp->itemName << " - Price: $" << temp->price << endl;                
            }
            else
            {
                cout << "Position out of bounds" << endl;
            }
            
        }
};
