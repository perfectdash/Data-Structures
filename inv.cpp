#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=1e4+1;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1],p1;

void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p=p1)
{
    if(N==R)    return 1;
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}


int getInvCount(int arr[],int n)
{
    
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; 
  
    multiset<int>::iterator itset1;
  
    for (int i=1; i<n; i++)
    {
        
        set1.insert(arr[i]);
  
        
        itset1 = set1.upper_bound(arr[i]);
  
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}


struct Node
{
    int key, height;
    struct Node *left, *right;
  
// size of the tree rooted with this Node
    int size; 
};
  
// A utility function to get the height of
// the tree rooted with N
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
  
// A utility function to size of the
// tree of rooted with N
int size(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->size;
}
  
/* Helper function that allocates a new Node with
the given key and NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key   = key;
    node->left   = node->right  = NULL;
    node->height = node->size = 1;
    return(node);
}
  
// A utility function to right rotate 
// subtree rooted with y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
  
    // Perform rotation
    x->right = y;
    y->left = T2;
  
    // Update heights
    y->height = max(height(y->left),
 height(y->right))+1;
    x->height = max(height(x->left),
 height(x->right))+1;
  
    // Update sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
  
    // Return new root
    return x;
}
  
// A utility function to left rotate 
// subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
  
    // Perform rotation
    y->left = x;
    x->right = T2;
  
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
  
    // Update sizes
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
  
    // Return new root
    return y;
}
  
// Get Balance factor of Node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
  
// Inserts a new key to the tree rotted with Node. Also, updates
// *result (inversion count)
struct Node* insert(struct Node* node, int key, int *result)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
  
    if (key < node->key)
    {
        node->left  = insert(node->left, key, result);
  
        // UPDATE COUNT OF GREATE ELEMENTS FOR KEY
        *result = *result + size(node->right) + 1;
    }
    else
        node->right = insert(node->right, key, result);
  
    /* 2. Update height and size of this ancestor node */
    node->height = max(height(node->left),
                       height(node->right)) + 1;
    node->size = size(node->left) + size(node->right) + 1;
  
    /* 3. Get the balance factor of this ancestor node to
          check whether this node became unbalanced */
    int balance = getBalance(node);
  
    // If this node becomes unbalanced, then there are
    // 4 cases
  
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
  
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
  
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
  
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
  
    /* return the (unchanged) node pointer */
    return node;
}
  
// The following function returns inversion count in arr[]
int getInvCount(int arr[], int n)
{
  struct Node *root = NULL;  // Create empty AVL Tree
  
  int result = 0;   // Initialize result
  
  // Starting from first element, insert all elements one by
  // one in an AVL tree.
  for (int i=0; i<n; i++)
  
     // Note that address of result is passed as insert
     // operation updates result by adding count of elements
     // greater than arr[i] on left of arr[i]
     root = insert(root, arr[i], &result);
  
  return result;
}
  

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << "Number of inversions count are : "
         << getInvCount(arr,n);
    return 0;
}



int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
 
// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;
 
        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
 
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

