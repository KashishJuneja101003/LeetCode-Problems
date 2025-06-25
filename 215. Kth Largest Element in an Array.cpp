// Approach 1: Sorting TC: O(n log n) SC: O(1)
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
*/

// Approach 2: Min-Heap TC: O(n log k) SC: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i:nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
