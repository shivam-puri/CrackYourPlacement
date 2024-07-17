// Revision Count : 0
// Sliding Window Approach
// Time Complexity : O(N * (N-1/2))  ~  O(N^2)  |  Space Complexity : O(1)

// TLE on leetcode

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int window = 0, initialSum = 0;
        int ans = 0;

        while(window < nums.size()) {
            int currSum = initialSum;
            int left = 0, right = window;
            
            while(right < nums.size()) {
                currSum += nums[right++];
                if(currSum%k == 0) ans++;
                currSum -= nums[left++];
            }

            initialSum += nums[window];
            window++;
        }

        return ans;
    }
};

// 4 5 0