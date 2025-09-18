class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char& c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto& it : freq)
            pq.push({it.second, it.first});

        string result = "";

        while (!pq.empty()) {
            int times = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            while (times--)
                result += c;
        }

        return result;
    }
};
