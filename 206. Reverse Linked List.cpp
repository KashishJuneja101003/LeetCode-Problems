// Approach 1: Iterative TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Approach 2: Recursive TC: O(n) SC: O(n)
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* reverseHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reverseHead;
    }
};
*/
