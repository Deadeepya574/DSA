class Solution {
public:
    int lengthOfLastWord(string s) {
        int prev = 0;
        int count =0;
        for(int i =0;i<s.size();i++){
            if(s[i] == ' '){
                if(count != 0) prev = count;
                count =0;
            }
            else{
                count++;
            }
        
        }
        return (count == 0)? prev : count ;
    }
};