// Revision Count : 0

// BruteForce Approach  : Generate all possible subarrays and calculate the sum in each subarray 
// Time Complexity : O(N^3)  |  Space Complexity : O(1)

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

// Remainder Approach
// TimeComplexity : O(N)  |  Space Complexity : O(1)

// Explanation
// 1. create an array with prefix sum. e.g. for 1 2 3 prefix sum array will be -> 1 3 6
// 2. create another array storing the remainders at every elements when divided by k. . e.g. take k = 3 then 1, 3, 6 will become : 1, 0, 0
// 3. each time you get a number which repeats add the previous frequency of that element

// Resource : https://www.youtube.com/watch?v=QM0klnvTQzk

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int preSum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            nums[i] = preSum;
            int remainder = preSum%k >= 0 ? preSum%k : preSum%k+k;
            if(map.count(remainder)) {
                ans += map[remainder];
                map[remainder]++;
            } else map[remainder]++;
        }

        return ans;
    }
};