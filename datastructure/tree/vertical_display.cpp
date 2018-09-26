#include <iostream>
#include <string>
#include <map>

/**
 * This function display the nodes of a binary tree in their vertical segments. Say for example, the below tree will be displayed as
 * 4 2 1 5 6 3 7
 *
 *                                       1
 *                                  2         3
 *                              4       5 6       7
 *
 * This above tree will be represented as below in vertical order
 *
 *                              -2| -1|  0  | 1 | 2
 *                             ---------------------
 *                                |   |  1  |   |
 *                                | 2 |     | 3 |
 *                              4 |   | 5 6 |   | 7
 *
 */

using namespace std;

struct Node {
    int data;
    int verticalId;
    Node * left;
    Node * right;
    Node(int x, int vid=0):data(x),verticalId(vid) {}
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
        pnode->left = new Node(val, pnode->verticalId - 1);
    } else {
        pnode->right = new Node(val, pnode->verticalId + 1);
    }
}

void traverse_all_node(multimap<int, Node *> &mmap, Node* root)
{
    if (root == nullptr) return;

    mmap.insert(make_pair(root->verticalId, root));
    traverse_all_node(mmap, root->left);
    traverse_all_node(mmap, root->right);
}

void traverse_all_node_alt(multimap<int, Node *> &mmap, Node* root, int val)
{
    if (root == nullptr) return;

    mmap.insert(make_pair(val, root));
    traverse_all_node_alt(mmap, root->left, val - 1);
    traverse_all_node_alt(mmap, root->right, val + 1);
}


void display_vertical(Node* root)
{
    multimap<int, Node *> mmap, mmap1;
    traverse_all_node(mmap, root);

    for(auto x:mmap) {
        cout << x.first << ":" << x.second->data << endl;
    }

    cout << endl << endl << endl;

    traverse_all_node_alt(mmap1, root, 0);

    for(auto x:mmap1) {
        cout << x.first << ":" << x.second->data << endl;
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

    display_vertical(root);
    return 0;
}


