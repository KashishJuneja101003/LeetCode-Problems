// Approach 1 (Using Hashmap): TC: O(n) SC: O(n)
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length() == 0) return t[0];

        vector<int> chars(26, 0);
        for(char c:s){
            chars[c-'a']++;
        }
        
        char ch;
        for(char c:t){
            int idx = c-'a';
            if(chars[idx] == 0) {
                ch = c; 
                break;
            }
            else chars[idx]--;
        }

        return ch;
    }
};
*/

// Approach 2 (Using sum): TC: O(n) SC: O(1)
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length() == 0) return t[0];

        int sum = 97;
        for(char c:t){
            sum += c-'a';
        }
        
        for(char c:s){
            sum -= c-'a';
        }
        
        return (char)sum;
    }
};
*/


// Approach 3 (Using XOR): TC: O(n) SC: O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length() == 0) return t[0];

        int xor1 = 0;
        for(char c:t){
            xor1 ^= c;
        }
        
        for(char c:s){
            xor1 ^= c;
        }

        return xor1;
    }
};


// Approach 4 (Using Sorting): TC: O(nlogn) SC: O(1)
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length() == 0) return t[0];

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[t.size()-1];
    }
};
*/
