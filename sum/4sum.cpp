    /**
     * Problem ref :- https://leetcode.com/problems/4sum/description/
     */
    
    using vec2d = vector<vector<int>>;
    using setvec = set<vector<int>>;
    
    vector<vector<int>> fourSum(vector<int>& s, int target) {
        
    sort(s.begin(), s.end());
    
    int a, b , c, d, start, end, n = s.size();
    setvec res;
    for (int i = 0; i < n-3; i ++) {
        a = s[i];
        for (int j = i + 1; j < n -2; j++) {
            b = s[j];
            start = j + 1;
            end = n - 1;
            while (start < end) {
                c = s[start];
                d = s[end];
            
                if (a + b + c + d == target) {
                    vector<int> temp({a, b, c, d});
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                    start = start + 1;
                    end = end - 1;
                } else if (a + b + c + d > target) {
                    end = end - 1;
                } else {
                    start = start + 1;
                }
            }
        }
    }
        
    vec2d ret;
    for (auto& s:res) {
        ret.push_back(s);
    }
	
    return ret;
    }
