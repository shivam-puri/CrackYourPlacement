// Revision Count : 0
// BruteForce Approach 
// Time Complexity - O(N^2) | Space Complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < prices.size()-1; i++) {
            for(int j = i+1; j < prices.size(); j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }

        return ans;
    }
};


// Optimal Approach : 
// Time Complexity - O(N) | Space Complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int mini = prices[0], profit = 0;

       for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i]-mini);
            mini = min(mini, prices[i]);
       }

       return profit;
    }
};