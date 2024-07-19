https://leetcode.com/problems/move-zeroes/description/
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int nonZeroIndex = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is non-zero, move it to the front
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        // Fill the remaining elements with zeros
        while (nonZeroIndex < nums.size()) {
            nums[nonZeroIndex++] = 0;
        }
    }
};



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer for the position of the next non-zero element
        int i = 0; // Pointer to traverse the array

        while (i < nums.size()) {
            if (nums[i] == 0) {
                i++;
            }else{
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
            
        }
    }
};
