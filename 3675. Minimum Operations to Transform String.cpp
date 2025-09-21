class Solution {
public:
    int minOperations(string s) {
        int op = 0;
        for(char& c:s){
            int steps = (26-(c - 'a'))%26;
            op = max(op, steps);
        }

        return op;
    }
};
