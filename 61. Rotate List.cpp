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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int noNodes = 0;
        ListNode*tail;
        ListNode* temp = head;
        while(temp != nullptr){
            noNodes++;
            tail=temp;
            temp = temp->next;
        }

        int rotate = k%noNodes;
        if(rotate == 0){
            return head;
        }

        temp = head;
        ListNode*prev;
        for(int i=0; i<noNodes-rotate; i++){
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        tail->next = head;
        head = temp;

        return head;
    }
};
