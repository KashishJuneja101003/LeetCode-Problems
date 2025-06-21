// Approach 1: Brute Force TC: O(n) SC: O(n)
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        unordered_set<ListNode*> visited;
        
        ListNode* temp = head;

        while(temp != nullptr){
            if(visited.find(temp) != visited.end()){
                return true;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
*/

// Approach 2: Floyd's Cycle Detection TC: O(n) SC: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};
