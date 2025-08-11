// Two Pass: TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* temp = head;

        while (temp) {
            N++;
            temp = temp->next;
        }

        int k = N - n;

        if (k == 0) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = head;
        for (int i = 1; i < k; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
        delete temp;

        return head;
    }
};

// One Pass: TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* fast = head;

        for(int i=0; i<n; i++) fast = fast->next;

        if(!fast) return head->next;

        ListNode* slow = head;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};
