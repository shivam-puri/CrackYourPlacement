// Revision Count : 0
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    int ans = 0;
    void merge(vector<int> &nums, int lo, int mid, int hi) {
       vector<int> temp;
        int left = lo, right = mid+1;

        while(left <= mid && right <= hi) {
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= hi) temp.push_back(nums[right++]);

        for(int i = lo; i <= hi; i++) {
            nums[i] = temp[i-lo];
        }
    }
    void countReversePairs(vector<int> &nums, int lo, int mid, int hi) {
       int right = mid+1;
       for(int i = lo; i<=mid; i++) {
            while(right <= hi && (long long int)nums[i] > (long long int)2*nums[right]) right++;
            ans += (right-(mid+1));
       }
    }

    void solve(vector<int> &nums,  int lo, int hi) {
        if(lo >= hi) return;
        int mid = (lo+hi)/2;
        solve(nums, lo, mid);
        solve(nums, mid+1, hi);
        countReversePairs(nums, lo, mid, hi);
        merge(nums, lo, mid, hi);
    }

    int reversePairs(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        for(auto i: nums) cout << i << " ";
        return ans;
    }
};