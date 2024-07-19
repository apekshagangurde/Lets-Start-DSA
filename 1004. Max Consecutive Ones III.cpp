//https://leetcode.com/problems/max-consecutive-ones-iii/
//https://www.youtube.com/watch?v=tqoi8-Msrjg&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=15
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0; // Right pointer
        int j = -1; // Left pointer (starts from -1 for convenience)
        int countZeroInWindow = 0; // Count of zeros in the current window

        while (i < nums.size()) {
            if (nums[i] == 0) {
                countZeroInWindow++;
            }
            i++;

            while (countZeroInWindow > k) {
                j++;
                if (nums[j] == 0) {
                    countZeroInWindow--;
                }
            }

            int sizeOfWindow = i - j - 1;
            ans = max(ans, sizeOfWindow);
        }

        return ans;
    }
};
