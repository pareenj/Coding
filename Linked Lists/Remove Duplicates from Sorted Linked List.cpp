/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL) return A;

    /* Pointer to traverse the linked list */
    ListNode *current = A;

    /* Pointer to store the next pointer of a node to be deleted*/
    ListNode *next_next;

    while(current->next != NULL)
    {
    	if(current->val == current->next->val) 
    	{
    		next_next = current->next->next;
    		delete current->next;
    		current->next = next_next;
    	}
    	else current = current->next; // Advance only if no deletion
    }
    return A;    
}

// http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/