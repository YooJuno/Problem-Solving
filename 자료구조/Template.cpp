#include <iostream>
#include <string>

/*
[Template?]

- 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀.\
- 함수 템플릿(Function Template)와 클래스 템플릿(Class Template) 로 나누어집니다.

*/

using namespace std;

/*
템플릿을 사용하면 함수 사용이 간단해진다.
*/
template<typename T>
T sum(T a, T b)
{
    return a + b;
}

template<class T1, class T2>
void printAll(T1 a, T2 b)
{
    cout << "T1 : " << a << endl;
    cout << "T2 : " << b << endl;
    // cout << "T1 + T2 : " << a + b << endl; // 안됨
}

int main()
{

    cout << "T sum(T a, T b) => " << sum<int>(10,20) << endl; // 인자로 들어가는 변수의 타입이 같을 때
    
    int a=1, b =2;
    double d1 = 2.2;
    double d2 = 3.3;
    string s1 = "Show me ";
    string s2 = "The Money 6";
    cout << "int 합 : " << sum<int>(a, b) << endl;
    cout << "double 합 : " << sum<double>(d1, d2) << endl;
    cout << "string 합 : " << sum<string>(s1, s2) << endl;

    /* 
    - template 함수는 호출할때 명확하게 어떤 자료형을 쓸 건지 < > 안에 표시해주는게 좋습니다.\
    - template로 사용하는 변수가 2개 이상일 경우에는 함수이름 뒤에 < > 안에 명확하게 사용하지 않습니다.

    */

    s1 = "Dok2" ; 
    s2 = "On my way." ;

    int num1 = 27; 
    int num2 = 35;

    d1 = 3.14; 
    d2 = 36.5;

    cout << "[string, string]" << endl; 
    printAll<string>(s1, s2);

    cout << "[string, int]" << endl; 
    printAll(s1, num1);

    cout << "[int, int]" << endl;  
    printAll<int>(num1, num2); 

    cout << "[int, double]" << endl; 
    printAll(num1, d1); 

    cout << "[double, double]" << endl; 
    printAll<double>(d1, d2); 

    cout << "[double, string]" << endl; 
    printAll(d1, s1);

    return 0;
}