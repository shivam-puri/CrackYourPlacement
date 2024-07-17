// Revision Count : 0
// Approach :  Sorting
// Time Complexity : O(N logN)  |  Space Complexity : O(1)

// Explanation : 1. sort the array.  2. initialize the ans variable with INT_MAX  
// 3. traverse the sorted array and calculate the diff bw ith and (m-1 + i)th element. update if it appears to be smaller than current 

class Solution {
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(), a.end());
        long long ans = INT_MAX;
        
        for(int i = 0; i <= a.size()-m; i++) {
            ans = min(ans, a[m-1 + i] - a[i]);
        }
        
        return ans;
    }   
};