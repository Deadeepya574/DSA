class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0){
            return true;
        }
        int left = 0; 
        for(int i =0;i<t.size();i++){
            if(t[i] == s[left]){
                left++;
            }
            if(left == s.size()){
                return true;
            }
        }
        return false;
    }
};