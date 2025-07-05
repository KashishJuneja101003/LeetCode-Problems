// Approach 1: Using vector TC: O(n) SC: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(char& c:s) freq[c-'a']++;

        for(int i=0; i<s.size(); i++){
            int c = s[i]-'a';
            if(freq[c] == 1) return i;
        }

        return -1;
    }
};

// Approach 2: Using queue TC: O(n) SC: O(n) (Works for streaming too)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<int> q;

        for(int i=0; i<s.size(); i++) {
            freq[s[i]-'a']++;
            q.push(i);
        }

        while(!q.empty() && freq[s[q.front()]-'a'] > 1){
            q.pop();
        }

        return (q.empty()) ? -1 : q.front();
    }
};
