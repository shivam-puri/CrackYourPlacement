// Revision count : 0

// Sliding Window Approach : 
// Time Complexity : O(2*k) ~ O(k)
// Explanation : take a window of size k, with its left = 0, and right = k-1 in the array
// slide the window to its left until the window's left reaches the last index (size-1)th of the array

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, sum = 0;
        for(int i=0; i<k; i++) {
            sum += cardPoints[i];
        }
        int left = 0, right = k-1;
        ans = sum;
        while(k--) {
            sum -= cardPoints[right];
            right = right == 0 ? right-1+cardPoints.size() : right-1;
            left = left == 0 ? left-1+cardPoints.size() : left-1;
            sum += cardPoints[left];
            ans = max(ans, sum);
        }

        return ans;
    }
};


// Recursive Solution 

class Solution {
public:
    int helper(vector<int>& cardPoints, int lo, int hi, int k) {
        if(k==0) return 0;
        return max(cardPoints[lo] + helper(cardPoints, lo+1, hi, k-1), cardPoints[hi] + helper(cardPoints, lo, hi-1, k-1));
    }
    int maxScore(vector<int>& cardPoints, int k) {
       if(cardPoints.size() <= k) {
            int ans = 0;
            for(auto i : cardPoints) ans += i;
            return ans;
       }
       return helper(cardPoints, 0, cardPoints.size()-1, k);
    }
};