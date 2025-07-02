// Approach 1: Brute Force TC: O(n^2) SC: O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]) return true;
            }
        }

        return false;
    }
};

// Approach 2: Hashmap TC: O(n) SC: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        unordered_map<int, int> el_freq;

        for(int i=0; i<n; i++){
            el_freq[nums[i]]++;
            if(el_freq[nums[i]] > 1){
                return true;
            }
        }

        return false;
    }
};

// Approach 3: Hashset TC: O(n) SC: O(n) (Cleaner and efficient)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        unordered_set<int> el;

        for(int i=0; i<n; i++){
            int e = nums[i];
            if(el.find(e) != el.end()){
                return true;
            }
            el.insert(e);
        }

        return false;
    }
};

// Approach 4: Sorting TC: O(nlogn) SC:O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]) return true;
        }

        return false;
    }
};
