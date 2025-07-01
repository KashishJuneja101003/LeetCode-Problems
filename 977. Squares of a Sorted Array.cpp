// My Creative Solution TC: O(n) SC: O(n)
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int minIdx = 0;
        int minEl = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int el = abs(nums[i]);
            if (el < minEl) {
                minIdx = i;
                minEl = el;
            }
        }

        int left = minIdx - 1;
        int right = minIdx + 1;
        vector<int> result;

        result.push_back(minEl * minEl);

        while (left >= 0 && right < n) {
            int leftEl = abs(nums[left]);
            int rightEl = abs(nums[right]);

            if (leftEl <= rightEl) {
                result.push_back(leftEl * leftEl);
                left--;
            } else {
                result.push_back(rightEl * rightEl);
                right++;
            }
        }

        while (left >= 0) {
            int leftEl = abs(nums[left]);
            result.push_back(leftEl * leftEl);
            left--;
        }

        while (right < n) {
            int rightEl = abs(nums[right]);
            result.push_back(rightEl * rightEl);
            right++;
        }

        return result;
    }
};
*/

// Approach 2: Two Pointers TC: O(n) SC: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;
        int idx = n-1;
        vector<int> result(n);

        while (left <= right) {
            int n1 = nums[left] * nums[left];
            int n2 = nums[right] * nums[right];

            if (n1 > n2) {
                result[idx] = n1;
                left++;
            } else {
                result[idx] = n2;
                right--;
            }
            idx--;
        }
        
        return result;
    }
};
