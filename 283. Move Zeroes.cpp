class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currZero = 0;
        int currNonZero = 0;
        int size = nums.size();

        while(currZero < size && currNonZero < size){
            if(nums[currZero] != 0){
                currZero++; continue;
            }

            if(nums[currNonZero] == 0){
                currNonZero++; continue;
            }

            if(currNonZero < currZero){
                currNonZero++; continue;
            }

            swap(nums[currZero], nums[currNonZero]);
        }
    }
};
