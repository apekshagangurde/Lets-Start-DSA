
//https://leetcode.com/problems/string-compression/submissions/1317186690/
class Solution {
public:
    int compress(vector<char>& chars) {

      int n=chars.size();

      int index=0;
      int i=0;
      while(i<n){
        char curr_char=chars[i];
        int count=0;
//find counts of duplicates
        while(i<n && chars[i]==curr_char){
            count++;
            i++;
        }

        //assign work
        chars[index]=curr_char;
        index++;
        if(count>1){
            string count_str=to_string(count);
            for(char &ch: count_str){
                chars[index]=ch;
                index++;
            }
        }

        

      }
      
      return index;
      

    }
};
