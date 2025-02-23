class Solution {
public:
    int helper(TreeNode* root, TreeNode* parent, int sum){
        if(root == nullptr){
            return 0;
        }

        if(parent->left == root && root->left == nullptr && root->right == nullptr){
            sum += root->val;
            return sum;
        }

        return helper(root->left, root, sum) + helper(root->right, root, sum);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, root, 0);
    }
};
