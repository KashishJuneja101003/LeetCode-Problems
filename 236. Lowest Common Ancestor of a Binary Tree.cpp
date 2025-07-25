// TC: O(n) SC: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p || root == q) return root;

        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        if(leftN && rightN) return root;
        if(leftN) return leftN;
        return rightN;
    }
};
