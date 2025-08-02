// Recursion TC: O(2^n)
class Solution {
public:
    int getCost(vector<int>& cost, int currStep){
        if(currStep >= cost.size()) {
            return 0;
        }

        // One step
        int one = cost[currStep] + getCost(cost, currStep+1);

        // Two steps
        int two = cost[currStep] + getCost(cost, currStep+2);

        return min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int minCost1 = getCost(cost, 0);
        int minCost2 = getCost(cost, 1);


        return min(minCost1, minCost2);
    }
};

// Memoized TC: O(n) SC: O(n)
class Solution {
public:
    int getCost(vector<int>& cost, int currStep, vector<int>& dp){
        if(currStep >= cost.size()) {
            return 0;
        }

        if(dp[currStep] != INT_MAX) return dp[currStep];

        // One step
        int one = cost[currStep] + getCost(cost, currStep+1, dp);

        // Two steps
        int two = cost[currStep] + getCost(cost, currStep+2, dp);

        return dp[currStep] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, INT_MAX);

        int minCost1 = getCost(cost, 0, dp);
        int minCost2 = getCost(cost, 1, dp);


        return min(minCost1, minCost2);
    }
};
