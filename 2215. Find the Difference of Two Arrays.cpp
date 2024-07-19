//https://leetcode.com/problems/find-the-difference-of-two-arrays/
//https://www.youtube.com/watch?v=2T2Bw-M7Wv0&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=19
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Use unordered_set to store unique elements from both arrays
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans1;
        vector<int> ans2;

        // Find elements in nums1 that are not in nums2
        for (int val : nums1) {
            if (set2.find(val) == set2.end()) {
                if (find(ans1.begin(), ans1.end(), val) == ans1.end()) {
                    ans1.push_back(val);
                }
            }
        }

        // Find elements in nums2 that are not in nums1
        for (int val : nums2) {
            if (set1.find(val) == set1.end()) {
                if (find(ans2.begin(), ans2.end(), val) == ans2.end()) {
                    ans2.push_back(val);
                }
            }
        }

        // Return the result as a vector of vectors
        return {ans1, ans2};
    }
};
