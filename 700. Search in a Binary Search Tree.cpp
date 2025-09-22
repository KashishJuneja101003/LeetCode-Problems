// Iterative TC: O(h) SC: O(h)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(val == root->val) return root;
        else if(val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};

// Iterative TC: O(h) SC: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;

        while(node){
            if(node->val == val) return node;
            else if (node->val < val) node = node->right;
            else node = node->left;
        }

        return node;
    }
};
