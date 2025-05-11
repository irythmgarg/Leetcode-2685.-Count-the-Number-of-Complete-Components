// C++ solution to count the number of complete components in an undirected graph using BFS
class Solution {
public:

    // Breadth First Search (BFS) helper function
    // i: starting node of the component
    // mp: adjacency list representing the graph
    // visited: marks which nodes have been visited
    // node: reference to count number of nodes in the component
    // edge: reference to count number of edges in the component
    void bfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited, int &node, int &edge)
    {
        queue<int> q;  // Queue for BFS traversal
        q.push(i);
        visited[i] = true;  // Mark starting node as visited

        // Traverse the component using BFS
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            node += 1;  // Increment node count
            edge += mp[top].size();  // Count the number of connections from this node

            // Visit all adjacent nodes
            for(int a : mp[top])
            {
                if(!visited[a])
                {
                    visited[a] = true;
                    q.push(a);  // Add unvisited neighbor to queue
                }
            }
        }
    }

    // Main function to count complete components in the graph
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);  // Track visited nodes
        int count = 0;  // Count of complete components
        unordered_map<int, vector<int>> mp;  // Adjacency list

        // Build the undirected graph
        for(auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);
            mp[to].push_back(from);
        }

        // Traverse all nodes to find connected components
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                int node = 0;
                int edge = 0;
                bfs(i, mp, visited, node, edge);  // Get node and edge count for this component

                // In a complete graph of k nodes, there are k*(k-1)/2 edges
                // Since edges are counted twice (once for each node), check if edge count equals k*(k-1)
                if(node * (node - 1) == edge)
                    count++;  // Component is complete
            }
        }

        return count;  // Return total number of complete components
    }
};
