// https://contest.yandex.ru/contest/30914/problems/1_4/
// 58849254

#include <iostream>
#include <string>
#include <vector>

// a < b ? true : false
bool string_compare(std::string &a, std::string &b) {
    if (a.length() < b.length()) { // <
        return true;
    }
    else if (a.length() > b.length()) { // >
        return false;
    }
    else {
        int n = a.length();
        for (int i = 0; i < n; i++) { // <
            if (a[i] < b[i]) {
                return true;
            }
            else if (a[i] > b[i]) { // >
                return false;
            }
            else if (a[i] == b[i] && i == n - 1) { // =
                return false;
            }
        }
    }
}

void swap_string(std::string& a, std::string& b) {
    std::string tmp;
    for (int i = 0; i < a.length(); i++) {
        tmp += a[i];
    }
    a.clear();
    for (int i = 0; i < b.length(); i++) {
        a += b[i];
    }
    b.clear();
    for (int i = 0; i < tmp.length(); i++) {
        b += tmp[i];
    }
}

void insertion_sort(std::vector<std::string>& v, int n) {
    int min_j;
    for (int i = 0; i < n - 1; i++) {
        min_j = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_j]) { //string_compare(v[j], v[min_j]) не работает! в чём проблема?
                min_j = j;
            }
        }
        swap_string(v[i], v[min_j]);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    selection_sort(v, n);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << "\n";
    }
}
