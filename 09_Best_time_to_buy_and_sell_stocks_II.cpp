// Revision Count : 0
// Optimal Approach
// Time Complexity : O(N)  |  Space Complexity : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            if(prices[i] - buy > 0) {
                profit += (prices[i] - buy);
                buy = prices[i];
            }
        }
        return profit;
    }
};