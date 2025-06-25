// Approach 1: Sorting TC: O(n^2 logn) SC: O(n) 
/*
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() >= 2){
            sort(stones.begin(), stones.end());

            // Take 2 largest stones
            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();

            if(x != y) stones.push_back(y-x);
        }

        if(stones.size() == 0) return 0;
        else return stones[0];
    }
};
*/

// Approach 2: Max-Heap TC: O(n logn) SC: O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        priority_queue<int> weights;

        // Push the weights into the max heap(weights)
        for(int i:stones) weights.push(i);

        // Since we have to retrieve only 2 top most weighted stones
        // while(weights.size() >= 2) will be the loop conditions
        while(weights.size() >= 2){
            // Get weights
            int y = weights.top(); weights.pop();
            int x = weights.top(); weights.pop();

            // If weights are not equal, push the difference into heap
            if(x != y) weights.push(y-x);
        }

        if(weights.size() == 0) return 0;
        else return weights.top();
    }
};
