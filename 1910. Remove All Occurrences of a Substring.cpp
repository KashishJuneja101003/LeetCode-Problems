// Approach 1: O(N^2 / M)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};

// Approach 2: O(NM)
class Solution {
public:
    bool helper(stack<char>& stk, string part, int p_len){
        stack<char> stk2 = stk;
        int i=1;
        for(int i=p_len-1; i>=0; i--){
            if(stk2.top() != part[i]){
                return false;
            }

            stk2.pop();
        }

        return true;
    }
    string removeOccurrences(string s, string part) {
        int s_len = s.size(), p_len = part.size();

        stack<char> stk;
        string newS = s + ' ';
        for(char c:newS){
            if(stk.size() >= p_len && helper(stk, part, p_len)){
                for(int i=0; i<p_len; i++){
                    stk.pop();
                }
            } 
            stk.push(c);
        }

        newS = "";
        while(!stk.empty()){
            newS = stk.top() + newS;
            stk.pop();
        }
        return newS.substr(0, newS.size()-1);
    }
};

// Approach 3: O(N)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p_len = part.size();
        string result="";

        for(char c:s){
            result.push_back(c);

            if((result.size() >= p_len) && (result.substr(result.size() - p_len) == part)){
                result.erase(result.size() - p_len);
            }
        }

        return result;
    }
};
