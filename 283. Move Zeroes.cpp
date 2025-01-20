class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i=0, j=0;

        while(i < n && j<n){
            if(nums[i] != 0){
                i++; continue;
            }

            if(nums[j] == 0){
                j++; continue;
            }

            if(j<i){
                j++; continue;
            }

            swap(nums[i], nums[j]);
        }
    }
};
