class Solution {
public:
    bool sumGame(string num) {

        int leftsum = 0;
        int rightsum = 0;

        int left = 0;
        int right = 0;

        for(int i = 0; i < num.length() / 2; i++) {
            if(num[i] != '?') {
                leftsum += num[i] - '0';
            }
            else {
                left++;
            }
        }

        for(int i = num.length() / 2; i < num.length(); i++) {
            if(num[i] != '?') {
                rightsum += num[i] - '0';
            }
            else {
                right++;
            }
        }

       int diff = leftsum - rightsum;
        int qdiff = left - right;
 
        return diff != -qdiff * 9 / 2 || (qdiff % 2 != 0);
    }
};