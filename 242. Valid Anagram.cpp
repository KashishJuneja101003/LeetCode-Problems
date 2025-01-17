class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1[26] = {0}, t1[26] = {0};
        for(char c:s){
            s1[c-'a'] += 1;
        }
        for(char c:t){
            t1[c-'a'] += 1;
        }

        for(int i=0; i<26; i++){
            if(s1[i] != t1[i]){
                return false;
            }
        }

        return true;
    }
};
