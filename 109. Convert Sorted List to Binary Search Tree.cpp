class Solution {
public:
    TreeNode* sllToTree(ListNode* listHead){
        if(listHead == nullptr){
            return nullptr;
        } 
        
        if(listHead->next == nullptr){
            return new TreeNode(listHead->val);
        }

        ListNode* prevSlow = nullptr;
        ListNode* slow = listHead;
        ListNode* fast = listHead;

        while(fast != nullptr && fast->next != nullptr){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* treeRoot = new TreeNode(slow->val);

        prevSlow->next = nullptr;
        treeRoot->left = sllToTree(listHead);

        treeRoot->right = sllToTree(slow->next);

        return treeRoot;
    }
    TreeNode* sortedListToBST(ListNode* listHead) {
        return sllToTree(listHead);
    }
};
