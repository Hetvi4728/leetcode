class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int buy = prices[0];

        for(int val : prices){
            if(val < buy){
                buy = val;
            }
            else if(val - buy > max){
                max = val - buy;
            }
        }
        return max;
    }
};