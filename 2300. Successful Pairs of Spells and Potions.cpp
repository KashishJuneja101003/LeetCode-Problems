class Solution {
public:
    int BS(int spell, vector<int>& potions, long long success) {
        int left = 0, right = potions.size() - 1;
        int m = potions.size();
        int ans = m; // default all fail

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long prod = 1LL * spell * potions[mid];

            if (prod >= success) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return m - ans; 
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for (int spell : spells) {
            result.push_back(BS(spell, potions, success));
        }
        return result;
    }
};
