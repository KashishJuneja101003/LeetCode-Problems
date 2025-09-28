class Solution {
public:    
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;

        int power = 1;

        while(n > 0){
            int digit = n%10;

            if(digit != 0) ans.push_back(digit*power);
            n/=10;

            if(power <= INT_MAX/10) power *= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
