// Brute Force TC: O(n^2) SC: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int len = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '(') {
                int curr = 0;
                stack<char> stk;
                for(int j=i; j<n; j++){
                    if(s[j] == '(') stk.push('(');
                    else{
                        if(stk.empty()) break;
                        curr += 2;
                        stk.pop();
                    }
                }

                len = max(len, curr);
            }
        }

        return len;
    }
};

// Two-Pointers TC: O(n) SC: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int len = 0;
        int open = 0;
        int close = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                len = max(len, open*2);
            } else if(close > open){
                open = 0; close = 0;
            }
        }

        open = 0; close = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                len = max(len, open*2);
            } else if(open > close){
                open = 0; close = 0;
            }
        }

        return len;
    }
};
