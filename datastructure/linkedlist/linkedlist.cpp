/**
 * This is my own basic implementations of linked list, can be improved a lot.
 */
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class linkedlist {

public:
    struct node {
        T data;
        node *next;
        node() {next = nullptr;}
        node(T _data) {data = _data; next = nullptr;}
    };
    using nodeptr = node *;

public:
    linkedlist():root(nullptr) {}
    linkedlist(vector<T> elements):linkedlist() {
        for (T x:elements) {
            nodeptr temp = nullptr;
            if (root == nullptr) {
                root = new node(x);
            }
            temp = new node(x);
            temp->next = root;
            root = temp;
        }
    }
    ~linkedlist() {}

    void push_back(T data) {
        if (root == nullptr) { root = new node(data); return;}
        auto it = root;
        while (it->next != nullptr) { it = it->next; }
        it->next = new node(data);
    }

    node * find(T data) {
        auto it = root;
        while (it) {
            if (it->data == data) return it;
            it = it->next;
        }
        return nullptr;
    }

    void print() {
        if (root == nullptr) { cout << "No items in the list" << endl; }
        auto it = root;
        while (it) {
            cout << it->data << " ";
            it = it->next;
        }
        cout << endl;
    }

    void delete_data(T data) {
        if (root == nullptr) {return;}

        if (root->data == data) { auto next = root->next; delete root; root = next; return;}

        auto it = root;
        while (it->next) {
            if (it->next && it->next->data == data) {
                auto next = it->next->next;
                delete it->next;
                it->next = next;
                break;
            }
            it = it->next;
        }
    }

    void reverse() {
        if (root == nullptr) return;

        auto it = root->next;
        root->next = nullptr;
        while (it) {
            auto temp = it->next;
            it->next = root;
            root = it;
            it = temp;
        }
    }

private:
    nodeptr root;
};

int main()
{
    linkedlist<int> ll;
    ll.push_back(10);
    ll.push_back(15);
    ll.push_back(17);
    ll.push_back(21);
    ll.push_back(25);
    ll.push_back(29);
    ll.push_back(37);
    ll.push_back(39);
    ll.push_back(41);

    ll.print();

    if(ll.find(21)) cout << "found 21" << endl;
    if(ll.find(11)) cout << "found 11" << endl;

    ll.delete_data(10);
    if(ll.find(21)) cout << "found 21" << endl;
    ll.print();

    ll.reverse();
    ll.print();

    cout << "list ll1:" << endl;
    linkedlist<int> ll1({1, 2, 3, 4, 5, 6});
    ll1.print();

    return 0;
}

