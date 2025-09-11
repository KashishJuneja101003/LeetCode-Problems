class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    string sortVowels(string s) {
        int n = s.length();
        string t = "";
        priority_queue<char, vector<char>, greater<char>> pq;

        for (char& c : s) {
            if (isVowel(c)) {
                pq.push(c);
            }
        }

        for (char& c : s) {
            if (isVowel(c)) {
                t += pq.top();
                pq.pop();
            } else {
                t += c;
            }
        }

        return t;
    }
};
