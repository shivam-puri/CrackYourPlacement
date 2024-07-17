// Bruteforce Approach :  Nested loops
// Time Complexity : O(N^2)  |  Space Complexity : O(1)
// Approach : 1. Traverse the array with a for loop with a nested for loop. 
// 2. the outer for points at first element and the inner for loop points at second element 
// 3. The moment first and second element's sum == target, return the first and second index


// Better Approach : using unordered_map
// Time Complexity : O(N) | Space Complexity : O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            if(map.count(nums[i])) {
                return {map[nums[i]], i};
            }
            else map[target - nums[i]] = i;
        }
        return {};
    }
};

// Another better approach : Two pointers approach 
// Time Complexity : O(N*logN) | Space Complexity : O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end());

        int left = 0, right = nums.size()-1;
        while(left < right) {
            if(pairs[left].first + pairs[right].first == target) return {pairs[left].second, pairs[right].second};
            else if(pairs[left].first + pairs[right].first > target) right--;
            else left++;
        }

        return {};
    }
};