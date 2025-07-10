class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        string s = "";
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr) {s += "n "; continue;}
            
            s += to_string(curr->val) + ' ';
            q.push(curr->left);
            q.push(curr->right);
        }
        return s;       
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = new TreeNode(-1001);
        queue<TreeNode*> q;
        q.push(root);

        string num = "";
        bool left = true;
        for(char& c:data){
            TreeNode* curr = q.front();

            if(c == 'n') {
                if(left) {curr->left = nullptr; left = false;}
                else {curr->right = nullptr; left = true; q.pop();}
            } else if(c != ' ') {
                num += c;
            } else{
                if(num == "") continue;

                int val = stoi(num);
                num = "";

                if(root->val == -1001){
                    root->val = val;
                    continue;
                }

                TreeNode* newNode = new TreeNode(val);
                q.push(newNode);

                if(left){
                    curr->left = newNode;
                    left = false;
                } else{
                    curr->right = newNode;
                    left = true;
                    q.pop();
                }

            }
        }

        if(root->val == -1001) return nullptr;
        return root;
    }
};
