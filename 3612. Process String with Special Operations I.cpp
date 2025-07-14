class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(char& c:s){
            if(isalpha(c)) result += c;
            else if (c == '*') result = result.substr(0, result.size()-1);
            else if (c == '#') result += result;
            else if (c == '%') reverse(result.begin(), result.end());
        }

        return result;
    }
};
