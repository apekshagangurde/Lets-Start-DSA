//https://www.youtube.com/watch?v=Q7gIQ-sP5jI&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=14
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;

        // Helper function to check if a character is a vowel
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Calculate the number of vowels in the first window of size k
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        ans = count; // Initialize the maximum count with the first window's count

        // Slide the window across the string
        for (int i = k; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                count++; // Increment count if the new character is a vowel
            }
            if (isVowel(s[i - k])) {
                count--; // Decrement count if the character leaving the window is a vowel
            }
            ans = max(ans, count); // Update the maximum count
        }

        return ans;
    }
};
