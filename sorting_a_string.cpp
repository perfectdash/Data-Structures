#include <bits/stdc++.h>
using namespace std;


/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N + M)

    Where 'N' is the number of Nodes and 'M' is the number of pairs.
*/
void dfs(int cur, vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans)
{
    // Iterating in all the child of the node 'cur'.
    for (auto child : graph[cur])
    {
        if (visited[child] == 0)
        {
            visited[child] = 1;
            ans.push_back(child);
            dfs(child, graph, visited, ans);
        }
    }
}
string stringSorting(string str, vector<vector<int>>& pairs)
{
    int n = str.size();
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    // Filling the adjacency list for the graph.
    for (auto i : pairs)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    // Iterating in all the nodes and finding the connected component for it.
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> ans;
            visited[i] = 1;
            ans.push_back(i);
            dfs(i, graph, visited, ans);

            // Sorting all the nodes that are present in the connected component.
            sort(ans.begin(), ans.end());
            vector<char> chars;

            // Storing the character corresponding to each node of the connected component.
            for (auto j : ans)
            {
                chars.push_back(str[j - 1]);
            }
            sort(chars.begin(), chars.end());

            // Updating the string.
            for (int j = 0; j < ans.size(); j++)
            {
                str[ans[j] - 1] = chars[j];
            }
        }
    }

    return str;
}