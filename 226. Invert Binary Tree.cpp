// Time Complexity: O(n) Space Complexity: O(h) → O(log n) for balanced, O(n) for skewed
class Solution {
public:
    void mirror(TreeNode* root){
        if(!root) return;
        
        swap(root->left, root->right);

        mirror(root->left);
        mirror(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};
