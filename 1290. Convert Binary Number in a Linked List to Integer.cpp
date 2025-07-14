// Approach 1: Reverse TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int getDecimalValue(ListNode* head) {
        int i=0;
        int dec=0;
        ListNode* temp = reverse(head);

        while(temp){
            if(temp->val == 1) dec += pow(2, i);
            i++;
            temp = temp->next;
        }

        return dec;
    }
};

// Approach 2: Math TC: O(n) SC: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int dec=0;
        ListNode* temp = head;

        while(temp){
            dec = dec*2 + temp->val;
            temp = temp->next;
        }

        return dec;
    }
};

// Approach 3: Bit Manipulation TC: O(n) SC: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int dec=0;
        ListNode* temp = head;

        while(temp){
            dec = (dec<<1) + temp->val;
            temp = temp->next;
        }

        return dec;
    }
};
