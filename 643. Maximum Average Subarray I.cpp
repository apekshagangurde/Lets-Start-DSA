//https://leetcode.com/problems/maximum-average-subarray-i/
//https://www.youtube.com/watch?v=d7sl7l7IWb4&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=13

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0; // To store the sum of the current window
        double avg = 0.0; // To store the average of the current window
        double ans = -1.0; // To store the maximum average
        
        // Calculate the sum of the first window of size k
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        
        // Initialize the average with the first window's average
        avg = static_cast<double>(sum) / k;
        ans = avg;
        
        // Slide the window across the array
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k]; // Update the sum by adding the new element and removing the old one
            avg = static_cast<double>(sum) / k; // Calculate the new average
            ans = max(ans, avg); // Update the maximum average
        }
        
        return ans;
    }
};
