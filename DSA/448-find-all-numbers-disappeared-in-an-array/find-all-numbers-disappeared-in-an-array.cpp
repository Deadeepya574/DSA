class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> s;
        vector<int> res;
        for(int i =0 ;i<nums.size();i++){
            s[nums[i]]++;
        }
        for(int i = 1; i<=nums.size();i++){
            if(!s[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};