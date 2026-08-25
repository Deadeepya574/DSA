class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int left = 0;
        int tot = 0;

        for(int i = 0; i < nums.size(); i++) {
 
            if(i == 0 || nums[i] != nums[i - 1]) {

                count = 1;

                nums[left] = nums[i];
                left++;
                tot++;

            }
      
            else {

                count++;
                if(count <= 2) {

                    nums[left] = nums[i];
                    left++;
                    tot++;
                }
            }
        }

        return tot;
    }
};