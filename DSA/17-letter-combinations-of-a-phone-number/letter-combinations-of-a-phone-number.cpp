class Solution {
public:
    void solve(string digits, vector<string>& res,
               vector<vector<char>>& store, string s, int ind) {

        if(ind == digits.size()) {
            res.push_back(s);
            return;
        }

        int num = digits[ind] - '0';

        for(char ch : store[num]) {
            s.push_back(ch);

            solve(digits, res, store, s, ind + 1);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<vector<char>> store(10);

        store[2] = {'a','b','c'};
        store[3] = {'d','e','f'};
        store[4] = {'g','h','i'};
        store[5] = {'j','k','l'};
        store[6] = {'m','n','o'};
        store[7] = {'p','q','r','s'};
        store[8] = {'t','u','v'};
        store[9] = {'w','x','y','z'};

        vector<string> res;

        solve(digits, res, store, "", 0);

        return res;
    }
};