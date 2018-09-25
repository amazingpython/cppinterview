#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> * left;
    Node<T> * right;
    Node(T x):data(x) {}
};

using NodeInt = Node<int>;
using NodeIntPtr = NodeInt *;

void bfs(const NodeIntPtr root)
{
    queue<NodeIntPtr> Q;
    Q.push(root);
    while (!Q.empty()) {
        NodeIntPtr T = Q.front();
        Q.pop();
        cout << T->data;
        if (T->left)
            Q.push(T->left);
        if(T->right)
            Q.push(T->right);
    }
}


int main()
{
    Node* root = new Node(10);
    bfs(root);
    return 0;
}
