
using umap = unordered_map<int, int>;
using vec2d = vector<vector<int>>;
using setvec = set<vector<int>>;
    
// This is O(n^3) solution, there is a better solution below
vector<vector<int>> threeSum(vector<int>& a) {
    umap nums;
    setvec res;
	int i = 0;
  
    for (int i =0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (j == i) continue;
            for (int k = 0; k < a.size(); k++) {
                if (k == i || k == j) continue;
                if (a[i] + a[j] + a[k] == 0) {
                    vector<int> temp {a[i], a[j], a[k]};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
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

// This is O(n^2) solution, ref: - https://en.wikipedia.org/wiki/3SUM

vector<vector<int>> threeSum(vector<int>& s) {
    
    sort(s.begin(), s.end());
    
    int a, b , c, start, end, n = s.size();
    setvec res;
    for (int i = 0; i < n-2; i ++) {
        a = s[i];
        start = i + 1;
        end = n - 1;
        while (start < end) {
            b = s[start];
            c = s[end];
            
            if (a + b + c == 0) {
                vector<int> temp({a, b, c});
                res.insert(temp);
                start = start + 1;
                end = end - 1;
            } else if (a + b + c > 0) {
                end = end - 1;
            } else {
                start = start + 1;
            }
        }
    }
        
    vec2d ret;
    for (auto& s:res) {
        ret.push_back(s);
    }
	
    return ret;
}
