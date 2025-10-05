class Solution {
public:
    string removeSubstring(string s, int k) {
        string stack; // simulate stack behavior using string
        
        for (char c : s) {
            stack.push_back(c);
            
            // if we have at least 2k chars, check the last 2k segment
            if ((int)stack.size() >= 2 * k) {
                bool match = true;
                // check first k are '('
                for (int i = stack.size() - 2 * k; i < stack.size() - k; i++) {
                    if (stack[i] != '(') { match = false; break; }
                }
                // check next k are ')'
                for (int i = stack.size() - k; i < stack.size(); i++) {
                    if (stack[i] != ')') { match = false; break; }
                }
                // remove if k-balanced
                if (match) {
                    stack.resize(stack.size() - 2 * k);
                }
            }
        }
        return stack;
    }
};
