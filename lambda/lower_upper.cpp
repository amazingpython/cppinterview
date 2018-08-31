/**
 * This lambda function, find out a lower and upper closest value to the target, NOT THE LOWER/UPPER BOUND, REFER, lower_bound/upper_bound
 * FOR THAT. Say for example, in a list [-4, -1, 1, 2, 5, 6] and target=1, closest lower value is -1 and closest upper value 2.
 * Output: -1	2
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

	auto [lower, upper] = [&]()->tuple<int,int> {
					int min = s[0], max = s[s.size() - 1];
					for (const auto& n:s) {
						if (min < n && n < target)
							min = n;
						if (max > n && n > target)
							max = n;
					}
					return {min, max};
			     	}();


	cout << lower << "\t" << upper << endl;

	return 0;
}
