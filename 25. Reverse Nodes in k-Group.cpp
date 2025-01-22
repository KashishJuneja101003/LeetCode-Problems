class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode*tail){
        ListNode* tailNext = tail->next;
        tail->next = nullptr;
        tail = head;

        ListNode* curr = head, *prev = nullptr, *next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Make the last node of the reverese list to point to the already reversed list (which comes after the current group)
        head->next = tailNext;
        head = prev;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }

        // Check if group exists
        ListNode* temp = head, *prev;

        for(int i=0; i<k; i++){
            // If group doesn't exists, return the head pointer
            if(temp == nullptr){
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        
        // Recursive call if group exists
        prev->next = reverseKGroup(temp, k);
        return reverse(head, prev);
        
    }
};
