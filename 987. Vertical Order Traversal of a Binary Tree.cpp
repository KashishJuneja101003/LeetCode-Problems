// TC: O(n log n) SC: O(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        map<int, map<int, multiset<int>>> mp;

        int level = 0;
        while(!q.empty()){
            int size = q.size();

            level++;
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* curr = p.first;
                int dist = p.second;

                mp[dist][level].insert(curr->val);

                if(curr->left) q.push({curr->left, dist-1});
                if(curr->right) q.push({curr->right, dist+1});
            }

        } 

        vector<vector<int>> order;
        for(auto& it:mp){
            auto sec = it.second;
            vector<int> temp;
            for(auto& it2:sec){
                auto st = it2.second;
                for(int i:st){
                    temp.push_back(i);
                }
            }
            order.push_back({temp});
        }

        return order;
    }
};
