#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    while (n != 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                std::cout << i << " ";
                n /= i;
                break;
            }
            if (i == n)
            {
                std::cout << i;
            }
        }
    }
    return 0;
}
