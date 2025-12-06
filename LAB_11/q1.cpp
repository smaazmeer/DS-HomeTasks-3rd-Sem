#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Node 
{
    string key;
    Node* next;
};

Node* hashTable[TABLE_SIZE];

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

void insert(string key) 
{
    int index = h1(key);
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr) 
    {
        hashTable[index] = newNode;
    } 
    else 
    {
        Node* temp = hashTable[index];
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

string search(string key) 
{
    int index = h1(key);
    Node* temp = hashTable[index];

    while (temp != nullptr) 
    {
        if (temp->key == key) 
        {
            return "Found";
        }
        temp = temp->next;
    }
    return "Not Found";
}

void display() 
{
    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        cout << "Bucket " << i << ": ";
        Node* temp = hashTable[i];
        if (temp == nullptr) 
        {
            cout << "NULL";
        }
        while (temp != nullptr) 
        {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main() 
{
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        hashTable[i] = nullptr;
    }

    insert("apple");
    insert("mango");
    insert("apple");
    insert("grapes");
    insert("peach");
    insert("banana");
    
    display();

    cout << "Searching 'apple': " << search("apple") << endl;
    cout << "Searching 'orange': " << search("orange") << endl;

    return 0;
}