#include <iostream>
#include <vector>

/**
 * Move all zeros in an array to the right size, with out changing the order of the non zero elements.
 * Conditions: No extra array, only in place swap, and O(N)
 */

using namespace std;

void moveZeroes(vector<int>& a) {
    int i, j;
    for (i = 0, j = 0; i < a.size(); i++) {
        if(a[i] == 0)
            continue;
        else
            a[j++] = a[i];
    }

    while(j<a.size()) {
        a[j++] = 0;
    }
}

int main()
{
    vector<int> a{0,1,0,3,12};

    moveZeroes(a);

    for (auto x:a) {
        cout << x << " ";
    }

    return 0;
}
