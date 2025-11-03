// TC: O(n) SC: O(n)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        priority_queue<int> pq;

        for (int i = 0; i < n;) {
            char lastColor = colors[i];
            while (i < n && colors[i] == lastColor) {
                pq.push(neededTime[i]);
                i++;
            }

            pq.pop();

            while (!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
