class Solution {
public:
    vector<int> arr;

    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int randIdx = rand() % arr.size();
        return arr[randIdx];
    }
};
