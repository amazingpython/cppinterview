#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

/**
 * This reverse an integer, with 32 bit limits
 */
using namespace std;

int reverse(int x) {

    int newX = 0, tempX = x, min_limit = INT_MIN/10, max_limit = INT_MAX/10, min_r = INT_MIN%10, max_r = INT_MAX%10;

    while (tempX != 0) {
        newX = newX * 10 + (tempX%10);
        tempX = tempX/10;

        if (x > 0 && newX > max_limit && tempX != 0) return 0;
        if (x < 0 && newX < min_limit && tempX != 0) return 0;
        if (x > 0 && newX == max_limit && tempX > max_r) return 0;
        if (x < 0 && newX == min_limit && tempX < min_r) return 0;
    }

    //cout << newX << " " << INT_MAX << " " << INT_MIN << endl;

    return newX;
}


int main()
{
    cout << reverse(-123) << endl;
    return 0;
}
