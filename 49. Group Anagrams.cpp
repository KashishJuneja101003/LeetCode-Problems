// Approach 1: Brute Force TC: O(n^2 * k) SC: O(1)
/*
class Solution {
public:
    bool isAnagram(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        vector<int> freq(26, 0);

        for(char c:s1) freq[c-'a']++;

        for(char c:s2){
            int idx = c-'a';
            freq[idx]--;
            if(freq[idx] < 0) return false;
        }

        for(int i:freq){
            if(i != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        for(string s:strs){
            bool found = false;
            for(auto& s1:result){
                if(isAnagram(s, s1.front())) {
                    s1.push_back(s);
                    found = true;
                    break;
                }
            }

            if(!found) result.push_back({s});
        }

        return result;
    }
};
*/

// Approach 2: Sorting + Hashmap TC: O(n * k * log k) SC: O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        // Make sorted string as key and push original string in vector corresponding to key
        for(string& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        // In result, push_back the vector corresponding to the keys
        for(auto& pair : mp){
            result.push_back(pair.second);
        }

        return result;
    }
};
