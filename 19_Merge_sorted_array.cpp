// Revision Count : 0
// Time Complexity :  
// Explained here : https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
// TC : O((m+n)log(m+n))  |  SC : O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2 + (m+2)%2;
        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[i-m];
        }

        while(gap > 0) {
            int left = 0, right = left+gap;
            
            while(right < m+n) {
                 if(nums1[left] > nums1[right]) swap(nums1[left], nums1[right]);
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
    }
};