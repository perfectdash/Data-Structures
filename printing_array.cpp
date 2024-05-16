#include <bits/stdc++.h>
using namespace std;



/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)

    Where N is the number of subsequences and M is average size of a subsequence
*/

#include <map>
#include<unordered_set>
#include<algorithm>

// Function to get the topological sort of the graph
void topologicalSort(int node, map<int, vector<int>> &graph, 
                unordered_set<int> &visited, vector<int> &nodes)
{
    // Add current node to visited node set
    visited.insert(node);

    // Iterate over all the children of the visited nodes
    for(int i = 0; i < graph[node].size(); i++)
    {   
        int children = graph[node][i];

        if(visited.find(children) == visited.end())
            topologicalSort(children, graph, visited, nodes);
    }

    // Insert the proccessed node in the node list
    nodes.push_back(node);
}


vector<int> makeArray(int n, vector<vector<int>> &subsequences)
{
    map<int, vector<int>> graph;

    // Iterate over all subsequences
    for(int i = 0; i < subsequences.size(); i++)
    {
        vector<int> subseq = subsequences[i];

        for(int j = 1; j < subseq.size(); j++)
        {
            // Make an edge from j - th to jth node
            graph[subseq[j - 1]].push_back(subseq[j]);
        }
    }

    vector<int> nodes;
    unordered_set<int> visited;
    map<int, vector<int>>::iterator it;

    // Get the topological sort of the graph
	for(it = graph.begin(); it != graph.end(); it++)
    {
        int node = it->first; 

        if(visited.find(node) == visited.end())
        topologicalSort(node, graph, visited, nodes);

    }
        

    // Reverse and return the list of nodes
    reverse(nodes.begin(), nodes.end());
    return nodes;
}