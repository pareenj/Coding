/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 'compare' function used to build up the
// priority queue
struct compare
{
	bool operator()(struct ListNode* a, struct ListNode* b)
	{
		return a->val > b->val;
	}
};

// function to merge k sorted linked lists
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int k = A.size();

    ListNode* head = NULL;
    ListNode* last;

    // priority_queue 'pq' implemeted as min heap with the help of 'compare' function
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // push the head nodes of all the k lists in 'pq'
    for(int i = 0; i < k; i++) pq.push(A[i]);

    // loop till 'pq' is not empty
    while(!pq.empty())
    {
    	// get the top element of 'pq'
    	ListNode* top = pq.top();
    	pq.pop();

    	// check if there is a node next to the 'top' node
        // in the list of which 'top' node is a member
    	if(top->next != NULL) 
    	{
    		// push the next node in 'pq'
    		pq.push(top->next);
    	}	

    	// if final merged list is empty
    	if(head == NULL) 
    	{
    		head = top;
    		// points to the last node so far of
            // the final merged list
    		last = top;
    	}
    	else
    	{
    		// insert 'top' at the end of the merged list so far
    		last->next = top;
    		// update the 'last' pointer
    		last = top;
    	}
    }

    // head node of the required merged list
    return head;
}

// http://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/


// http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
// http://www.geeksforgeeks.org/merge-two-sorted-lists-place/
// http://www.geeksforgeeks.org/merge-k-sorted-arrays/


// http://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* mergeTwoLists(ListNode* a, ListNode* b)
{
	ListNode* result = NULL;

	// Base Cases
	if(a == NULL) return b;
	else if(b == NULL) return a;

	// Pick either a or b, and recur
	if(a->val <= b->val)
	{
		result = a;
		result->next = mergeTwoLists(a->next, b);
	}
	else
	{
		result = b;
		result->next = mergeTwoLists(a, b->next);
	}

	return result;
}

// function to merge k sorted linked lists
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int k = A.size();
    int last = k;

    // Repeat until only one list is left
    while(last != 0)
    {
    	int i = 0, j = last;

    	// (i, j) forms a pair
    	while(i < j)
    	{
    		A[i] = mergeTwoLists(A[i], A[j]);

    		// Consider next pair
    		i++; j--;

    		// If all pairs are merged, update last
    		if(i >= j) last = j;
    	}
    }
    return A[0];
}