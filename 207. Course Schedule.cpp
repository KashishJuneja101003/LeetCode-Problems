class Solution {
public:
    void topoBFS(unordered_map<int, vector<int>> &adj, vector<int>& inDegree, queue<int> &que, vector<int>& topoOrder){
        while(!que.empty()){
            int front = que.front();
            que.pop();

            topoOrder.push_back(front);

            for(int v : adj[front]){
                inDegree[v]--;

                if(inDegree[v] == 0) que.push(v);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);

        for(int i=0; i<prereq.size(); i++){
            int u=prereq[i][1];
            int v=prereq[i][0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0) que.push(i);
        }

        vector<int>topoOrder;

        topoBFS(adj, inDegree, que, topoOrder);

        return topoOrder.size() == numCourses;

        
    }
};
