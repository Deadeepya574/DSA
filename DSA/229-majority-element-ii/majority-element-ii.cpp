class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i =0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }
            else if (m[nums[i]]>=1){
                m[nums[i]]++;
            }
            if(m[nums[i]] > nums.size()/3 && m[nums[i]] >=1 ){
                res.push_back(nums[i]);
                m[nums[i]] = 0;
            }
        }
        return res;
    }
};