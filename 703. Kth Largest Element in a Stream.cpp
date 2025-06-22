// Approach 1: Min-Heap TC: O(n logk) SC: O(k)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int K, vector<int>& nums) {
        k = K;
        for(int i:nums){
            minHeap.push(i);
            if(minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
