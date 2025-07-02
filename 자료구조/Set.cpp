#include <iostream>
#include <set>

using namespace std;

struct CustomCompare
{
    bool operator()(const int &a, const int &b) const
    {
        // 예: 내림차순 정렬
        return a > b;
    }
};

int main()
{
    set<int, CustomCompare> s;

    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(1);

    for (int x : s)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
