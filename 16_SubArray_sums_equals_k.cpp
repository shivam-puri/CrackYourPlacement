// Revision Count : 0
// similar problem : Subarray sum divisible by k

/*
Let's say we want the solution for 0.
If you have a number 'A', then adding '-A' gives you 0.

If you make a prefix sum table (sum[]) from the given array (nums []), the difference of sum[j]-sum[i] is the sum of items from i+1 to j.

for example,
index : 0 1 2 3
nums : 6 -1 -3 4
sum : 6 5 2 6

In this case, sum[3]-sum[0] is 0. And it is the same as sum of items index 1 to 3.

So you keep add up the element value, and if the current sum at index 'i' is 'S', and say there WAS a index 'j' where the sum was 'S', you found a solution. Summing each values from 'j+1' to 'i' will give the sum 0.

Now just change the target value from 0 to 'sum - k' and you just need to add those occurrences. That's it.

The catch here is that there can be many occurrences that makes the range sum as 0 (or 'sum - k' in our original problem case), you need to count all those occurrences. That's why you see 'ans+=mp[find]' in the code.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> map;
        map[sum] = 1;

        for(auto it : nums) {
            sum += it;
            if(map.find(sum - k) != map.end()) {
                ans += map[sum-k];
            }
            map[sum]++;
        }
        return ans;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0, initialSum = nums[0], window = 0; 
        while(window < nums.size()) {
            int left = 0, right = window;
            int currSum = initialSum;
            while(right+1 < nums.size()) {
                if(currSum == k) ans++;
                currSum -= nums[left++];
                right++;
                currSum += nums[right];
            }
            if(currSum == k) ans++;
            window++;
            if(window < nums.size()) initialSum += nums[window];
            else break;
        }
        return ans;
    }
};