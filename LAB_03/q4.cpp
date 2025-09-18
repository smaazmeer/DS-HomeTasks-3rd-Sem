#include <iostream>
using namespace std;

class Node
{
    public:
        int ticketID;
        string customerName;
        string rideName;
        Node *next, ;

        Node()
        {
            ticketID = 0;
            customerName = "";
            rideName = "";
            next = nullptr;

        }

        Node(int id, string name, string ride):ticketID(id), customerName(name), rideName(ride)
        {
            next = nullptr;
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

        void IssueAtFirst(int id, string name, string ride)
        {
            Node* newNode = new Node(id, name, ride);

            if (head != nullptr)
            {
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
            else
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
            }
            
        }

        void IssueAtEnd(int id, string name, string ride)
        {
            if (head == nullptr)
            {
                IssueAtFirst(id, name, ride);
                return;
            }
            
            Node* newNode = new Node(id, name, ride);

            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        void CancelAtFirst()
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
            tail->next = head;
            delete del;  
        }

        void searchByID(int id)
        {
            Node* temp = head;
            
            while (temp != tail)
            {
                if (temp->ticketID == id)
                {
                    cout << "Ticket Found..." << endl;
                    cout << "Ticket ID: " << temp->ticketID << ", Customer: " << temp->customerName << ", Ride: " << temp->rideName << endl;
                    return;
                }
                
                temp = temp->next;
            }
            cout << "Item ID not found!" << endl;
        }

        void nextInLine(int id)
        {
            if (head == nullptr)
            {   
                cout << "No tickets" << endl;
                return;
            }
            
            if (tail->ticketID == id)
            {
                cout << "Ticket Found..." << endl;
                cout << "Ticket ID: " << head->ticketID << ", Customer: " << head->customerName << ", Ride: " << head->rideName << endl;
                return;
            }

            Node* temp = head;
            
            while (temp != tail)
            {
                if (temp->ticketID == id)
                {
                    Node* nextTicket = temp->next;
                    cout << "Ticket Found..." << endl;
                    cout << "Ticket ID: " << nextTicket->ticketID << ", Customer: " << nextTicket->customerName << ", Ride: " << nextTicket->rideName << endl;
                    return;
                }
                
                temp = temp->next;
            }
            cout << "ticket ID not found!" << endl;
        }

        void cancelByID(int id)
        {
            Node* temp = head;
            bool found = 0;

            if (head == nullptr)
            {
                cout << "List doesn't exists" << endl;
                return;
            }
            
            if(head->ticketID == id)
            {
                CancelAtFirst();
                return;
            }

            while (temp->next != tail)
            {
                if (temp->next->ticketID == id)
                {
                    found = 1;
                    break;
                }
                
                temp = temp->next;
            }

            if (not found)
            {
                cout << "Item ID not found!" << endl;
                return;
            }

            Node* del = temp->next;

            if (temp->next == tail)
            {
                temp->next = head;
                tail = temp;     
                delete del;
                return;
            }
            
            temp->next = temp->next->next;
            delete del;
        }

        int countTickets()
        {
            Node* temp = head;
            if (head == nullptr)
            {
                return 0;
            }
            
            int i = 1;
            while (temp != tail)
            {
                temp = temp->next;
                ++i;
            }
            return i;
        }

};
