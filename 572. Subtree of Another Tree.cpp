// Approach 1: Recursive TC: O(n * m) SC: O(n + m) (due to recursion stack)
class Solution {
public:
    bool isSame(TreeNode* r, TreeNode* s){
        if(!r && !s) return true;
        if(!r || !s) return false;
        if(r->val != s->val) return false;

        return isSame(r->left, s->left) && isSame(r->right, s->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
