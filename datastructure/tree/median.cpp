#include <iostream>
#include <queue>
#include <functional>

/**
 * This function calculate the medians of a running stream of integers.
 */

using namespace std;

void insert_elements(priority_queue<int>& l, priority_queue<int, vector<int>, greater<int>>& h, int x)
{
    if (l.empty()) {
        l.push(x);
        return;
    }

    if(l.top() > x)
        l.push(x);
    else
        h.push(x);

}

void balance_queues(priority_queue<int>& l, priority_queue<int, vector<int>, greater<int>>& h)
{
    int lsize = l.size(), hsize = h.size();
    if (lsize - hsize > 1) {
        h.push(l.top());
        l.pop();
    }
    if (hsize - lsize > 1) {
        l.push(h.top());
        h.pop();
    }
}

double get_median(priority_queue<int>& l, priority_queue<int, vector<int>, greater<int>>& h)
{
    if (l.size() > h.size()) {
        return l.top();
    } else if (l.size() < h.size()) {
        return h.top();
    } else {
        return ((l.top() + h.top()) / 2);
    }
}

void find_median(const vector<int>& arr)
{
    vector<double> medians;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> h;

    for (auto& x: arr) {
        insert_elements(l, h, x);
        balance_queues(l,h);
        medians.push_back(get_median(l, h));
    }

    for (auto x:medians) {
        cout << x << " ";
    }
}


int main()
{
    vector<int> arr{5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    find_median(arr);
    //medians: 5 10 5 4 3 4 5 6 7 6 7 6
}
