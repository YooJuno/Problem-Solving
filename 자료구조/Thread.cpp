#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

class MyClass1
{
public:
    void memberFunction(int& num, mutex& mu1, mutex& mu2) 
    {
        for (int i = 0; i < 10; ++i) 
        {
            std::this_thread::sleep_for(chrono::milliseconds(534));
            mu1.lock();
            mu2.lock();
            cout << "Thread 1 : " << num++ << endl;
            mu2.unlock();
            mu1.unlock();
        }
    }
};

class MyClass2 
{
public:
    void memberFunction(int& num, mutex& mu1, mutex& mu2) 
    {
        for (int i = 0; i < 10; ++i) 
        {
            std::this_thread::sleep_for(chrono::milliseconds(423));
            std::lock_guard<std::mutex> lock1(mu1);
            std::lock_guard<std::mutex> lock2(mu2);
            cout << "Thread 2 : " << num++ << endl;

        }
    }
};

int main() 
{
    MyClass1 myObject1;
    MyClass2 myObject2;
    std::mutex mu1;
    std::mutex mu2;
    vector<thread> workers;
    int num = 0;

    /*
    push_back()
        - 이미 생성된 객체를 벡터의 끝에 복사 또는 이동
        - 객체가 생성된 후에 벡터에 전달되기 때문에, 객체의 생성자와 소멸자가 호출될 수 있음.
    */
    // workers.push_back(thread(&MyClass1::memberFunction, &myObject1, 10));
    // workers.push_back(thread(&MyClass2::memberFunction, &myObject2, 20));

    /*
    emplace_back()
        - 객체를 직접 생성하여 벡터의 끝에 배치
        - 전달된 인자들로 객체가 벡터의 내부에서 직접 생성되기 때문에 불필요한 복사나 이동이 생략될 수 있음
    */

    // 첫번째 인자로 멤버 함수를 전달할 때는 두번째 인자로 해당 객체 인스턴스를 같이 전달한다.
    workers.emplace_back(thread(&MyClass1::memberFunction, &myObject1, std::ref(num), std::ref(mu1), std::ref(mu2)));
    workers.emplace_back(thread(&MyClass2::memberFunction, &myObject2, std::ref(num), std::ref(mu1), std::ref(mu2)));
    
    // 스레드 종료 대기
    for(auto& t : workers)
        t.join();

    return 0;
}