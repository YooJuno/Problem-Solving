#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    // 오름차순 정렬된 상태여야 모든 순열을 출력 가능
    sort(v.begin(), v.end());

    do {
        // 현재 순열 출력
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    /*
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
    */

    vector<int> v = {3, 2, 1};
    sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬
    do {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    } while (prev_permutation(v.begin(), v.end()));
    /*
        3 2 1
        3 1 2
        2 3 1
        2 1 3
        1 3 2
        1 2 3
    */

    return 0;
}


