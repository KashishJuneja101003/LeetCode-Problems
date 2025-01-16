class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int result = 0;
        if(n1%2 != 0){
            for(int i:nums2){
                result ^= i;
            }
        } 
        if(n2%2 != 0){
            for(int i:nums1){
                result ^= i;
            }
        }

        return result;
    }
};
