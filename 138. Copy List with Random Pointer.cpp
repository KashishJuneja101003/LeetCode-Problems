/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }

        unordered_map<Node*, Node*> myMap;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        myMap[head] = newHead;

        while(oldTemp != nullptr){
            Node* copyNode = new Node(oldTemp->val);
            myMap[oldTemp] = copyNode; // Adding pointers
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head; newTemp = newHead;
        while(oldTemp != nullptr){
            newTemp->random = myMap[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
