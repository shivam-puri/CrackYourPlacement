// Revision Count : 0

// Bruteforce Approach
// Time Complexcity - O(N*N)
// Idea - Do Check Double Time For Each element

// Approach : Using hashmap
// Time Complexity : O(N)  | Space Complexity : O(N)
// Create unordered_map, store the frequencies of each element in map, the moment an element appears second time in the map, push it in the final Answer array


// Approach : Sorting
// Time complexity : O(N logN)
// if adjacent element is same, push in ans and increment the counter by 2, else increment the counter by 1

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) ans.push_back(nums[i++]);
        }
        return ans;
    }
};

// Optimal Approach : marking negative
// Time Complexity : O(N)
// If any element is visited mark it negative. if you find any negative element in the array, that's one of ur ans;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
       for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0) ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
       }

       return ans;
    }
};