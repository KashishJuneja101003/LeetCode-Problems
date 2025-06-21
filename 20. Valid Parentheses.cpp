// Approach 1: Using Stacks TC: O(n) SC: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c:s){
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c); continue;
            } else {
                if(stk.empty()) return false;

                char top = stk.top();
                
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;                
                if (c == ']' && top != '[') return false;
                
                stk.pop();
            }

        }

        return stk.empty();
    }
};
