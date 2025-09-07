class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1) return {0};

        vector<int> ans;
        if (n % 2 == 1) ans.push_back(0);
        int num = 1;

        while (ans.size() < n) {
            ans.push_back(-num);
            ans.push_back(num);
            num++;
        }

        return ans;
    }
};
