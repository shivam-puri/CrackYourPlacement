// Revision Count : 0

// Bruteforce : O(N^3) 🥴, but still not help in leetcode because : 
// 1. TLE 2. the solution requires unique triplets

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    } 
                }
            }
        }

        return ans;
    }
};

// Approach : Two pointers inside a for loop 
// Time Complexity : O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums[0] > 0) return ans;

        for(int i=0; i < nums.size()-2; i++) {
            if(nums[i] > 0) break;   // no pairs can be formed since min element > 0
            if(i > 0 && nums[i] == nums[i-1]) continue;   // we dont want duplicate triplets
            // Two pointers implementation
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int last_left_val = nums[left], last_right_val = nums[right];
                    // again, we dont want duplicate triplets, therefore we are moving left and right
                    // until the skip all the values same as last_left_val || last_right_val if present
                    while(left < nums.size() && nums[left] == last_left_val) {
                        left++;
                    }
                    while(right > 0 && nums[right] == last_right_val) {
                        right--;
                    }

                }
                else if(sum > 0) right--;
                else left++;
            }
        }

        return ans;
    }
};

// Hashmap Approach (from leetcode) : 

/*
In this approach, firstly, we will hash the indices of all elements in a hashMap. In case of repeated elements, the last occurence index would be stored in hashMap.

Here also we fix a number (num[i]), by traversing the loop. But the loop traversal here for fixing numbers would leave last two indices. These last two indices would be covered by the nested loop.
If number fixed is +ve, break there because we can't make it zero by searching after it.
    Make a nested loop to fix a number after the first fixed number. (num[j])
    To make sum 0, we would require the -ve sum of both fixed numbers. Let us say this required.
    Now, we will find the this required number in hashMap. If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet. Push it in answer vector.
    Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
    Update i to last occurence of 1st fixed number to avoid duplicate triplets.
    Return answer vector.
    My HashMap Submission:
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());     //Sorted Array
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        unordered_map<int , int> hashMap;
        for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
            hashMap[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};