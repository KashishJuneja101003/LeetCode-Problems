class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);

        for(char c:s){
            freq[c-'a']++;
        }

        for(char c:t){
            int idx = c-'a';
            if(freq[idx] == 0) return false;
            freq[idx]--;
        }

        for(int i:freq){
            if(i > 0) return false;
        }

        return true;
    }
};
