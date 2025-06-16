class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftProd = 1;
        int rightProd = 1;
        int maxProd = nums[0];
        int n = nums.size();

        for(int i=0; i<n; i++){
            leftProd = (leftProd == 0) ? 1 : leftProd;
            rightProd = (rightProd == 0) ? 1 : rightProd;
            
            leftProd *= nums[i];
            rightProd *= nums[n-i-1];

            maxProd = max(maxProd, max(leftProd, rightProd));
        }
        return maxProd;
    }
};
