int INT_SIZE = 32;

// A Trie Node
struct TrieNode
{
    int value; // used in leaf node
    TrieNode * Child[2];
};
 
// Utility function to create a new Trie node
TrieNode * getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->value = 0;
    newNode->Child[0] = newNode->Child[1] = NULL;
    return newNode;
}
 
// utility function insert new key in trie
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;
 
    // start from the most significant bit , insert all
    // bit of key one-by-one into trie
    for (int i = INT_SIZE-1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1<<i));
 
        // Add a new Node into trie
        if (temp->Child[current_bit] == NULL)
            temp->Child[current_bit] = getNode();
 
        temp = temp->Child[current_bit];
    }
 
    // store value at leafNode
    temp->value = key ;
}
 
// Returns minimum XOR value of an integer inserted
// in Trie and given key.
int  minXORUtil(TrieNode * root, int key)
{
    TrieNode * temp = root;
 
    for (int i=INT_SIZE-1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = ( key & ( 1<<i) );
 
        // Traversal Trie, look for prefix that has
        // same bit
        if (temp->Child[current_bit] != NULL)
            temp = temp->Child[current_bit];
 
        // if there is no same bit.then looking for
        // opposite bit
        else if(temp->Child[1-current_bit] !=NULL)
            temp = temp->Child[1-current_bit];
    }
 
    // return xor value of minimum bit difference value
    // so we get minimum xor value
    return key ^ temp->value;
}

// Returns minimum xor value of pair in arr[0..n-1]
int Solution::findMinXor(vector<int> &A) {
    
    
    int min_xor = INT_MAX;  // Initialize result
    int n = A.size();
 
    // create a True and insert first element in it
    TrieNode *root = getNode();
    insert(root, A[0]);
 
    // Traversr all array elementd and find minimum xor
    // for every element
    for (int i = 1 ; i < n; i++)
    {
        // Find minimum XOR value of current element with
        // previous elements inserted in Trie
        min_xor = min(min_xor, minXORUtil(root, A[i]));
 
        // insert current array value into Trie
        insert(root, A[i]);
    }
    return min_xor;
}

// http://www.geeksforgeeks.org/minimum-xor-value-pair/


-----------------------------------------------------------------------------------------------------------------------------


int Solution::findMinXor(vector<int> &A) {
    
    int min_xor = INT_MAX;
    int n = A.size();
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n - 1; i++)
    {
        min_xor = min(min_xor, (A[i]^A[i+1]));
    }
    
    return min_xor;
}
