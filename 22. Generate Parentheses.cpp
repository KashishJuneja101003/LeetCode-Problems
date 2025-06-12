// Approach 1: Recursion TC: O(2n * 2^2n) SC: O(2*n)
/*
class Solution {
public:
    bool isValid(string curr){
        stack<char> stk;
        for(char c : curr){
            if(c == '(') stk.push(c);
            else{
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

    void generate(int size, vector<string>& parenthesis, string curr, int idx){
        if(idx >= size){
            if(isValid(curr)){
                parenthesis.push_back(curr);
            }
            return;
        }

        generate(size, parenthesis, curr + '(', idx+1);
        generate(size, parenthesis, curr + ')', idx+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        generate(n*2, parenthesis, "", 0);
        return parenthesis;
    }
};
*/

// Approach 2: Recursion TC: O(2n * 2^2n) SC: O(2*n)
/*
class Solution {
public:
    bool isValid(string curr){
        int count = 0;
        for(char c : curr){
            if(c == '(') count++;
            else{
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }

    void generate(int size, vector<string>& parenthesis, string curr, int idx){
        if(idx >= size){
            if(isValid(curr)){
                parenthesis.push_back(curr);
            }
            return;
        }

        generate(size, parenthesis, curr + '(', idx+1);
        generate(size, parenthesis, curr + ')', idx+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        generate(n*2, parenthesis, "", 0);
        return parenthesis;
    }
};
*/

// Approach 3: Recursion + Early Check TC: O(2^2n) SC: O(2^n)
class Solution {
public:
    void generate(int n, vector<string>& parenthesis, string curr, int idx, int open, int close){
        if(idx >= n*2){
            parenthesis.push_back(curr);
            return;
        }

        if(open < n) {
            generate(n, parenthesis, curr + '(', idx+1, open+1, close);
        }
        if(close < open) {
            generate(n, parenthesis, curr + ')', idx+1, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        generate(n, parenthesis, "", 0, 0, 0);
        return parenthesis;
    }
};
