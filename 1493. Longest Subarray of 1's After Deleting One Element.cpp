//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//https://www.youtube.com/watch?v=C9QMdVwFvBo&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=16
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0; // To store the length of the longest subarray found
        int i = 0; // Right pointer of the sliding window
        int j = -1; // Left pointer of the sliding window, starting from -1 for convenience
        int count = 0; // Count of zeros in the current window

        while (i < nums.size()) {
            if (nums[i] == 1) {
                // If the current element is 1, simply move the right pointer to the right
                i++;
            } else {
                // If the current element is 0, move the right pointer and increase the zero count
                i++;
                count++;
            }

            while (count > 1 && j < i) {
                // If the count of zeros exceeds 1, move the left pointer to the right
                j++;
                if (nums[j] == 0) {
                    // If the element leaving the window is 0, decrease the zero count
                    count--;
                }
            }

            // Calculate the size of the current window
            ans = max(ans, i - j - 1);
        }

        // The final result is the length of the longest subarray found
        return ans-1;
    }
};
