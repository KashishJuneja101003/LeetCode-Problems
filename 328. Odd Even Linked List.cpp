/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* evenHead = head->next, *temp = evenHead->next;

        ListNode* odd = head, *even = head->next;
        while(temp != nullptr){
            odd->next = temp;
            odd = temp;

            temp = temp->next;
            
            even->next = temp;
            even = temp;
            
            if(temp != nullptr){
                temp = temp->next;
            }
        }

        odd->next = evenHead;

        return head;
    }
};
