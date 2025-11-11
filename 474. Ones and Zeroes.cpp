// Brute Force
class Solution {
public:
    pair<int, int> count(string s){
        int zeroes = 0;
        int ones = 0;

        for(char& c:s){
            if(c == '0') zeroes++;
            else ones++;
        }

        return {zeroes, ones};
    }
    
    void solve(vector<pair<int, int>>& vec, int m, int n, int i, int len, int& maxLen){
        if(i == vec.size()){ 
            maxLen = max(maxLen, len);
            return;
        }
        if(m == 0 && n == 0) {
            maxLen = max(maxLen, len);
            return;
        }

        // Exclude
        solve(vec, m, n, i+1, len, maxLen);

        // Include
        if(vec[i].first <= m && vec[i].second <= n){
            solve(vec, m-vec[i].first, n-vec[i].second, i+1, len+1, maxLen);
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int maxLen = 0;

        vector<pair<int, int>> vec;

        for(string& s:strs){
            vec.push_back(count(s));
        }

        solve(vec, m, n, 0, 0, maxLen);

        return maxLen;
    }
};
