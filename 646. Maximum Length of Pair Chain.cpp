// Approach 1: Recursion TC: O(2^n) SC: O(1)
/*
class Solution {
public:
    void solve(vector<vector<int>>& pairs, int index, int currEnd, int currChain, int& maxChain) {
        maxChain = max(maxChain, currChain);

        for (int i = index; i < pairs.size(); i++) {
            if (currEnd < pairs[i][0]) {
                solve(pairs, i + 1, pairs[i][1], currChain + 1, maxChain);
            }
        }
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());  
        int maxChain = 0;
        solve(pairs, 0, -1001, 0, maxChain);
        return maxChain;
    }
};
*/


// Approach 2: Greedy TC: O(n logn) SC: O(1)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // sort by second element
        });

        int chainLength = 0;
        int currentEnd = INT_MIN;

        for (auto& pair : pairs) {
            if (pair[0] > currentEnd) {
                chainLength++;
                currentEnd = pair[1];
            }
        }

        return chainLength;
    }
};
