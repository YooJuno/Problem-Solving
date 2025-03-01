#include <iostream>
#include <functional>

using namespace std;

class CallbackClass 
{
public:
    void Callbackfunction(int x) 
    {
        std::cout<< "Callback Func Called : " << x << std::endl;
    }
};

void CallbackFunction2(int x, int y) 
{
    std::cout << "Callback Func Called : " << x << std::endl;
}

int main() 
{
	CallbackClass cls;

    // functional pointer
    std::function<void(int)> cbMember = std::bind(&CallbackClass::Callbackfunction, &cls, std::placeholders::_1); // Class의 member func를 가져올 땐 두 번째 인자로 객체 포인터를 넣어줘야함.
    std::function<void(int, int)> cbFunc = std::bind(&CallbackFunction2, std::placeholders::_1, std::placeholders::_2);
   	
    cbMember(1);
    cbFunc(2, 3);
    
    return 0;
}