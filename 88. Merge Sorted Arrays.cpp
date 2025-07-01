// Approach 1: TC: O(m+n) SC: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1;
        int i = m-1;
        int j = n-1;

        while(i >= 0 && j >= 0){
            if(nums2[j] >= nums1[i]){
                nums1[idx] = nums2[j];
                j--;
            } else{
                swap(nums1[i], nums1[idx]);
                i--;
            }
            idx--; 
        }

        while(j >= 0){
            nums1[idx] = nums2[j];
            idx--; j--;
        }
    }
};
