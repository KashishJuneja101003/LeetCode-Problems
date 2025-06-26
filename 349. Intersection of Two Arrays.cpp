// Approach 1: Sorting TC: O(nlogn) SC: O(k) k - common unique elements
/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_set<int> st;
        int i=0;
        int j=0;

        int m=nums1.size();
        int n=nums2.size();

        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                st.insert(nums1[i]);
                i++; j++;
            } else if (nums1[i] < nums2[j]){
                i++;
            } else{
                j++;
            }
        }

        vector<int> result;
        for(auto& num : st){
            result.push_back(num);
        }

        return result;
    }
};
*/

// Approach 2: HashSet TC: O(m+n) SC: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int i:nums1) st.insert(i);

        vector<int> result;
        for(int i:nums2){
            if(st.find(i) != st.end()){
                result.push_back(i);
                st.erase(i);
            }
        }

        return result;
    }
};
