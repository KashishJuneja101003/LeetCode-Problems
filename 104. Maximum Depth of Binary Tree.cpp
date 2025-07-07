// Approach 1: Recursion (DFS) TC: O(n) SC: O(h) (can be log n to n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

// Approach 2: Iterative (BFS) TC: O(n) SC: O(h)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int countLevels = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int currNodes = q.size();
            
            while(currNodes > 0){
                TreeNode* front = q.front();
                q.pop();

                if(front->left != nullptr) q.push(front->left);
                if(front->right != nullptr) q.push(front->right);

                currNodes--;
            }

            countLevels++;
        }


        return countLevels;
    }
};
