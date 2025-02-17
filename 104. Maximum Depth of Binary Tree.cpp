class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int leftChild = maxDepth(root->left);
        int rightChild = maxDepth(root->right);

        return 1 + max(leftChild, rightChild); 
    }
};
