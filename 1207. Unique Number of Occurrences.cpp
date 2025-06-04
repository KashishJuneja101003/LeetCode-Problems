class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> el_freq;
        for(int& i:arr){
            el_freq[i]++;
        }

        unordered_set<int> uniqueFreq;
        for(auto& it : el_freq){
            int freq = it.second;
            if(uniqueFreq.find(freq) != uniqueFreq.end()){
                return false;
            }

            uniqueFreq.insert(freq);
        }

        return true;
    }
};
