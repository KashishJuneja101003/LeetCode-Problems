// Approach 1: Hashmap and Max-Heap TC: O(n logn) SC: O(n) 
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> el_freq;
        for(int i:nums){
            el_freq[i]++;
        }

        priority_queue<pair<int, int>> pq;
        
        for(auto& it: el_freq){
            int el = it.first;
            int freq = it.second;

            pq.push({freq, el});
        }

        vector<int> freqElements;
        while(freqElements.size() != k){
            freqElements.push_back(pq.top().second);
            pq.pop();
        }

        return freqElements;
    }
};
*/

// Approach 2: Hashmap and Min-Heap TC: O(n logn) SC: O(n) 
/*
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> el_freq;
        for(int i:nums){
            el_freq[i]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        
        for(auto& it: el_freq){
            int el = it.first;
            int freq = it.second;

            pq.push({freq, el});

            if(pq.size() > k) pq.pop();
        }

        vector<int> freqElements;
        while(!pq.empty() ){
            freqElements.push_back(pq.top().second);
            pq.pop();
        }

        return freqElements;
    }
};
*/

// Approach 3: Bucket Sort TC: O(n) SC: O(n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> el_freq;
        for(int i:nums){
            el_freq[i]++;
        }

        int n = nums.size();
        vector<vector<int>> frequencies(n+1);
        for(auto& it:el_freq){
            int freq = it.second;
            int el = it.first;

            frequencies[freq].push_back(el);
        }

        vector<int> freqElements;
        int idx = n;
        while(freqElements.size() != k){
            if(frequencies[idx].size() == 0){
                idx--; continue;
            }
            freqElements.push_back(frequencies[idx].back());
            frequencies[idx].pop_back();
        }

        return freqElements;
    }
};
