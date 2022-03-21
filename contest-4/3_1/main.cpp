// ID: 66226409
// https://contest.yandex.ru/contest/35212/problems/3_1/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    else if (n == 3) {
        std::cout << 2;
        return 0;
    }
    else if(n < 6) {
        cout << 1;
        return 0;
    }
    vector<int> arr(n + 1, 1000000000);
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 1;
    arr[5] = 1;
    for(int i = 6; i <= n; i++) {
        if (i % 5 == 0 && arr[i] > arr[i / 5]) {
            arr[i] = arr[i / 5] + 1;
        }
        if (i % 4 == 0 && arr[i] > arr[i / 4]) {
            arr[i] = arr[i / 4] + 1;
        }
        if (arr[i] > arr[i - 1]) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    cout << arr[n];
    return 0;
}