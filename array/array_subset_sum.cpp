#include <iostream>
#include <vector>

/**
 * -2,1,-3,4,-1,2,1,-5,4
 * -2|1|-2|4|3 |5|6|1 |5
 * calculate the maximum sum in every location and store the value. If the previous sum is greater than the current value,
 * store the previous value as the maximum sum. Then, print the maximum value. Maximum sum is 6, not, optimize that without
 * an array, and use a variable to store the previous value, which is the sum in this case and the maximum is the ultimate maximum
 * in the whole array.
 */

using namespace std;

int maxSubArray(vector<int>& A)
{
    int sum = 0, maximum = 0;

    maximum = sum = A[0];   //maximum is initialized to the 1st element, in case array has only one element

    for (int i = 1;i < A.size(); i ++) {
        sum = max(A[i], A[i] + sum);
        maximum = max(maximum, sum);
    }

    return maximum;
}


int main()
{
    vector<int> A{-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max sum:" << maxSubArray(A) << endl;
    return 0;
}
