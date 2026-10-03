class Solution {
public:
    int count = 0;

    void solve(int n, int ind, vector<int>& vis) {

        if(ind > n) {
            count++;
            return;
        }

        for(int i = 1; i <= n; i++) {

            if(vis[i]) continue;

            if(i % ind == 0 || ind % i == 0) {

                vis[i] = 1;

                solve(n, ind + 1, vis);

                vis[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> vis(n + 1, 0);

        solve(n, 1, vis);

        return count;
    }
};