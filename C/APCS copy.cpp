#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int _data;
    Node *_lchild = nullptr, *_rchild = nullptr;
    void print_data()
    {
        cout << _data << "\n";
    }
}

void dfs(Node *node)
{
    node->print_data();
    if (node->_lchild != nullptr)
        dfs(node->_lchild);
    if (node->_rchild != nullptr)
        dfs(node->_rchild);
}

int main()
{
}