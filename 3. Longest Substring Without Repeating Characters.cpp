class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstring = 0;
        int left = 0, right = 0;
        unordered_set<char> characterSet;

        while (right < s.size()) {
            while (characterSet.find(s[right]) != characterSet.end()) {
                characterSet.erase(s[left]);
                left++;
            }
            characterSet.insert(s[right]);
            longestSubstring = max(longestSubstring, right - left + 1);
            right++;
        }

        return longestSubstring;
    }
};
