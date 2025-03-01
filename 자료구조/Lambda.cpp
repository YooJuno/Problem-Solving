#include <iostream>
#include <string>
#include <array>
#include <algorithm>

/*

std::vector<int> vec = {1, 2, 3, 4, 5};

std::function<void(int)> print = [](int n) { std::cout << n << ' '; }; // function<return(input)> print

for_each(vec.begin(), vec.end(), print);
// 출력: 1 2 3 4 5 


* [captures](parameters) -> return type { body }

* captures
    - comma(,)로 구분된 캡처들이 들어갑니다.
    - lambda 외부에 정의되어 있는 변수나 상수를 lambda 내부에서 사용하기 위해서 캡처를 사용합니다. 
    - 참조(reference)와 복사(copy) 두 방식을 사용할 수 있고, 참조는 [&var] 로 복사는 [var] 로 합니다. 
    - 그리고 캡처는 처음에 보았듯이 문법 요소 중 가장 처음에 나오는 []에 기술
    - mutable은 복사로 캡처된 변수를 몸통안에서 수정될 수 있도록 허용하는 지정자이고 
    - constexpr은 함수 호출 연산자(function call operator)가 상수 식인 것을 명시하는 지정자
    - 지정자에 아무 것도 기술하지 않으면 constexpr이 기본값        

        // x, y는 참조로, z, w는 복사로 캡처.
        auto foo = [&x, &y, z, w]() {};
    
    - [a,&b] a를 복사로 캡처, b를 참조로 캡처.
    - [this] 현재 객체를 참조로 캡처.
    - [&] 몸통에서 쓰이는 모든 변수나 상수를 참조로 캡처하고 현재 객체를 참조로 캡처.
    - [=] 몸통에서 쓰이는 모든 변수나 상수를 복사로 캡처하고 현재 객체를 참조로 캡처.
    - [] 아무것도 캡처하지 않음.
    - [&]나 [=]는 lambda가 정의되어있는 함수를 넘어서서 전역(global) 범위까지가 그 캡처 범위
    - 전역 변수를 캡처하기 위해서는 기본 캡처 모드(capture-default)를 사용 [&]
    - 클래스 멤버 함수안에서 정의되는 것뿐만 아니라 lambda 자체가 멤버로 선언될 수도 있습니다. 
        이럴 경우 기존 멤버 다루듯 하면 됩니다. [this]로 현재 객체를 참조로 캡처할 수 있는 것도 마찬가지

* parameters
    - 함수의 인자들이 들어갑니다.

* return type
    - 함수의 반환형입니다.
    - lambda는 값을 반환할 수 있고 그 반환형을 명시할 수 있습니다.
    - 후행 반환형(trailing return type)을 사용\
    - 또한 함수 포인터나 함수 객체와 다르게 반환형의 추론도 가능?

        int main() {
            // implicit return type
            auto foo = [] { return 3.14;};
            
            // explicit return type
            auto bar = []() -> float { return 3.14f; };
            
            // warning. double에서 float으로 암시적 형변환.
            float x = foo();
            
            // OK
            float y = bar();
            
            return 0;
        }

* body
    - 함수의 몸통입니다.
*/



int main() 
{
    [ /* capture */ ]( /* parameters */ std::string name) -> void
    { 
        /* body */ std::cout << "My name is " << name << std::endl; 
    } 
    ("Jinsoo Heo");

    std::array<int, 5> numbers = { 1, 2, 3, 4, 5 };
    
    int sum = 0;
    
    // 1. lambda로 구현 
    // std::for_each( numbers.begin(), numbers.end(), [&sum](int& number) 
    // { 
    //     sum += number; 
    // });

    // 2. lambda로 구현한걸
    /* auto */ std::function<int(int&)> adder = [&sum](int& number) {sum += number; std::cout << "number : " << number << "\nsum : " << sum << std::endl << std::endl; return sum;};
    std::for_each( numbers.begin(), numbers.end(), adder);

    std::cout << "[return] " << adder(sum) << std::endl;
    /*
    [RESULT]
        [return] number : 30
        sum : 30

        30

    => return 값이 먼저 나오는게 아니라 람다 함수 안에 있는 cout 결과가 먼저 나옴.
    그 다음에 람다함수의 리턴 값이 출력됨.
    */
    
    return 0;
}
