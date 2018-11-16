// Horizontal Distance Based Method

/*
// min --> Minimum horizontal distance from root
// max --> Maximum horizontal distance from root
// hd  --> Horizontal distance of current node from root 
findMinMax(tree, min, max, hd)
     if tree is NULL then return;
 
     if hd is less than min then
           min = hd;
     else if hd is greater than max then
          *max = hd;
 
     findMinMax(tree->left, min, max, hd-1);
     findMinMax(tree->right, min, max, hd+1);

printVerticalLine(tree, line_no, hd)
     if tree is NULL then return;
 
     if hd is equal to line_no, then
           print(tree->data);
     printVerticalLine(tree->left, line_no, hd-1);
     printVerticalLine(tree->right, line_no, hd+1); 
*/ 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// A utility function to find min and max distances with respect to root
void findMinMax(TreeNode* node, int* min, int* max, int hd)
{
	// Base case
	if(node == NULL) return;

	// Update min and max
	if(hd < *min) *min = hd;
	else if(hd > *max) *max = hd;

	// Recur for left and right subtrees
	findMinMax(node->left, min, max, hd-1);
	findMinMax(node->right, min, max, hd+1);
}

void pushVerticalLine(TreeNode* node, int lineNumber, int hd, vector<int> &a)
{
	// Base case
	if(node == NULL) return;

	// If this node is on the given line number
	if(hd == lineNumber)
		a.push_back(node->val);

	// Recur for left and right subtrees
	pushVerticalLine(node->left, lineNumber, hd-1, a);
	pushVerticalLine(node->right, lineNumber, hd+1, a);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {

	vector<vector<int> > ans;
	if(A == NULL) return ans;

	// Find min and max distances with respect to root
	int min = 0, max = 0;
	findMinMax(A, &min, &max, 0);

	// Iterate through all possible vertical lines starting from the leftmost line and push all the nodes line by line
	for(int lineNumber = min; lineNumber <= max; lineNumber++)
	{
		vector<int> currRow;
		pushVerticalLine(A, lineNumber, 0, currRow);
		// sort(currRow.begin(), currRow.end());
		ans.push_back(currRow);
	}

	return ans;
}

// http://www.geeksforgeeks.org/print-binary-tree-vertical-order/


// Hashmap Based Method

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
}

// http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/


// Level Order Traversal Based Method

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
}

// http://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/