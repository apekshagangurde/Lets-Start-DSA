//https://leetcode.com/problems/delete-columns-to-make-sorted/
//https://www.youtube.com/watch?v=tFQWBeljuaU&list=PLpIkg8OmuX-KRHVXwqSixQC9UE6DsHnWa&index=11
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // Get the number of strings in the vector
        int n = strs.size();

        // Get the length of the first string (assuming all strings are of the same length)
        int k = strs[0].length();

        // Initialize a counter to keep track of the number of columns to delete
        int count = 0;

        // Loop through each column
        for (int i = 0; i < k; i++) {
            // Check if the column is sorted
            for (int j = 1; j < n; j++) {
                // If the current string's character is less than the previous string's character in the same column
                if (strs[j][i] < strs[j-1][i]) {
                    // Increment the counter
                    count++;
                    // No need to check further, as this column needs to be deleted
                    break;
                }
            }
        }
        
        // Return the number of columns that need to be deleted
        return count;
    }
};
