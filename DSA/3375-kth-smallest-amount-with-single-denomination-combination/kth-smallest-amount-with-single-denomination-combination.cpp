class Solution {
public:

    long long lc_m(vector<int>& nums) {
        if (nums.empty()) return 1;

        long long ans = 1;

        for (int x : nums) {
            ans = lcm(ans, (long long)x);
        }

        return ans;
    }

    long long count(vector<int>& coins, long long mid) {

        long long count = 0;

        vector<int> res;

        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= mid) {
                res.push_back(coins[i]);
            }
        }

        int n = res.size();

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++) {

            vector<int> nums;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    nums.push_back(res[i]);
                }
            }

            long long LCM = lc_m(nums);

            if (LCM > mid)
                continue;

            long long ways = mid / LCM;

            if (nums.size() % 2 == 1) {
                count += ways;
            }
            else {
                count -= ways;
            }
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        sort(coins.begin(), coins.end());

        long long left = coins[0];

        long long right = 1LL * k * coins[0];

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            if (count(coins, mid) >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};