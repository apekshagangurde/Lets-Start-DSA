//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
//https://www.youtube.com/watch?v=AJBMmBRVcjE&list=PL-Jc9J83PIiEA7f_cI_v6oqh_EYWboj6S&index=3
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies
        int maxCandies = candies[0];
        for (int i = 1; i < candies.size(); ++i) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }

        // Create a result vector
        vector<bool> result;

        // Check each kid
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};
