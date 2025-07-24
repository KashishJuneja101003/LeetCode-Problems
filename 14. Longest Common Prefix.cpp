// Brute Force TC: O(n*m) m - avg length (Good for small m)
class Solution {
public:
    string commonStr(string s1, string s2){
        string str = "";

        for(int i=0; i<min(s1.size(), s2.size()); i++){
            if(s1[i] != s2[i]) return str;
            str += s1[i];
        }

        return str;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];

        for(int i=1; i<strs.size(); i++){
            result = commonStr(result, strs[i]);

            if(result == "") return result;
        }

        return result;
    }
};

// Sorting TC: O(n log n) (good for large m)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_size = strs.size();
        sort(strs.begin(), strs.end());

        string first = strs[0], last = strs[strs_size-1], result = "";
        int first_size = first.size();
        for(int i=0; i<first_size; i++){
            if (first[i] == last[i]) result += first[i];
            else break;
        }
        return result;
    }
}; 
