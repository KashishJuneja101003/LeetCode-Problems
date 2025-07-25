// TC: O(2n) = O(n) SC: O(1)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> freq(101, 0);
        int sum = 0;
        bool positive = false;

        for(int& i:nums){
            if(i >= 0 && freq[i] == 0){
                sum += i;
                freq[i] = 1;
                positive = true;
            }
        }

        if(!positive){
            int maxEl = INT_MIN;
            for(int& i:nums){
                maxEl = max(maxEl, i);
            }

            return maxEl;
        }

        return sum;
    }
};


// TC: O(n) SC: O(1)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> freq(101, 0);
        int sum = 0;
        int maxEl = INT_MIN;

        for (int& i : nums) {
            if (i >= 0 && freq[i] == 0) {
                sum += i;
                freq[i] = 1;
            }
            maxEl = max(maxEl, i);
        }

        return (maxEl < 0) ? maxEl : sum;
    }
};
