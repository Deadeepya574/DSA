class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Remainder 0 before starting
        freq[0] = 1;

        int sum = 0;
        int count = 0;

        for(int x : nums) {

            sum += x;

            int rem = sum % k;

            // C++ can give negative remainder
            if(rem < 0)
                rem += k;

            // Same remainder -> valid subarrays
            count += freq[rem];

            // Store this remainder
            freq[rem]++;
        }

        return count;
    }
};