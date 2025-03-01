#include <iostream>

using namespace std;

class Juno
{
public:
    Juno(int num) : _num(num)
    {

    }

    int printChar(char c)
    {
        cout << c << " " << _num << endl;
        return c;
    }
    
private:
    int _num;
};

int main()
{
    new Juno(10);
    void* tag;
    static_cast<Juno*>(tag)->printChar('n');

    return 0;
}