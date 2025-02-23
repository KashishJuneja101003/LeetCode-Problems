class Solution {
public:
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr){
            return true;
        }

        if(root == nullptr || subRoot == nullptr){
            return false;
        }

        if(root->val == subRoot->val){
            return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
        }

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }

        if(root->val == subRoot->val){
            if(isIdentical(root, subRoot)){
                return true;
            }
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
