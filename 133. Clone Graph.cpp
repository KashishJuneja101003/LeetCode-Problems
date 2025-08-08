/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        Node* head = new Node(node->val);
        unordered_map<Node*, Node*> cloneMap;
        cloneMap[node] = head;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            for(Node* nbr : curr->neighbors){
                if(cloneMap.find(nbr) == cloneMap.end()){
                    cloneMap[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }

                cloneMap[curr]->neighbors.push_back(cloneMap[nbr]);
            }
        }

        return head;
    }
};
