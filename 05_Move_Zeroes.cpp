// Revision Count : 0
// Similar Questions : Sort Colors
// Bruteforce Approach
// Time Complexity : O(2*N) ~ O(N) | S.C. - O(N)

// Intiution : Count all zeroes and push all non zeroes in a new vector. In the same sequence, insert the elements of nonZeroes vector into input array
// and set the last remaining elements to 0. 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //   bruteforce approach
        int zeroCount = 0;
        vector<int> nonZeroes;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zeroCount++;
            else nonZeroes.push_back(nums[i]);
        }

        for(int i = 0; i < nonZeroes.size(); i++) {
            nums[i] = nonZeroes[i];
        }
        for(int i = nonZeroes.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// Optimal Approach 
//  Time Complexity : O(2*N) ~ O(N) | S.C. - O(N)

// Intution : 
// 1. initialize 2 pointers left and mid pointing to 0 index
// 2. traverse the array through mid pointer until it reaches the end
// 3. if element at mid pointer != 0 than swap it with left pointer (i.e. the leftmost position for that element)
// 4. else just move the mid pointer forward

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, mid = 0;

        while(mid <= nums.size()-1) {
            if(nums[mid] != 0) {
                swap(nums[mid], nums[left]);
                left++;
            }
            mid++;
        }
       
    }
};