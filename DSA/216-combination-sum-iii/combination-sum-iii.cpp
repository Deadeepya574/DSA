class Solution {
public:
void solve(int k, int n,vector<vector<int>>& res,vector<int>& curr,vector<int>& vis,int sum ,int start){
    if(sum == n && k == 0){
        res.push_back(curr);
        return ;
    }
    for(int i = start;i<=9;i++){
        if(vis[i-1] == 1){
            continue;

        }
        vis[i-1] = 1;
        curr.push_back(i);
        sum += i;
        k--;
        solve(k,n,res,curr,vis,sum,i+1);
        k++;
        sum -= i;
        curr.pop_back();
        vis[i-1] = 0; 
        }
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<int> vis(9,0);
        solve(k,n,res,curr,vis,0,1);
        return res;
    }
};