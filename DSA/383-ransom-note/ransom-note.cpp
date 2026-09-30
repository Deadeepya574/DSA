class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) { 
        unordered_map<char,int> mp2;
        if(magazine.size() < ransomNote.size()){
            return false;
        }
        for(int i = 0;i<magazine.size();i++){ 
            mp2[magazine[i]]++;
        }

        for(int i = 0 ;i<ransomNote.size();i++){
            if(mp2[ransomNote[i]]>=1){
                mp2[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};