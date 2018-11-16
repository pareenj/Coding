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
    
    if(A == NULL){
        return A;
    }

    /* create a dummy node that acts like a fake head of list pointing to the original head*/
    ListNode* dummy = new ListNode(-1);
    dummy->next = A;

    ListNode *prev = dummy, *current = A;

    while(current != NULL)
    {
    	/* Until the current and previous values are same, keep updating current */
    	while((current->next != NULL) && (prev->next->val == current->next->val))
    		current = current->next;

    	/* if current has unique value i.e current is not updated, 
    	Move the prev pointer to next node*/
    	if(prev->next == current) prev = prev->next;

    	/* when current is updated to the last duplicate value of that segment, 
    	make prev the next of current*/
    	else prev->next = current->next;

    	current = current->next;
    }

    return dummy->next;
}

// http://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/
// http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/