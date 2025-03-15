class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candiesAssigned(n, 1);

        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candiesAssigned[i] = candiesAssigned[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candiesAssigned[i] = max(candiesAssigned[i], candiesAssigned[i+1]+1);
            }
        }

        // Calculate the sum of candies assigned
        int count = 0;
        for(int i:candiesAssigned){
            cout<<i<<" ";
            count += i;
        }
        return count;
    }
};
