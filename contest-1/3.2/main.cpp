// https://contest.yandex.ru/contest/29212/problems/3_2/
// ID посылки: 54883442 

#include <iostream>
#include <vector>

int main()
{
    int n, tmp, tmp1, tmp2;
    bool flag = false;
    std::cin >> n;
    std::cin >> tmp1;
    for (int i = 1; i < n; i++)
    {
        std::cin >> tmp2;
        if (tmp2 < tmp1)
        {
            std::cout << i-1;
            flag = true;
            break;
        }
        tmp1 = tmp2;
    }
    if (!flag)
    {
        std::cout << n-1;
    }
    return 0;
}
