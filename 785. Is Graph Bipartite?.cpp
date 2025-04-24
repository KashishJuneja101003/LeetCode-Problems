// There are 2 colors: 0 & 1
class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int currNode, vector<int>& color, int currColor){
        color[currNode] = currColor;

        for(int &newCurrNode : graph[currNode]){
            if(color[currNode] == color[newCurrNode]) return false;

            if(color[newCurrNode] == -1) {
                int newCurrColor = 1 - currColor; // Toggle between 0 & 1
                if(!checkBipartiteDFS(graph, newCurrNode, color, newCurrColor)) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(!checkBipartiteDFS(graph, i, color, 0)) return false;
            }
        }

        return true;

    }
};
