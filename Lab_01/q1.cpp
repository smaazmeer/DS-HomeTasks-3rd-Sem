#include <iostream>
using namespace std;

class ResearchPaper
{
    private:
        string* authorNames;
        int authorNum;

    public:
        ResearchPaper(int num)
        {
            authorNum = num;
            authorNames = new string[authorNum];

        }

        ResearchPaper(const ResearchPaper& obj)
        {
            authorNum = obj.authorNum;
            authorNames = new string[obj.authorNum];
            for (int i = 0; i < authorNum; i++)
            {
                authorNames[i] = obj.authorNames[i];
            }   
        }

        ~ResearchPaper()
        {
            delete []authorNames;
            authorNames = NULL;
        }

        ResearchPaper& operator=(const ResearchPaper& obj)
        {
            delete []authorNames;

            authorNum = obj.authorNum;
            string* authorNames = new string[obj.authorNum];
            for (int i = 0; i < authorNum; i++)
            {
                authorNames[i] = obj.authorNames[i];
            }   
            return *this;
        }

        void setAuthor(int index, string name)
        {
            if (index >= 0 && index < authorNum)
            {
                authorNames[index] = name;
            }
        }

        void displayAuthors() const
        {
            cout << "Authors: ";
            for (int i = 0; i < authorNum; i++)
            {
                cout << authorNames[i];
                if (i < authorNum - 1) cout << ", ";
            }
            cout << endl;
        }
};

int main()
{
    ResearchPaper paper1(2);
    paper1.setAuthor(0, "irfan");
    paper1.setAuthor(1, "talha");

    cout << "Original Paper 1:" << endl;
    paper1.displayAuthors();

    
    ResearchPaper paper2(paper1);
    cout << "Copied Paper 2 (via copy constructor):" << endl;
    paper2.displayAuthors();

    paper2.setAuthor(0, "adil");
    cout << "\nAfter modifying Paper 2:" << endl;

    cout << "Paper 1: ";
    paper1.displayAuthors();

    cout << "Paper 2: ";
    paper2.displayAuthors();

    ResearchPaper paper3(2);
    paper3 = paper1;
    cout << "\nCopied Paper 3 (via assignment operator):" << endl;
    paper3.displayAuthors();

    return 0;
}
