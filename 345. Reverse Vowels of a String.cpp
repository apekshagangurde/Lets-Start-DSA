//https://leetcode.com/problems/reverse-vowels-of-a-string/
//https://www.youtube.com/watch?v=9cl3tne0rNU&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=5
class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert to lowercase for uniform checking
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int li = 0; // Left pointer
        int ri = s.size() - 1; // Right pointer

        // Convert string to a char array for in-place modifications
        vector<char> arr(s.begin(), s.end());

        // Two-pointer technique to swap vowels
        while (li < ri) {
            // Move the left pointer to the next vowel
            while (li < ri && !isVowel(arr[li])) {
                li++;
            }

            // Move the right pointer to the previous vowel
            while (li < ri && !isVowel(arr[ri])) {
                ri--;
            }

            // Swap vowels if both pointers are at vowels
            if (li < ri) {
                swap(arr[li], arr[ri]);
                li++;
                ri--;
            }
        }

        // Convert char array back to string
        return string(arr.begin(), arr.end());
    }
};
