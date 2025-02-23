class Solution {
public:
    int height(TreeNode* root){
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // If any subtree is unbalanced, return -1 as an indicator
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
