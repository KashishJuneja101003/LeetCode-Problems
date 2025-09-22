class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int maxFreq = 0;

        for (int& i : nums) {
            freq[i]++;
            maxFreq = max(maxFreq, freq[i]);
        }

        int count = 0;

        for (int& i : freq) {
            if (i == maxFreq) count++;
        }

        return count * maxFreq;
    }
};
