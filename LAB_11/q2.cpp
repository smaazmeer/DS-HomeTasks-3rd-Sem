#include <iostream>
using namespace std;

const int TABLE_SIZE = 100;

struct Node 
{
    string key;
    Node* next;
};

Node* dictionary[TABLE_SIZE];

int stringSum(string key) 
{
    int sum = 0;
    for (char c : key) 
    {
        sum += c;
    }
    return sum;
}

int h1(string key) 
{
    return stringSum(key) % TABLE_SIZE;
}

void Add_Record(string key) 
{
    int index = h1(key);
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = nullptr;

    if (dictionary[index] == nullptr) 
    {
        dictionary[index] = newNode;
    } 
    else 
    {
        Node* temp = dictionary[index];
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Added '" << key << "' to the dictionary." << endl;
}

void wordSearch(string key) 
{
    int index = h1(key);
    Node* temp = dictionary[index];

    while (temp != nullptr) 
    {
        if (temp->key == key) 
        {
            cout << "'" << key << "' is available in the dictionary." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Error: '" << key << "' not available in the dictionary." << endl;
}

void display() 
{
    cout << "\n--- Complete Dictionary ---" << endl;
    bool empty = true;
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        Node* temp = dictionary[i];
        if (temp != nullptr) 
        {
            empty = false;
            cout << "Bucket " << i << ": ";
            while (temp != nullptr) 
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    if (empty) 
    {
        cout << "Dictionary is empty." << endl;
    }
    cout << "---------------------------" << endl;
}

int main() 
{
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        dictionary[i] = nullptr;
    }

    Add_Record("algorithm");
    Add_Record("data");
    Add_Record("structure");
    Add_Record("sort");

    wordSearch("data");
    wordSearch("hash");

    display();

    return 0;
}