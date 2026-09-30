class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        for(int i =0;i<strs[0].size();i++){ 
                char c = strs[0][i];
                int j =0;
                while(j < n){
                    if(i >= strs[j].size() || strs[j][i] != c){
                        return res;                    
                    }
                    j++;
                }
                res.push_back(c);                
            
        }
        
    return res;
    }
};