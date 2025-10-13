// TC: O(n * k) SC: O(1)
class Solution {
public:
    bool isAnagram(string& a, string& b) {
        vector<int> freq(26, 0);

        for (char& c : a) {
            freq[c - 'a']++;
        }
        for (char& c : b) {
            freq[c - 'a']--;
        }

        for (int& f : freq) {
            if (f != 0) {
                return false;
            }
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        int curr = 0;
        ans.push_back(words[0]);

        for (int i = 1; i < n; i++) {
            if (!isAnagram(words[curr], words[i])) {
                ans.push_back(words[i]);
                curr = i;
            }
        }

        return ans;
    }
};

// TC: O(n * k log k) SC: O(k)
