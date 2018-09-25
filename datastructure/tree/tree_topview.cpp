#include <iostream>
#include <deque>

/**
 * This function display top view of binary tree. Say for example, the below tree will be displayed as
 * 4 2 1 3 7
 *
 *
 *                                       1
 *                                  2         3
 *                              4       5 6       7
 *
 */

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int x):data(x) {}
};

void insert(Node* root, int val)
{
    if (root == nullptr) {
        root = new Node(val);
    }

    Node *t = root, *pnode = root;

    while (t) {
        pnode = t;
        if (t->data > val) {
            t = t->left;
        } else {
            t = t->right;
        }
    }

    if (pnode->data > val) {
        pnode->left = new Node(val);
    } else {
        pnode->right = new Node(val);
    }
}


void display_topview(Node* root)
{
    deque<int> dq;

    dq.push_back(root->data);

    Node *t = root->left;
    while(t) {
        dq.push_front(t->data);
        t = t->left;
    }

    t = root->right;
    while(t) {
        dq.push_back(t->data);
        t = t->right;
    }

    for (auto x:dq) {
        cout << x << " ";
    }
}


int main()
{
    Node* root = new Node(10);
    insert(root, 11);
    insert(root, 8);
    insert(root, 7);
    insert(root, 12);
    insert(root, 9);

    display_topview(root);
    return 0;
}

