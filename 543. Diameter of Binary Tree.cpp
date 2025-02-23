class Solution {
public:
    class TreeInfo{
        public:
            int height, diameter;
            TreeInfo(int height, int diameter){
                this->height = height;
                this->diameter = diameter;
            }
    };

    TreeInfo* diameterTree(TreeNode* root){
        if(root == nullptr){
            return new TreeInfo(0, 0);
        }

        TreeInfo* leftSubtree = diameterTree(root->left);
        TreeInfo* rightSubtree = diameterTree(root->right);

        int height = 1 + max(leftSubtree->height, rightSubtree->height);

        int diameterLeft = leftSubtree->diameter;
        int diameterRight = rightSubtree->diameter;
        int diameterRoot = leftSubtree->height + rightSubtree->height;

        int diameter = max(diameterRoot, max(diameterLeft, diameterRight));

        return new TreeInfo(height, diameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterTree(root)->diameter;
    }
};
