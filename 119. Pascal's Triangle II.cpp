class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};

        vector<int> result = {1, 1};

        for (int i = 2; i <= rowIndex; i++) {
            vector<int> temp(i + 1);
            temp[0] = temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = result[j - 1] + result[j];
            }

            result = temp;
        }

        return result;
    }
};
