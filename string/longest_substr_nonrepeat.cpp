#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

//Problem Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//This is implemented in 2 different ways, 1st solution jas a complexity of O(n) and 2nd solution should be O(n^2)

int lenOfLongestSubStringNonRepeat(const string& str)
{
    int s, e, m; //start, end, max
    s = e = m = 0;
    unordered_set<char> arr;

    while (s < str.length() && e < str.length()) { // Complexity O(n)
        if (arr.find(str[e]) == arr.end()) {
            arr.insert(str[e++]);  //Complexity O(1)
        } else {
            arr.erase(str[s++]);  //Complexity O(1)
        }
        m = max(m, e-s);
    }

    return m;
}

int lengthOfLongestSubstring(const string& str) {

    int m = 0; //max
    for (int i = 0; i < str.length(); i ++) {   //Complexity O(n)
        int t = 0;
        unordered_set<char> arr;
        for (int j = i; j < str.length(); j++) {    //Complexity O(n), O(n^2)
            if (arr.find(str[j]) != arr.end()) {    //Complexity O(1)
                break;
            } else {
                arr.insert(str[j]);     //Complexity O(1)
                t ++;
            }
            m = max(m, t);
        }
    return m;
}
