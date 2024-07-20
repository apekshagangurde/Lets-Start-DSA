//https://www.youtube.com/watch?v=DrVLI_NXaic&list=PLpIkg8OmuX-KRHVXwqSixQC9UE6DsHnWa&index=10
//https://leetcode.com/problems/detect-capital/
class Solution {
public:
 bool allCapital(string word){
    for(char &ch:word){
        if(ch<'A'||ch>'Z'){
            return false;
        }
    }
    return true;
 }
  bool allSmall(string word){
    for(char &ch:word){
        if(ch<'a'||ch>'z'){
            return false;
        }
    }
    return true;
 }



    bool detectCapitalUse(string word) {
        if(allCapital(word)||allSmall(word)||allSmall(word.substr(1))){
        return true;
    }
return false;
} 
};




class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals = 0;

        // Count the number of capital letters in the word
        for (char &ch : word) {
            if (isupper(ch))
                countCapitals++;
        }

        // Check the conditions for correct capital use
        if (countCapitals == 0 || 
            countCapitals == word.length() || 
            (countCapitals == 1 && isupper(word[0]))) {
            return true;
        }
        
        return false;
    }
};
