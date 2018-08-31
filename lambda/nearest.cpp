/**
 * This lambda function, find out a nearest integer number in a vector. Nearest is closest to the tatget.
 * Say for example, in a list [-4, -1, 1, 2, 5, 6] and target=1, the nearest will be 2.
 * Closest minimum value of target is -1 and closest maximum value of the target is 2, but the closest
 * between these two values will be 2.
 * Output: 2
 */

#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
	vector<int> s = {-4, -1, 1, 2, 5, 6};
	int target = 1;

	auto nearest = [&]()->int {
					int min = s[0], max = s[s.size() - 1];
					for (const auto& n:s) {
						if (min < n && n < target)
							min = n;
						if (max > n && n > target)
							max = n;
					}
					if (target - min > max - target)
						return max;
					else return min;
			     	}();


	cout << nearest << endl;

	return 0;
}
