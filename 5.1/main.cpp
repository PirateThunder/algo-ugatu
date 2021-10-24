// https://contest.yandex.ru/contest/29212/problems/5_1/
// ID посылки: 55352221

#include <deque>
#include <iostream>
#include <string>

int main()
{
    std::string str;
    getline(std::cin, str);

    std::string start_str = "";
    std::string end_str = "";
    std::deque<char> d;
    char c;

    for (int i = 0; i < str.length(); i++)
    {
        c = str[i];
        if (c == '(' || c == '{' || c == '[')
        {
            d.push_back(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (!d.empty())
            {
                if (!d.empty() && d.back() == '(')
                {
                    if (!d.empty() && c == ')')
                    {
                        d.pop_back();
                    }
                    else
                    {
                        d.push_back(c);
                    }
                }
                else if (!d.empty() && d.back() == '{')
                {
                    if (!d.empty() && c == '}')
                    {
                        d.pop_back();
                    }
                    else
                    {
                        d.push_back(c);
                    }
                }
                else if (!d.empty() && d.back() == '[')
                {
                    if (!d.empty() && c == ']')
                    {
                        d.pop_back();
                    }
                    else
                    {
                        d.push_back(c);
                    }
                }
                else
                {
                    d.push_back(c);
                }
            }
            else
            {
                d.push_back(c);
            }
        }
    }
    while (!d.empty())
    {
        if (d.back() == '(' || d.back() == '{' || d.back() == '[')
        {
            if (d.back() == '(')
            {
                end_str += ')';
                d.pop_back();
            }
            else if (d.back() == '{')
            {
                end_str += '}';
                d.pop_back();
            }
            else if (d.back() == '[')
            {
                end_str += ']';
                d.pop_back();
            }
            else
            {
                break;
            }
        }
        else if (d.front() == ')' || d.front() == '}' || d.front() == ']')
        {
            if (d.front() == ')')
            {
                start_str = '(' + start_str;
                d.pop_front();
            }
            else if (d.front() == '}')
            {
                start_str = '{' + start_str;
                d.pop_front();
            }
            else if (d.front() == ']')
            {
                start_str = '[' + start_str;
                d.pop_front();
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    if (d.empty())
    {
        std::cout << start_str << str << end_str;
    }
    else
    {
        std::cout << "IMPOSSIBLE";
    }
}
