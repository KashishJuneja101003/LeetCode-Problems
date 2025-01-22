class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if(root == nullptr) return newNode;
        TreeNode* temp = root;

        while(temp != nullptr){
            if(val < temp->val){
                if(temp->left != nullptr){
                    temp = temp->left;
                } else{
                    temp->left = newNode;
                    break;
                }
            } else{
                if(temp->right != nullptr){
                    temp = temp->right;
                } else{
                    temp->right = newNode;
                    break;
                }
            }
        }

        return root;
    }
};
