class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;

        for(int i = 0; i < nums.size()-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<nums.size()-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int lo = j+1, hi = nums.size()-1;
                int mid = (lo+hi)/2;
                
                while(lo < hi) {
                    long long int sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[lo] + (long long int)nums[hi];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        int last_lo = nums[lo];
                        int last_hi = nums[hi];
                        while(lo < hi && nums[lo] == last_lo) lo++;
                        while(lo < hi && nums[hi] == last_hi) hi--;
                    }
                    else if(sum > target) hi--;
                    else lo++;
                }
            }
        }
        return ans;
    }
};