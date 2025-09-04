#include <iostream>
using namespace std;

class Exam
{
    private:
        int* marks;
        int count;

    public:
        Exam()
        {
            count = 0;
            marks = new int[count];
        }

        Exam(int count) : count(count)
        {
            marks = new int[count];
        }

        ~Exam()
        {
            delete[] marks;
            marks = nullptr;
        }

        void setMark(int index, int value)
        {
            if (index >= 0 && index < count)
                marks[index] = value;
        }

        void display() const
        {
            cout << "Marks: ";
            for (int i = 0; i < count; i++)
            {
                cout << marks[i] << " ";
            }
            cout << endl;
        }
};

int main()
{

    Exam exam1(3);
    exam1.setMark(0, 85);
    exam1.setMark(1, 90);
    exam1.setMark(2, 75);

    cout << "Exam 1 original marks:" << endl;
    exam1.display();

    Exam exam2 = exam1;  
    cout << "Exam 2 (copied from Exam 1):" << endl;
    exam2.display();

    exam2.setMark(0, 40);  

    cout << "\nAfter modifying Exam 2:" << endl;
    cout << "Exam 1: ";
    exam1.display(); 
    cout << "Exam 2: ";
    exam2.display();

    return 0;
}
