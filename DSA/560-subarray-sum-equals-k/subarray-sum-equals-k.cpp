class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Prefix sum 0 exists before we start
        freq[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Current prefix sum
            sum += nums[i];

            // We need an earlier prefix sum = sum - k
            if(freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }

            // Store current prefix sum
            freq[sum]++;
        }

        return count;

    }
};