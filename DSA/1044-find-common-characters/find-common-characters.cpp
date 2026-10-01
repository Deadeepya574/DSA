class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<char> res;
        for(char x : words[0]){
            res.push_back(x);
        } 
        int i = 1;
        while(i<words.size()){
             int j = 0;

            while(j < res.size()) {
                int pos = words[i].find(res[j]);

                if(pos != string::npos) {
                    words[i].erase(pos, 1);
                    j++;
                }
                else {
                    res.erase(res.begin() + j);
                }
            }

            i++;
        }
        vector<string> ans;

        for(char c : res) {
            ans.push_back(string(1, c));
        }

        return ans;
        }
    
};