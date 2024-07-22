// Brute Force : Unordered Map
// Time Complexity : O(n)
// Space Complexity : O(n)

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        map[nums[i]]++;
        cout << nums[i] << " " << map[nums[i]] << endl;
        if(map[nums[i]] > nums.size()/2) {
            ans = nums[i];
            break;
        }
    }

    return ans;
}

// Optimized Solution : Boyer-Moore Voting Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    // Boyer-Moore Voting Algorithm 
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;
        for(auto i : nums) {
            if(count == 0) candidate = i;
            if(i == candidate) count++;
            else count--;
        }

        return candidate;
    }
};