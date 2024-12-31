class Solution {
public:
    bool isPalindrome(string s1){
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return (s1 == s2) ? true : false;
    }

    void getAllParts(string s, vector<string>& parts, vector<vector<string>>&ans){
        if(s.size() == 0){
            ans.push_back({parts});
            return;
        }

        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);

            if(isPalindrome(part)){
                parts.push_back(part);
                getAllParts(s.substr(i+1), parts, ans);

                parts.pop_back();   // Backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>parts;
        
        getAllParts(s, parts, ans);
        return ans;
    }
};
