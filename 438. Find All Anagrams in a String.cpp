class Solution {
public:
    bool isAnagram(vector<int>& char_freq){
        for(int i:char_freq){
            if(i != 0) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> char_freq(26, 0);
        for(char c:p) char_freq[c-'a']++;
        
        int i=0;
        int j=0;
        vector<int> indicesAnagrams;
        
        while(j < s.size()){
            char_freq[s[j] - 'a']--;
            if(j-i+1 == p.size()){
                if(isAnagram(char_freq)) indicesAnagrams.push_back(i);
                char_freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        
        return indicesAnagrams;
    }
};
