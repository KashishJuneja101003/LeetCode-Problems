class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0], maxProfit = 0;

        for(int i=1; i<prices.size(); i++){
            minSoFar = min(minSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minSoFar);
        }

        return (maxProfit > 0 ? maxProfit : 0);
    }
};
