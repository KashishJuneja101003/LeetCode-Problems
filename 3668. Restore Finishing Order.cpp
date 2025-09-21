class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st;
        for(int& i:friends) st.insert(i);

        vector<int> ans;
        for(int& i:order){
            if(st.find(i) != st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
