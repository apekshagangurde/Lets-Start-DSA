//https://www.youtube.com/watch?v=3ZuLKFPsYv8&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=2
//https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
class Solution {
public:
    // Function to calculate the GCD of two integers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to get the greatest common divisor of two strings
    string gcdOfStrings(string str1, string str2) {
        // Check if both strings are equal
        if (str1 + str2 != str2 + str1) {
            return ""; // If concatenated results differ, there is no common divisor
        }

        // Get lengths of both strings
        int a = str1.length();
        int b = str2.length();

        // Calculate GCD of the lengths
        int gcdLength = gcd(a, b);

        // Return the substring of length gcdLength from str1
        return str1.substr(0, gcdLength);
    }
};
//time complexity  o(m+n)
