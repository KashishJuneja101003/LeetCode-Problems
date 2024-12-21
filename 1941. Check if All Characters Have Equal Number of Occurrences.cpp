class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);

        for(char c:s){
            freq[c-'a']++;
        }

        for(int i:freq)cout<<i<<" ";

        int check = freq[s[0]-'a'];
        for(int i=0; i<26; i++){
            if(freq[i] != 0 && freq[i] != check) return false;
        }

        return true;
    }
};
