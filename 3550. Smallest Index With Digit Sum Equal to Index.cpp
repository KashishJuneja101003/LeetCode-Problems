class Solution {
public:
    int calculateSum(int n){
        int sum = 0;
        while(n > 0){
            int rem = n%10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int sum = calculateSum(nums[i]);
            if (sum == i){
                return i;
            }
        }

        return -1;
    }
};
