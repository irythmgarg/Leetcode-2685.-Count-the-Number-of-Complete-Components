// C++ solution to count the number of complete components in an undirected graph
class Solution {
public:

    // Depth First Search (DFS) helper function
    // i: current node
    // mp: adjacency list
    // visited: keeps track of visited nodes
    // node: reference to count number of nodes in the component
    // edge: reference to count number of edges in the component
    void dfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited, int &node, int &edge)
    {
        node++;  // Increment node count for current component
        edge += mp[i].size();  // Add number of edges connected to current node
        visited[i] = true;  // Mark node as visited

        // Traverse all adjacent nodes
        for(int a : mp[i])
        {
            if(!visited[a])
            {
                dfs(a, mp, visited, node, edge);  // Recursive DFS call
            }
        }
    }

    // Main function to count complete components
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);  // Track visited nodes
        int count = 0;  // Store number of complete components
        unordered_map<int, vector<int>> mp;  // Adjacency list

        // Build the adjacency list
        for(auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);
            mp[to].push_back(from);
        }

        // Traverse all nodes to find components
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                int node = 0;
                int edge = 0;
                dfs(i, mp, visited, node, edge);  // DFS to get node and edge count

                // Each edge is counted twice, so total edge count should be node*(node-1)
                if(node * (node - 1) == edge)
                    count++;  // Increment if it's a complete component
            }
        }

        return count;  // Return the total number of complete components
    }
};
