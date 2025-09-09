// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int left = INT_MAX;
        int right = INT_MAX;

        if(root->left) left = minDepth(root->left);
        if(root->right) right = minDepth(root->right);

        return 1 + min(left, right);
    }
};

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();

                if(!curr->left && !curr->right) return depth;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            depth++;
        }

        return depth;
    }
};
