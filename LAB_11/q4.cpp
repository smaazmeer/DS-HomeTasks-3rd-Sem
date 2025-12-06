#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 15;
const int EMPTY_ROLL = -1;
const int DELETED_ROLL = -2;

struct studentRecord 
{
    int rollNum;
    string name;
};

class StudentHashTable 
{
    private:
        studentRecord table[TABLE_SIZE];

        int h1(int rollNum) 
        {
            return rollNum % TABLE_SIZE;
        }

    public:
        StudentHashTable() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                table[i].rollNum = EMPTY_ROLL;
            }
        }

        void InsertRecord(int roll, string studentName) 
        {
            int index = h1(roll);

            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                int newIndex = (index + i * i) % TABLE_SIZE;

                if (table[newIndex].rollNum == EMPTY_ROLL || table[newIndex].rollNum == DELETED_ROLL) 
                {
                    table[newIndex].rollNum = roll;
                    table[newIndex].name = studentName;
                    cout << "Inserted Roll " << roll << " at index " << newIndex << endl;
                    return;
                }
                if (table[newIndex].rollNum == roll) 
                {
                    cout << "Error: Roll number " << roll << " already exists." << endl;
                    return;
                }
            }
            cout << "Hash table is full! Cannot insert Roll " << roll << endl;
        }

        void SearchRecord(int roll) 
        {
            int index = h1(roll);

            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                int newIndex = (index + i * i) % TABLE_SIZE;

                if (table[newIndex].rollNum == EMPTY_ROLL) 
                {
                    cout << "Record not found for Roll " << roll << endl;
                    return;
                }
                
                if (table[newIndex].rollNum == roll) 
                {
                    cout << "Record found: Student Name is " << table[newIndex].name << endl;
                    return;
                }
            }
            cout << "Record not found for Roll " << roll << endl;
        }
};

int main() 
{
    StudentHashTable studentTable;

    studentTable.InsertRecord(120, "Alice");
    studentTable.InsertRecord(32, "Bob");
    studentTable.InsertRecord(17, "Charlie");
    studentTable.InsertRecord(47, "David");

    studentTable.SearchRecord(32);
    studentTable.SearchRecord(17);
    studentTable.SearchRecord(99);

    return 0;
}