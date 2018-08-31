/**
 * Problem ref: - https://leetcode.com/problems/3sum-closest/description/
 */

int threeSumClosest(vector<int>& s, int target) {
    sort(s.begin(), s.end());
    vector<int> res;
    
    int a, b , c, start, end, n = s.size();
        
    for (int i = 0; i < n-2; i ++) {
        a = s[i];
        start = i + 1;
        end = n - 1;
        while (start < end) {
            b = s[start];
            c = s[end];
            
            if (a + b + c == target) {
                return target;
                start = start + 1;
                end = end - 1;
            } else if (a + b + c > target) {
                end = end - 1;
                res.push_back(a + b + c);
            } else {
                start = start + 1;
                res.push_back(a + b + c);
            }
        }
    }
            
    sort(res.begin(), res.end());
        
    auto nearest = [&]()->int {
        int min = res[0], max = res[res.size() - 1];
        for (const auto& n:res) {
            if (min < n && n < target)
            min = n;
            if (max > n && n > target)
                max = n;
        }
        if (target - min > max - target)
            return max;
        else return min;
    }();
    
    return nearest;
    }
