//https://www.youtube.com/watch?v=KbdCp4nUDiQ&list=PLpIkg8OmuX-KRHVXwqSixQC9UE6DsHnWa&index=9
//https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1326846153/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Get the lengths of both words
        int m=word1.size();
        int n=word2.size();
        // If the lengths are not equal, the strings can't be close
if(m!=n)
return false;

 // Create frequency vectors for both words with 26 slots (one for each letter)
        vector<int>freq1(26);
        vector<int>freq2(26);
        // Populate the frequency vectors

        for(int i=0;i<m;i++){
            char ch1=word1[i];
            char ch2=word2[i];
            int idx1=ch1-'a';
             int idx2=ch2-'a';
            freq1[idx1]++;
            freq2[idx2]++;
        }

        // Check if both strings contain the same set of unique characters
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0) continue;
            return false;

        }
        // Sort the frequency vectors
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};
