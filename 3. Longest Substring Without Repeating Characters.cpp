// Brute Force TC: O(n^2) SC: O(k)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if(n <= 1) return n;

        int maxLen = 0;
        
        for(int i=0; i<n; i++){
            unordered_set<char> st;
            int len = 0;
            for(int j=i; j<n; j++){
                if(st.find(s[j]) == st.end()){
                    st.insert(s[j]);
                    len++;
                } else {
                    break;
                }
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

// Two Ponters TC: O(n) SC: O(k)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if (n <= 1)
            return n;

        int maxLen = 0;
        unordered_set<char> st;

        int left = 0;
        int right = 0;
        while(right < n){
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};

// Optimized:
// 1. If right is present in map, jump to its index+1 so that you don't have to remove elements repeatedly.
// 2. left should be updated by max(left, index+1) to ensure the previous occurrence of the repeated character is removed from the window at once.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if (n <= 1)
            return n;

        int maxLen = 0;
        unordered_map<char, int> char_idx;

        int left = 0;
        int right = 0;
        while (right < n) {
            if (char_idx.find(s[right]) != char_idx.end()) {
                int index = char_idx[s[right]];
                left = max(left, index + 1);
            }
            char_idx[s[right]] = right;
            right++;
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
