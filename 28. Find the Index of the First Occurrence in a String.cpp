//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//https://www.youtube.com/watch?v=7UBEku3y2Ig&list=PLpIkg8OmuX-KRHVXwqSixQC9UE6DsHnWa&index=14
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();  // Length of the haystack string
        int n = needle.size();    // Length of the needle string

        // Loop through the haystack, ensuring we do not go past the point where the needle would fit
        for (int i = 0; i <= m - n; i++) {
            int j = 0;  // Initialize j for each new position i in haystack

            // Loop through the needle to compare with the corresponding part of the haystack
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;  // If characters do not match, break out of the inner loop
                }
            }

            // If we have compared all characters of the needle, return the start index
            if (j == n) {
                return i;
            }
        }

        // If the needle is not found in the haystack, return -1
        return -1;
    }
};
