#include <iostream>
using namespace std;

class Box
{
    private:
        int* volume;

    public:
        Box()
        {
            volume = new int{0};
        }

        Box(int vol)
        {
            volume = new int{vol};
        }

        Box(const Box& obj)
        {
            volume = new int{*obj.volume};
        }

        ~Box()
        {
            delete volume;
            volume = nullptr;
        }

            void setVolume(int vol)
        {
            *volume = vol;
        }


        int getVolume() const
        {
            return *volume;
        }
};

int main()
{

    Box b1;
    cout << "Box 1 volume (default): " << b1.getVolume() << endl;

    Box b2(50);
    cout << "Box 2 volume (parameterized): " << b2.getVolume() << endl;

    Box b3 = b2;
    cout << "Box 3 volume (copied from Box 2): " << b3.getVolume() << endl;

    b3.setVolume(100);
    cout << "\nAfter modifying Box 3 volume:" << endl;
    cout << "Box 2 volume: " << b2.getVolume() << endl;  
    cout << "Box 3 volume: " << b3.getVolume() << endl;

    return 0;
}


