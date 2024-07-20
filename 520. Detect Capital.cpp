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
