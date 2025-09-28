class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        
        for(char& c:magazine){
            int idx = c-'a';

            freq[idx]++;
        }

        for(char& c:ransomNote){
            int idx = c-'a';

            if(freq[idx] == 0) return false;
            freq[idx]--;
        }

        return true;
    }
};
