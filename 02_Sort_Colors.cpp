// Revision Count : 0
// BruteForce Approach : Sorting
// Time Complexity - O(NlogN) | Space Complexity - O(1)

// Better Approach : Keep count of values
// Time Complexity - O(N) | Space Complexity - O(N)

// Optimal Approach : Three Pointers Approach
// Time Complexity - O(N) | Space Complexity - O(1)

// Approach : 
// 1. Create three pointers lo, mid and hi
// 2. initialize low and mid from 0th index and high from last index
// 3. Traverse the array while mid pointer is <= high pointer
// 4. if mid pointer encounters '2' than swap it with high pointer and decrement the high pointer
//    which will be the position of next '2' (if encountered in future in the array)
// 5. if mid pointer encounters '1' than ignore it and increment the mid pointer
// 6. if mid pointer encounters '0' than swap it with the low pointer (which contains the position (or index) of next zero to be placed)
//    than increment the low pointer (to update the position of next zero to be placed)
//    also update the value of mid. mid = max(mid, low);    (why?  because : mid should always be >= low)

class Solution {
public:
    void sortColors(vector<int>& nums) {
       if(nums.size() == 1) return;

       int lo=0, mid=0, hi=nums.size()-1;

        while(mid <= hi) {
            switch(nums[mid]) {
                case 1:
                mid++;
                break;
                
                case 2: 
                swap(nums[mid], nums[hi]);
                hi--;
                break;

                case 0:
                swap(nums[mid], nums[lo]);
                lo++;
                mid = max(mid, lo);
                break;
            }
        }
    }
};