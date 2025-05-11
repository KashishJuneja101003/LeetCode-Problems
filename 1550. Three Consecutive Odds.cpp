class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        if(n < 3) return false;

        int numOdd = 0;
        for(int i=0; i<n; i++){
            if(arr[i]%2 != 0) numOdd++;
            else numOdd = 0;

            if(numOdd == 3) return true;
        }

        return false;
    }
};
