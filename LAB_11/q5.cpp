#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 50;
const string EMPTY_NAME = "";
const string DELETED_NAME = "_DEL_";

class EmployeeDirectory 
{
    private:
        string table[TABLE_SIZE];

        int calculateSum(string key) 
        {
            int sum = 0;
            for (char c : key) 
            {
                sum += c;
            }
            return sum;
        }

        int h1(int sum) 
        {
            return sum % TABLE_SIZE;
        }

        int h2(int sum) 
        {
            return 7 - (sum % 7);
        }

    public:
        EmployeeDirectory() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                table[i] = EMPTY_NAME;
            }
        }

        void Add_Employee(string name) 
        {
            int sum = calculateSum(name);
            int hash1 = h1(sum);
            int hash2 = h2(sum);
            int index = hash1;

            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                if (table[index] == EMPTY_NAME || table[index] == DELETED_NAME) 
                {
                    table[index] = name;
                    cout << "Added employee '" << name << "' at index " << index << endl;
                    return;
                }
                if (table[index] == name) 
                {
                    cout << "Employee '" << name << "' already in directory." << endl;
                    return;
                }

                index = (hash1 + i * hash2) % TABLE_SIZE;
            }
            cout << "Error: Directory is full. Cannot add employee '" << name << "'." << endl;
        }

        void Search_Employee(string name) 
        {
            int sum = calculateSum(name);
            int hash1 = h1(sum);
            int hash2 = h2(sum);
            int index = hash1;

            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                if (table[index] == EMPTY_NAME) 
                {
                    cout << "Employee not found in the directory." << endl;
                    return;
                }
                
                if (table[index] == name) 
                {
                    cout << "Employee '" << name << "' found at index " << index << "." << endl;
                    return;
                }

                index = (hash1 + i * hash2) % TABLE_SIZE;
            }
            cout << "Employee not found in the directory." << endl;
        }

        void display() 
        {
            cout << "\n--- Employee Hash Table (Index: Name) ---" << endl;
            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                if (table[i] != EMPTY_NAME && table[i] != DELETED_NAME) 
                {
                    cout << i << ": " << table[i] << endl;
                }
            }
            cout << "------------------------------------------" << endl;
        }
};

int main() 
{
    EmployeeDirectory directory;

    directory.Add_Employee("John Doe"); 
    directory.Add_Employee("Jane Smith");
    directory.Add_Employee("Alex Brown");
    directory.Add_Employee("Do E Joh");

    directory.Search_Employee("Jane Smith");
    directory.Search_Employee("Mark Lee");

    directory.display();

    return 0;
}