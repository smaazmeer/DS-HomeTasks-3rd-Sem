#include <iostream>
using namespace std;

class Node
{
    public:
        int itemID;
        string itemName;
        double itemPrice;
        Node *next, *prev;

        Node()
        {
            itemID = 0;
            itemName = "";
            itemPrice = 0;
            next = nullptr;
            prev = nullptr;
        }

        Node(int id, string name, double price):itemID(id), itemName(name), itemPrice(price)
        {
            next = nullptr;
            prev = nullptr;
        }
};

class LinkedList
{
    private:
        Node* head, *tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void InsertAtHead(int id, string name, double price)
        {
            Node* newNode = new Node(id, name, price);

            if (head != nullptr)
            {
                newNode->next = head;
                newNode->prev = nullptr;
                head->prev = newNode;
                head = newNode;
            }
            else
            {
                head = newNode;
                tail = newNode;
            }
            
        }

        void InsertAtEnd(int id, string name, double price)
        {
            if (head == nullptr)
            {
                InsertAtHead(id, name, price);
                return;
            }
            
            Node* newNode = new Node(id, name, price);

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void DeleteAtHead()
        {
            if (head == nullptr)
            {
                cout << "List doesn't exist" << endl;
                return;
            }

            Node* del = head;
            
            if(head == tail)
            {
                head = nullptr;
                tail = nullptr;
                delete del;
                return;
            }

            head = head->next;
            head->prev = nullptr;
            delete del;  
        }

        void deleteAtTail()
        {
            if (head == nullptr)
            {
                cout << "List doesn't exist" << endl;
                return;
            }

            Node* del = tail;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
                delete del;
                return;
            }
            
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete del;
        }

        void searchByID(int id)
        {
            Node* temp = head;
            
            while (temp != nullptr)
            {
                if (temp->itemID == id)
                {
                    cout << "Item Found..." << endl;
                    cout << "Item ID: " << temp->itemID << ", Name: " << temp->itemName << ", Price: " << temp->itemPrice << endl;
                    return;
                }
                
                temp = temp->next;
            }
            cout << "Item ID not found!" << endl;
        }

        void UpdateItemPrice(int id, double price)
        {
            Node* temp = head;
            
            while (temp != nullptr)
            {
                if (temp->itemID == id)
                {
                    temp->itemPrice = price;
                    return;
                }
                
                temp = temp->next;
            }
            cout << "Item ID not found!" << endl;
        }

        void DisplayFrontToEnd()
        {
            Node* temp = head;
            int i = 0;
            while (temp != nullptr)
            {
                cout << ++i << ". ";
                cout << "Item ID: " << temp->itemID << ", Name: " << temp->itemName << ", Price: " << temp->itemPrice << endl;
                temp = temp->next;
            }
        }

        void DisplayEndToFront()
        {
            Node* temp = tail;
            int i = 0;
            while (temp != nullptr)
            {
                cout << ++i << ". ";
                cout << "Item ID: " << temp->itemID << ", Name: " << temp->itemName << ", Price: " << temp->itemPrice << endl;
                temp = temp->prev;
            }
        }

        int countItems()
        {
            Node* temp = head;
            int i = 0;
            while (temp != nullptr)
            {
                ++i;
                temp = temp->next;
            }
            return i;
        }

        void MostExpensive()
        {
            Node* temp = head;
            float max = 0;
            int id;

            while (temp != nullptr)
            {
                if (temp->itemPrice > max)
                {
                    max = temp->itemPrice;
                    id = temp->itemID;
                }
                temp = temp->next;
            }
            searchByID(id);
        }
};



int main()
{
    
    return 0;
}