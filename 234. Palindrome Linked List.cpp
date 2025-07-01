// Approach 1: TC: O(n) SC: O(n)
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> revnum;
        ListNode* temp = head;

        while(temp != nullptr){
            revnum.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        for(int i=revnum.size()-1; i>=0; i--){
            if(revnum[i] != temp->val) return false;
            temp = temp->next;
        }

        return true;
    }
};
*/

// Approach 2: TC: O(n) SC: O(1)
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        // Find middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse nodes after middle
        ListNode* revHead = reverse(slow);

        // Check if the list is palindrome
        ListNode* first = head;
        ListNode* second = revHead;
        while(second != nullptr){
            if(second->val != first->val) return false;
            second = second->next;
            first = first->next;
        }
        return true;
    }
};
