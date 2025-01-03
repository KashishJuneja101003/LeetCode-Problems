/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool isCycle = false;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){   // Cycle Detected
                isCycle = true; break;
            }
        }

        if(!isCycle) {
            return nullptr;
        } else{
            slow = head;
        }
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};
