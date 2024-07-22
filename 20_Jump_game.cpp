// Recursive Solution : TLE on leetcode
// Time Complexity : O(2^N)  |  Space Complexity : O(N)

class Solution {
public:
    bool solve(vector<int> &nums, int index) {
        if(index >= nums.size()-1) return true;
        if(nums[index] == 0) return false;
        
        for(int i = nums[index]; i >= 1; i--) {
            if(solve(nums, index + i)) return true;
        }

        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};

// Memoized Solution
// Time Complexity : O(n*m) where m is max element
// SC : O(n)

class Solution {
public:
    bool solve(vector<int> &nums, int index, vector<int> &dp) {
        if(index >= nums.size()-1) return true;
        if(nums[index] == 0) return false;

        if(dp[index] != -1) return dp[index];
        
        for(int i = nums[index]; i >= 1; i--) {
            if(solve(nums, index + i, dp)){
                return dp[index] = true;
            }
        }
        dp[index] = false;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};

// Tabular Solution DP : 

class Solution {
public:
// initialize a vector dp with all values 0.
// mark the last index as true
// traverse it from the secondlast index till the 0th index
// at each index check whether we can reach the last element or not.
// if we can, than put dp[index] = true or 1 for that index
// else put false there
// return dp[0]

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;
        
        for(int index = n-2; index >= 0; index--) {
            // no way you can reach the end from this index 🙅🏻‍♀️
            if(nums[index] == 0) {
                dp[index] = false;
                continue;
            }

            bool flag = false;
            for(int i = nums[index]; i >= 1; i--) {
                if(index + i < n && dp[index + i]) {
                    dp[index] = true;
                    flag = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};