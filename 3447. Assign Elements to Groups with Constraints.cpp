class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int ng = groups.size();
        int maxValue = 100000; // Max value of elements[i] and groups[i]

        // Step 1: Store the smallest index of each element
        vector<int> index_map(maxValue + 1, -1);
        for (int i = 0; i < elements.size(); i++) {
            if (index_map[elements[i]] == -1) {
                index_map[elements[i]] = i; // Store the first occurrence
            }
        }

        vector<int> assigned(ng, -1);

        // Step 2: Process each group efficiently
        for (int i = 0; i < ng; i++) {
            int min_index = INT_MAX;
            for (int d = 1; d * d <= groups[i]; d++) {  // Iterate over divisors
                if (groups[i] % d == 0) {
                    if (index_map[d] != -1) min_index = min(min_index, index_map[d]);
                    if (groups[i] / d != d && index_map[groups[i] / d] != -1) {
                        min_index = min(min_index, index_map[groups[i] / d]);
                    }
                }
            }
            if (min_index != INT_MAX) {
                assigned[i] = min_index;
            }
        }

        return assigned;
    }
};
