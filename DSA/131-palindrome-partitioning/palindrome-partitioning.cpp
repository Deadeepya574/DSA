class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    void solve(string s, int ind, vector<string>& path) {

        if(ind == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = ind; i < s.size(); i++) {

            string sub = s.substr(ind, i-ind+1);

            if(isPalindrome(sub)) {

                path.push_back(sub);

                solve(s, i+1, path);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);
        return ans;
    }
};