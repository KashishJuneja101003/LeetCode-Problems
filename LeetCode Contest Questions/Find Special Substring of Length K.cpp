/*
You are given a string s and an integer k.

Determine if there exists a substring of length exactly k in s that satisfies the following conditions:

The substring consists of only one distinct character (e.g., "aaa" or "bbb").
If there is a character immediately before the substring, it must be different from the character in the substring.
If there is a character immediately after the substring, it must also be different from the character in the substring.
Return true if such a substring exists. Otherwise, return false.

A substring is a contiguous non-empty sequence of characters within a string.
 

Example 1:

Input: s = "aaabaaa", k = 3

Output: true

Explanation:

The substring s[4..6] == "aaa" satisfies the conditions.

It has a length of 3.
All characters are the same.
The character before "aaa" is 'b', which is different from 'a'.
There is no character after "aaa".
Example 2:

Input: s = "abc", k = 2

Output: false

Explanation:

There is no substring of length 2 that consists of one distinct character and satisfies the conditions.

 

Constraints:

1 <= k <= s.length <= 100
s consists of lowercase English letters only.©leetcode
*/
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int left = 0, right = 0, n = s.size();

        while(right < n){
            // Characters must be same
            if(s[left] != s[right]){
                left++;
            } else if(right-left+1 < k){  // Achieving size k
                right++;
            } else{
                bool status = true;
                if(left > 0 && s[left-1] == s[left]) status = false;
                if(right<n-1 && s[right+1] == s[right]) status = false;

                if(status) return true;
                else left++; right++;
            }
        }

        return false;
    }
};©leetcode
