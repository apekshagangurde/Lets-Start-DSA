//https://www.youtube.com/watch?v=Bxgq2ILCsfQ&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S
//https://leetcode.com/problems/merge-strings-alternately/description/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        bool flag = true; // Start with word1
        
        // Iterate while there are characters left in either word1 or word2
        while (i < word1.length() || j < word2.length()) {
            if (flag) {
                if (i < word1.length()) {
                    result += word1[i++];
                }
            } else {
                if (j < word2.length()) {
                    result += word2[j++];
                }
            }
            flag = !flag; // Toggle the flag
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "123456";
    
    string merged = sol.mergeAlternately(word1, word2);
    cout << "Merged string: " << merged << endl; // Output: "a1b2c3456"
    
    return 0;
}
