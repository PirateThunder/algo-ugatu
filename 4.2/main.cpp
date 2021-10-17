#include <iostream>
#include <string>

class Deck {
public:
    Deck(int size) : buffer_size(size), head(size / 2), tail(size / 2)
    {
        buffer = new int[buffer_size];
    }

    ~Deck()
    {
        delete[] buffer;
    }

    bool empty()
    {
        return head == tail;
    }

    void push_front(int n)
    {
        head = (head - 1) % buffer_size;
        buffer[head] = n;
    }

    void push_back(int n)
    {
        buffer[tail] = n;
        tail = (tail + 1) % buffer_size;
    }

    int pop_front()
    {
        int result = buffer[head];
        head = (head + 1) % buffer_size;
        return result;
    }

    int pop_back()
    {
        tail = (tail - 1) % buffer_size;
        int result = buffer[tail];
        return result;
    }

private:
    int* buffer;
    int buffer_size;
    int head;
    int tail;
};

int main()
{
    int n, a, b;
    bool flag = true;
    std::cin >> n;
    Deck deck(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        if (a == 3)
        {
            deck.push_back(b);
        }
        else if (a == 1)
        {
            deck.push_front(b);
        }
        else if (a == 4)
        {
            if ((deck.empty() && b != -1) || (!deck.empty() && deck.pop_back() != b))
            {
                flag = false;
            }
        }
        else
        {
            if ((deck.empty() && b != -1) || (!deck.empty() && deck.pop_front() != b))
            {
                flag = false;
            }
        }
    }
    if (flag)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}
