#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int x):data(x) {}
};

void bfs(Node* root)
{
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node* T = Q.front();
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

