#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(32 * (N + M))
    Space Complexity: O(32 * N)

    where 'N', and 'M' are the size of the given array.
*/



#define INT_SIZE 32


struct TrieNode
{
    int value ;
    TrieNode * Child[2];
};

TrieNode * getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->value =0;
    newNode -> Child[0] = newNode -> Child[1] = NULL;
    return newNode;
}

// Utility function insert new key in trie.
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;

    // Start from the most significant bit, and insert all bit of key one-by-one into trie.
    for (int i = 32; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1 << i));

        // Add a new Node into trie
        if (temp->Child[current_bit] == NULL)
        {
            temp->Child[current_bit] = getNode();
        }

        temp = temp->Child[current_bit];
    }

    // Store value of key at leafNode
    temp->value = key ;
}

// Utility function to find maximum XOR value of an integer inserted in Trie and given key.
int  findMax(TrieNode * root, int key)
{
    TrieNode * temp = root;

    for (int i = 32; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = ( key & ( 1 << i) );

        // Traversal Trie, look for prefix that has opposite bit.
        if (temp->Child[1 - current_bit] != NULL)
        {
            temp = temp->Child[1 - current_bit];
        }

        // If there is no opposite bit then look for the same bit.
        else if (temp->Child[current_bit] != NULL){
            temp = temp->Child[current_bit];
        }
    }

    // Return Xor with value at leaf node.
    return key ^ temp->value;
}

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Initialize result.
    int maxVal = 0;  

    // Create a Trie and inssert all elements of first array into trie.
    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
    {
        insert(root, arr1[i]);
    }

    // For each element in second array find max XOR value from trie.
    for (int i = 0 ; i < m; i++)
    {
        // Find maximum XOR value of current element with elements inserted in Trie.
        maxVal = max(maxVal, findMax(root, arr2[i]));
    }

    return maxVal;
}