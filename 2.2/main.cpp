// https://contest.yandex.ru/contest/29212/problems/2_2/
// ID посылки: 54853409

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    std::vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
		std::cin >> x[i] >> y[i];
    }

    int min_x, min_y, max_x, max_y;
    min_x = min_y = INT_MAX;
    max_x = max_y = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        min_x = std::min(min_x, x[i]);
        min_y = std::min(min_y, y[i]);
        max_x = std::max(max_x, x[i]);
        max_y = std::max(max_y, y[i]);
    }
    int w, h, S, S1;
    w = abs(max_x - min_x);
    h = abs(max_y - min_y);
    S = w*h;
    S1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min_x = std::min(x[i], x[i+1]);
        min_y = std::min(y[i], y[i+1]);
        max_x = std::max(x[i], x[i+1]);
        max_y = std::max(y[i], y[i+1]);
        w = std::abs(max_x - min_x);
        h = std::abs(max_y - min_y);
        S1 += w*h;
    }
    min_x = std::min(x[n-1], x[0]);
    min_y = std::min(y[n-1], y[0]);
    max_x = std::max(x[n-1], x[0]);
    max_y = std::max(y[n-1], y[0]);
    w = std::abs(max_x - min_x);
    h = std::abs(max_y - min_y);
    S1 += w*h;

    std::cout << S - (double)S1/2;
    return 0;
}
