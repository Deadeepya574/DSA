class Solution {
public:
    vector<string> ans;

    void solve(string num, int target, int ind,
               long long curr, long long last,
               string expr) {

        if(ind == num.size()) {
            if(curr == target) {
                ans.push_back(expr);
            }
            return;
        }

        for(int i = ind; i < num.size(); i++) { 
            if(i > ind && num[ind] == '0')
                break;

            string part = num.substr(ind, i - ind + 1);
            long long val = stoll(part); 
            if(ind == 0) {
                solve(num, target, i+1, val, val, part);
            }
            else { 
                solve(num, target, i+1,
                      curr + val, val,
                      expr + "+" + part); 
                solve(num, target, i+1,
                      curr - val, -val,
                      expr + "-" + part); 
                solve(num, target, i+1,
                      curr - last + last * val,
                      last * val,
                      expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, 0, 0, "");

        return ans;
    }
};