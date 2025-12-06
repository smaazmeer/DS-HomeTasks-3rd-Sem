#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY_KEY = -1;
const int DELETED_KEY = -2;

class Hash 
{
    private:
        int keys[TABLE_SIZE];

    public:
        Hash() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                keys[i] = EMPTY_KEY;
            }
        }

        int h1(int key) 
        {
            return key % TABLE_SIZE;
        }

        void insert(int key) 
        {
            int index = h1(key);
            int startIndex = index;

            while (keys[index] != EMPTY_KEY && keys[index] != DELETED_KEY) 
            {
                if (keys[index] == key) 
                {
                    return;
                }
                index = (index + 1) % TABLE_SIZE;
                if (index == startIndex) 
                {
                    return;
                }
            }
            keys[index] = key;
        }

        void remove(int key) 
        {
            int index = h1(key);
            int startIndex = index;

            while (keys[index] != EMPTY_KEY) 
            {
                if (keys[index] == key) 
                {
                    keys[index] = DELETED_KEY;
                    cout << "Remove " << key << endl;
                    return;
                }
                index = (index + 1) % TABLE_SIZE;
                if (index == startIndex) 
                {
                    break;
                }
            }
        }

        void search(int key) 
        {
            int index = h1(key);
            int startIndex = index;

            while (keys[index] != EMPTY_KEY) 
            {
                if (keys[index] == key) 
                {
                    cout << key << " found" << endl;
                    return;
                }
                index = (index + 1) % TABLE_SIZE;
                if (index == startIndex) 
                {
                    break;
                }
            }
            cout << key << " not found" << endl;
        }

        void display() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                if (keys[i] != EMPTY_KEY && keys[i] != DELETED_KEY) 
                {
                    cout << keys[i] << " ";
                }
            }
            cout << endl;
        }
};

int main() 
{
    Hash hashTable;

    hashTable.insert(1);
    hashTable.insert(3);
    hashTable.insert(4);
    hashTable.insert(5);
    hashTable.insert(7);

    hashTable.display();

    hashTable.remove(4);

    hashTable.display();

    hashTable.search(5);
    hashTable.search(6);

    return 0;
}