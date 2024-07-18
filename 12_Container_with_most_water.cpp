// Revision Count 0

// Bruteforce approach
// check all possibilities and store the maximum area
// Time Complexity : O(N*N)

// Two Pointer approach
// Time Complexity : O(N)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1;
        
        while(left < height.size() && right >=0 && left < right) {
            // calculating the current water stored
            int currWater = min(height[left], height[right])*(right-left);
            // updating ans if new maximum is encountered
            ans = max(ans, currWater);
            // we need to either decrement left or increment right pointer, to check more possibilities.
            // now when we increment left we lose the water on the left, and when we decrement right ptr, we lose the water stored at right
            // the choice is ours, and we choose to lose the minimum, inorder to store maximum.
            // we can lose minimum if we move the counter whose value is smaller. hence smaller amount of water will be lost.
            if(height[left] < height[right]) left++;
            else right--;
        }

        return ans;
    }
};