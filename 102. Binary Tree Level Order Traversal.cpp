// Approach 1: TC: O(n) SC: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            ans.push_back(level);
        }

        return ans;
    }
};

// Approach 2: TC: O(n) SC: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> order;
        vector<int> temp;

        q.push(root);
        q.push(nullptr);
        while(q.size() > 1){
            TreeNode* curr = q.front(); q.pop();
            temp.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            if(q.front() == nullptr) {
                q.push(nullptr);
                q.pop();
                order.push_back(temp);
                temp = {};
                continue;
            }            
        }

        return order;
    }
};
