class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num = prices[0];
        int max = 0;
        for(int i = 1;i<prices.size();i++){
            if(i == 1){
                if(prices[i] - num > 0){
                    max = max + (prices[i] - num); 
                }
            }
            else{
                if(prices[i] - prices[i-1] > 0){
                max += prices[i] - prices[i-1];
            }}
        }
        return max;
    }
};