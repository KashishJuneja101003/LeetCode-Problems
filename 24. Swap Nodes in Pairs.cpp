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

        head->next = tailNext;
        head = prev;
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        // Check if group exists
        ListNode* temp = head, *prev;

        for(int i=0; i<2; i++){
            // If group doesn't exists, return the head pointer
            if(temp == nullptr){
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        
        // Recursive call if group exists
        prev->next = swapPairs(temp);
        return reverse(head, prev);
    }
};
