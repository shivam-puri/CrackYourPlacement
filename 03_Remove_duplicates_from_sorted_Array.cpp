class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        int counter = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(map.count(nums[i]) == 0) map[nums[i]] = counter++; 
        }

        for(auto i : map) {
            nums[i.second] = i.first;
        }

        return map.size();
    }
};



// Optimal Approach 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size() < 2) return nums.size();
       int last_unique = 1, currentptr = 1, k = 1;
       while(currentptr < nums.size()) {
        if(nums[currentptr] != nums[currentptr-1]) {
            nums[last_unique] = nums[currentptr];
            last_unique++;
            currentptr++;
            k++;
        }else currentptr++;
       }

       return k;
    }
};