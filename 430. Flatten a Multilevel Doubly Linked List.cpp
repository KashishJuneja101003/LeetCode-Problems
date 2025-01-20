/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }

        Node* curr = head;
        while(curr != nullptr){
            // If child exists, call flatten with curr->child
            if(curr->child != nullptr){
                Node* nextNode = curr->next;    // Stores the next node of curr
                curr->next = flatten(curr->child);  // curr->next will point to its child
                curr->next->prev = curr; // Makes the child node to point towards curr (prev pointer)
                curr->child = nullptr;  // Make the child ptr null

                while(curr->next != nullptr){
                    curr = curr->next;
                }

                if(nextNode != nullptr){
                    curr->next = nextNode;
                    nextNode->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
