// 2 pass solution
// TC: O(n) SC: O(1)
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

// 1 pass solution
// TC: O(n) SC: O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int maxFreq = 0;
        int total = 0;

        for (int& i : nums) {
            freq[i]++;
            
            if(freq[i] > maxFreq){
                maxFreq = freq[i];
                total = maxFreq;
            } else if(freq[i] == maxFreq){
                total += maxFreq;
            }
        }

        return total;
    }
};
