class Solution {
public:
    string resultingString(string s) {
        string stack;

        for (char c : s) {
            if (!stack.empty()) {
                int diff = abs(stack.back() - c);
                if (diff == 1 || diff == 25) {
                    // Remove the top of the stack (and skip pushing c)
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(c);
        }

        return stack;
    }
};
