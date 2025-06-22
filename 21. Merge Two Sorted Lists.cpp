// Approach 1: Iterative TC: O(n+m) SC: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* temp = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr)
            temp->next = list1;
        if (list2 != nullptr)
            temp->next = list2;

        return head;
    }
};

// Approach 2: Recursive TC: O(n+m) SC: O(n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        } else if(list2 == nullptr){
            return list1;
        }
        
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
