class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i:nums) {pq.push(i);}

        int result = 0;
        
        while(pq.size() >= 2 && pq.top() < k){
            result++;
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            long long int formula = (min(x,y)*2LL) + 1LL*(max(x,y));
            pq.push(formula);
        }
        return result;
    }
};
