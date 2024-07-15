// Revision Count : 0
// Optimal Approach : Rabbit and tortoise approach | Linked list Cycle Approach
// Time Complexity - O(N)  | Space Complexity - O(1)
// Explanation : https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = 0, fast = 0;
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];

      }while(slow != fast);

       slow = 0;
       while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
       }

       return fast;
    }
};

// Other Approaches  
// 1. Sort the array and return the element whose adjacent element is same. 
// Time Complexity - O(N logN) | Space Complexity - O(1)

// 2. Use a frequency map array (size N+1) and increment the value of each index, as soon as an element appears. Return the index of frequency 2
// Time Complexity - O(N) | Space Complexity - O(N)