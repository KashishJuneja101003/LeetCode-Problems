class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();

        if(n == 1){
            return true;
        }

        // flag = 1, if nums[0] is odd. flag = 0, if nums[0] is even.
        int flag = (nums[0]&1);

        for(int i=0; i<n; i++){
            if((nums[i]&1) != flag){
                return false;
            }

            flag = (flag == 0) ? 1 : 0; // Toggle flag: if flag = 0, convert it to 1. If 1, convert it to 0.
        }

        return true;
    }
};
