class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* evenHead = evenPtr;

        while(oddPtr->next != nullptr && evenPtr->next != nullptr){
            oddPtr->next = oddPtr->next->next;
            oddPtr = oddPtr->next;
            evenPtr->next = evenPtr->next->next;
            evenPtr = evenPtr->next;
        }

        oddPtr->next = evenHead;
        
        return head;
    }
};
