class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // for(int i = m ; i < m+n ; i++){
        //     nums1[i] = nums2[i - m];
        // }
        // sort(nums1.begin(),nums1.end());


        // Two Pointer Solution
          int left = m - 1;
        int right = n - 1;
        int index = m + n - 1;

        while(left >= 0 && right >= 0) {

            if(nums1[left] > nums2[right]) {
                nums1[index] = nums1[left];
                left--;
            }
            else {
                nums1[index] = nums2[right];
                right--;
            }

            index--;
        }

        // If nums2 still has elements
        while(right >= 0) {
            nums1[index] = nums2[right];
            right--;
            index--;
        }
    }
};