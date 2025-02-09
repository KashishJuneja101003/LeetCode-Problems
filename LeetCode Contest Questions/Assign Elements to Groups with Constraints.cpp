// You are given an integer array groups, where groups[i] represents the size of the ith group. You are also given an integer array elements.
// Your task is to assign one element to each group based on the following rules:
// - An element j can be assigned to a group i if groups[i] is divisible by elements[j].
// - If there are multiple elements that can be assigned, assign the element with the smallest index j.
// - If no element satisfies the condition for a group, assign -1 to that group.
// Return an integer array assigned, where assigned[i] is the index of the element chosen for group i, or -1 if no suitable element exists.
// Note: An element may be assigned to more than one group.

// Example 1:
// Input: groups = [8,4,3,2,4], elements = [4,2]
// Output: [0,0,-1,1,0]
// Explanation:
// elements[0] = 4 is assigned to groups 0, 1, and 4.
// elements[1] = 2 is assigned to group 3.
// Group 2 cannot be assigned any element.©leetcode

// Example 2:
// Input: groups = [2,3,5,7], elements = [5,3,3]
// Output: [-1,1,0,-1]
// Explanation:
// elements[1] = 3 is assigned to group 1.
// elements[0] = 5 is assigned to group 2.
// Groups 0 and 3 cannot be assigned any element.

// Example 3:
// Input: groups = [10,21,30,41], elements = [2,1]
// Output: [0,1,0,1]
// Explanation:
// elements[0] = 2 is assigned to the groups with even values, and elements[1] = 1 is assigned to the groups with odd values.

// Constraints:
// 1 <= groups.length <= 105
// 1 <= elements.length <= 105
// 1 <= groups[i] <= 105
// 1 <= elements[i] <= 105

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
