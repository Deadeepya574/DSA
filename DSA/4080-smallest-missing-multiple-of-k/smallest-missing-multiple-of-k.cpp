class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i = k;i<=(nums.size()+1)*k;i += k){
            if(s.find(i) == s.end()){
                return i;
            }
        }
        return k;
    }
};