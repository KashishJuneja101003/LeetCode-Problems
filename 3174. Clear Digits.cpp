class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;

        for(char c:s){
            if(isdigit(c) && !stk.empty()){
                stk.pop();
            } 
            else{
                stk.push(c);
            }
        }

        string x="";
        while(!stk.empty()){
            x = stk.top() + x;
            stk.pop();
        }

        return x;
    }
};
