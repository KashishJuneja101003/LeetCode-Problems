// TC: O(n) SC: O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(char& c:sentence){
            st.insert(c);
        }

        return st.size() == 26;
    }
};

// Optimized - early exit
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        for(char& c:sentence){
            st.insert(c);

            if(st.size() == 26) return true;
        }

        return false;
    }
};
