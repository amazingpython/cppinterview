/**
 * Problem Description: https://leetcode.com/problems/two-sum/description/
 */

vector<int> twoSum(vector<int>& _nums, int target) {

    unordered_map<int, int> numbers;
    size_t i = 0;
        
    for (auto n : _nums) {
    
    auto it = numbers.find(target - n);
    if ( it != numbers.end()) {
        return {it->second, i};
    }
        numbers[n] = i ++;
    }
        return {0, 0};
}
