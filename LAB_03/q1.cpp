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

    public:
        LinkedList()
        {
            head = nullptr;
        }

        void InsertAtHead(string name, int price)
        {
            Node* newNode = new Node(name, price);
            newNode->next = head;
            head = newNode;
        }

        void InsertAtEnd(string name, int price)
        {
            Node* newNode = new Node(name, price);
            Node* temp;
            temp = head;
            while (temp->next != nullptr)
            {
                temp  = temp->next;        
            }
            
            temp->next = newNode;    
        }

        void InsertAfterItem(string afterName, string name, int price)
        {
            Node* newNode = new Node(name, price);
            Node* temp;
            int pos = 0;
            bool found = 0;
            temp = head;

            while (temp != NULL)
            {
                if (temp->itemName == afterName)
                {
                    found = 1;
                    break;
                }
                temp = temp->next;
                pos++;
            }

            if (not found)
            {
                cout << "Target Item doesn't exists in the cart" << endl;
                delete newNode;
                return;
            }
            
            pos++;
            temp = head;

            for (int i = 0; i < pos - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            
            
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void search(string name)
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
};




int main()
{
    LinkedList Cart;
    // INITIAL LINKED LIST
    Cart.InsertAtHead("Laptop", 1000);
    Cart.InsertAtEnd("Phone", 700);
    Cart.InsertAtEnd("Tablet", 400);
    Cart.InsertAtEnd("Headphones", 150);
    
    cout << "DISPLAYING INITIAL LIST..." << endl;
    Cart.displayList();

    Cart.InsertAtHead("Smartwatch", 200);
    Cart.InsertAtEnd("Keyboard", 80);
    Cart.InsertAfterItem("Phone", "Monitor", 300);
    Cart.search("Tablet");
    
    cout << "DISPLAYING NEW LIST..." << endl;
    Cart.displayList();
    return 0;
}