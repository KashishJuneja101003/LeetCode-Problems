// Approach 1: TC: O(n * (k + log n)) SC: O(n*k)
class Solution {
public:
    bool isValid(string code){
        if(code == "") return false;
        
        for(char c:code){
            if(c != '_' && !isalnum(c)) return false;
        }

        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<multiset<string>> mp(4); // 0: electronics, 1: grocery, 2: pharmacy, 3: restaurant

        for(int i = 0; i < n; i++) {
            if(isActive[i] && isValid(code[i])) {
                int order = -1;
                string bl = businessLine[i];
                
                if(bl == "electronics") order = 0;
                else if(bl == "grocery") order = 1;
                else if(bl == "pharmacy") order = 2;
                else if(bl == "restaurant") order = 3;
                
                if(order != -1)
                    mp[order].insert(code[i]);
            }
        }

        vector<string> result;
        for(auto& p : mp) {
            for(const string& s : p) {
                result.push_back(s);
            }
        }

        return result;
    }
};
