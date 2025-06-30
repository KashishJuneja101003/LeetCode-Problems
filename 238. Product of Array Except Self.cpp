// Approach 1: Brute Force TC: O(n^2) SC: O(n)
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for(int i=0; i<n; i++){
            int prod = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                prod *= nums[j];
                if(prod == 0) break;
            }
            result[i] = prod;
        }
        return result;
    }
};
*/

// Approach 2: Array Manipulation TC: O(n) SC: O(n)
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixProd(n, 1);
        vector<int> prefixProd(n, 1);

        for(int i=1; i<n; i++) prefixProd[i] = prefixProd[i-1]*nums[i-1];
        for(int i=n-2; i>=0; i--) suffixProd[i] = suffixProd[i+1]*nums[i+1];

        vector<int> result(n);
        for(int i=0; i<n; i++) result[i] = prefixProd[i]*suffixProd[i];

        return result;
    }
};
*/

// Approach 3: Array Manipulation Optimized TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n,1);
        for(int i=1; i<n; i++) result[i] = result[i-1]*nums[i-1];

        int suffixProd = 1;
        for(int i=n-1; i>=0; i--) {
            result[i] = result[i]*suffixProd;
            suffixProd *= nums[i];
        }

        return result;
    }
};
