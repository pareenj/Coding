/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL) return A;

    ListNode *current = A;

    /* Traverse further only if there are at-least two nodes left */
    while((current != NULL) && (current->next != NULL))
    {
    	/* Swap data of node with its next node's data */
    	swap(&(current->val), &(current->next->val));

    	/* Move temp by 2 for the next pair */
    	current = current->next->next;
    }
}


ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if((A != NULL) && (A->next != NULL))
    {
    	/* Swap the node's data with data of next node */
    	swap(&(A->val), &(A->next->val));

    	/* Call pairWiseSwap() for rest of the list */
      	swapPairs(A->next->next);
    }
}

// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/