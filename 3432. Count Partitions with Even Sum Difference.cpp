class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int r = 0;
        int l = 0;
        int c = 0;

        for(int& x:nums){
            r += x;
        }

        for(int& x:nums){
            l += x;
            r -= x;

            if((l-r) % 2 == 0){
                c++;
            }
        }

        return (c==0)? 0 : c-1;
    }
};
