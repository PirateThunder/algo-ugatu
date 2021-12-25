// https://contest.yandex.ru/contest/32613/problems/1_2/
// ID посылки: 62908986

#include <iostream>
#include <stack>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};


void add_node(BinaryTree* node, int value)
{
    if (value <= node->value) {
        if (node->left != nullptr) {
            add_node(node->left, value);
        }
        else {
            node->left = new BinaryTree(value);
        }
    } else {
        if (node->right != nullptr) {
            add_node(node->right, value);
        }
        else {
            node->right = new BinaryTree(value);
        }
    }
}

void DFS(BinaryTree* node) {
    stack<BinaryTree*> s;
    stack<pair<bool, bool>> is_visited;


    if (node != nullptr) {
        s.push(node);
        is_visited.push(make_pair(false, false));
    }

    while(!s.empty()) {
        BinaryTree* node = s.top();
        pair<int, int> visited = is_visited.top();

        if (!visited.first) cout << node->value << " "; // выводим текущую вершину
        if (node->left != nullptr && !visited.first) { // если вершина слева есть, идём в её
            s.push(node->left);
            is_visited.pop();
            is_visited.push(make_pair(true, false));
            is_visited.push(make_pair(false, false));
        }
        else if (node->right != nullptr && !visited.second) { // иначе идём направо
           s.push(node->right);
           is_visited.pop();
           is_visited.push(make_pair(true, true));
           is_visited.push(make_pair(false, false));
        }
        else {
            s.pop();
            is_visited.pop();
        }
    }
}

int main() {
    int n;
    cin >> n;
    int tmp;
    cin >> tmp;
    BinaryTree* tree = new BinaryTree(tmp);
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        add_node(tree, tmp);
    }

    DFS(tree);
}
